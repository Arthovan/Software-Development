#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

// --- Simulated hardware timers ---
volatile uint32_t TIMER_LOW  = 0;  // 32-bit timer A (LSB)
volatile uint32_t TIMER_HIGH = 0;  // 32-bit timer B (MSB)

// --- Platform-specific stubs ---
static inline uint32_t timerA_read(void) {
    return TIMER_LOW;  // In real MCU: read from timer A counter register
}

static inline void timerB_increment(void) {
    TIMER_HIGH++;  // In real MCU: increment high timer or write to its counter
}

// --- ISR: Called when Timer A overflows ---
void TimerA_Overflow_IRQHandler(void)
{
    // Clear overflow flag (platform-specific)
    // e.g., __HAL_TIM_CLEAR_FLAG(&htimA, TIM_FLAG_UPDATE);

    // Increment high 32-bit timer
    timerB_increment();
}

// --- 64-bit read (atomic without disabling interrupts) ---
uint64_t timer64_read(void)
{
    uint32_t high1, low, high2;

    do {
        high1 = TIMER_HIGH;
        low   = timerA_read();
        high2 = TIMER_HIGH;
    } while (high1 != high2);

    return ((uint64_t)high1 << 32) | low;
}

// Basic Implementation
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t high = 0x12345678;  // higher 32 bits
    uint32_t low  = 0x9ABCDEF0;  // lower 32 bits

    // Combine into 64-bit value
    uint64_t value = ((uint64_t)high << 32) | low;

    // Print result
    printf("64-bit value = 0x%016llX\n", (unsigned long long)value);

    return 0;
}