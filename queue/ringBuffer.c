#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define RING_BUFFER_SIZE 16

typedef struct
{
    uint8_t buffer[RING_BUFFER_SIZE];
    uint32_t head;
    uint32_t tail;
}ring_buffer_t;

void ringBufferInit(ring_buffer_t* rb)
{
    memset(rb->buffer, 0, RING_BUFFER_SIZE);
    rb->head = 0;
    rb->tail = 0;
}

bool ringBufferIsEmpty(ring_buffer_t* rb)
{
    return (rb->head == rb->tail);     
}

bool ringBufferIsFull(ring_buffer_t* rb)
{
    return (rb->head == ((rb->tail + 1) % RING_BUFFER_SIZE));
}

int ringBufferReadByByte(ring_buffer_t *rb, uint8_t* byte)
{
    if(ringBufferIsEmpty(rb))
    {
        printf("No Data to Read, buffer is empty\n");
        return -1;
    }
    
    *byte = rb->buffer[rb->head];
    rb->head = (rb->head + 1) % RING_BUFFER_SIZE;
    
    return 0;
}

int ringBufferWriteByByte(ring_buffer_t* rb, uint8_t data)
{
    if(ringBufferIsFull(rb))
    {
        printf("Could not write to the buffer, as buffer is full\n");
        return -1;
    }
    rb->buffer[rb->tail] = data;
    rb->tail = (rb->tail + 1) % RING_BUFFER_SIZE;

    return 0;
}

int ringBufferWrite(ring_buffer_t* rb, uint8_t *data, uint32_t size)
{
    for(int i = 0; i < size; ++i)
    {
        if(ringBufferIsFull(rb))
        {
            printf("Could not write to the buffer, as buffer is full\n");
            return -1;
        }
        rb->buffer[rb->tail] = data[i];
        rb->tail = (rb->tail + 1) % RING_BUFFER_SIZE;
    }
    return 0;
}

void ringBufferPrint(ring_buffer_t* rb)
{
    printf("All Data in Ring Buffer:\n");
    for(int i = 0; i < RING_BUFFER_SIZE; ++i)
    {
        printf("%X ", rb->buffer[i]);
    }
}

int main()
{
    ring_buffer_t rb;
    ringBufferInit(&rb);
    
    uint8_t data[8] = {0xDE, 0xAD, 0xBE, 0xEF, 0x10, 0x20, 0x30, 0x40};
    
    ringBufferWrite(&rb, data, sizeof(data)/sizeof(data[0]));

    ringBufferPrint(&rb);
    
    printf("\n\nReading data byte by byte:\n");

    for(int i = 0; i < 8; ++i)
    {
        uint8_t data;
        if(!ringBufferReadByByte(&rb, &data))
            printf("%X ", data);
    }
    
    return 0;
}
