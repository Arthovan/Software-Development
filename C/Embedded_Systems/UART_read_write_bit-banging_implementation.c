#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>

#define BAUD_RATE 9600
#define BIT_PERIOD_US (1000000 / BAUD_RATE)

int wire_line = 1; // shared TX→RX wire (idle = high)
pthread_mutex_t wire_lock;

/* ---------------- GPIO SIMULATION ---------------- */
void gpio_set_tx(int value) {
    pthread_mutex_lock(&wire_lock);
    wire_line = value;
    pthread_mutex_unlock(&wire_lock);
}

int gpio_get_rx() {
    pthread_mutex_lock(&wire_lock);
    int v = wire_line;
    pthread_mutex_unlock(&wire_lock);
    return v;
}

void delay_us(int us) {
    usleep(us);
}

/* ---------------- UART BITBANG TX ---------------- */
void uart_write_byte(uint8_t data) {
    // Start bit
    gpio_set_tx(0);
    delay_us(BIT_PERIOD_US);

    // Data bits (LSB first)
    for (int i = 0; i < 8; i++) {
        int bit = (data >> i) & 1;
        gpio_set_tx(bit);
        delay_us(BIT_PERIOD_US);
    }

    // Stop bit
    gpio_set_tx(1);
    delay_us(BIT_PERIOD_US);
}

/* ---------------- UART BITBANG RX ---------------- */
uint8_t uart_read_byte() {
    uint8_t data = 0;

    // Wait for start bit (falling edge)
    while (gpio_get_rx() == 1)
        usleep(10);

    // Wait half bit period to sample mid-bit
    delay_us(BIT_PERIOD_US / 2);

    for (int i = 0; i < 8; i++) {
        delay_us(BIT_PERIOD_US);
        int bit = gpio_get_rx();
        data |= (bit << i);
    }

    // Wait for stop bit
    delay_us(BIT_PERIOD_US);

    return data;
}

/* ---------------- THREAD FUNCTIONS ---------------- */
void* tx_thread(void* arg) {
    const char *msg = "HELLO";
    for (int i = 0; msg[i]; i++) {
        uart_write_byte(msg[i]);
        printf("[TX] Sent: %c\n", msg[i]);
        usleep(20000); // gap between characters
    }
    return NULL;
}

void* rx_thread(void* arg) {
    for (int i = 0; i < 5; i++) {
        uint8_t c = uart_read_byte();
        printf("                 [RX] Received: %c\n", c);
    }
    return NULL;
}

/* ---------------- MAIN ---------------- */
int main() {
    pthread_t tx, rx;
    pthread_mutex_init(&wire_lock, NULL);

    printf("UART Bit-Banging Simulation (TX ↔ RX)\n");

    pthread_create(&rx, NULL, rx_thread, NULL);
    pthread_create(&tx, NULL, tx_thread, NULL);

    pthread_join(tx, NULL);
    pthread_join(rx, NULL);

    pthread_mutex_destroy(&wire_lock);
    return 0;
}
