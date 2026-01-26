#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define RING_BUFFER_SIZE 8   // must be > 0

typedef struct RingBuffer{
    uint8_t buffer[RING_BUFFER_SIZE];  // storage
    uint32_t head;   // next write index
    uint32_t tail;   // next read index
    uint32_t count;  // number of elements currently stored
} RingBuffer_t;

// Initialize the ring buffer
void RingBuffer_Init(RingBuffer_t *rb)
{
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

// Check if buffer is full
bool RingBuffer_IsFull(RingBuffer_t *rb)
{
    return rb->count == RING_BUFFER_SIZE;
}

// Check if buffer is empty
bool RingBuffer_IsEmpty(RingBuffer_t *rb)
{
    return rb->count == 0;
}

// Add element (returns false if full)
bool RingBuffer_Put(RingBuffer_t *rb, uint8_t data)
{
    if (RingBuffer_IsFull(rb))
        return false; // Buffer full

    rb->buffer[rb->head] = data;
    rb->head = (rb->head + 1) % RING_BUFFER_SIZE;
    rb->count++;
    return true;
}

// Get element (returns false if empty)
bool RingBuffer_Get(RingBuffer_t *rb, uint8_t *data)
{
    if (RingBuffer_IsEmpty(rb))
        return false; // Buffer empty

    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % RING_BUFFER_SIZE;
    rb->count--;
    return true;
}

// Get number of stored elements
uint32_t RingBuffer_Count(RingBuffer_t *rb)
{
    return rb->count;
}

int main(void)
{
    RingBuffer_t rb;
    RingBuffer_Init(&rb);

    // Push some data
    for (int i = 0; i < 10; i++) {
        if (RingBuffer_Put(&rb, i))
            printf("Put: %d\n", i);
        else
            printf("Buffer full, can't put %d\n", i);
    }

    // Pop some data
    uint8_t value;
    while (RingBuffer_Get(&rb, &value))
        printf("Got: %d\n", value);

    return 0;
}
