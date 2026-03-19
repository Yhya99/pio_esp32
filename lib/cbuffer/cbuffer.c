#include "cbuffer.h"
#include <stdlib.h>
void cbuffer_init(cbuffer_t* buf) {
buf->head = 0;
buf->tail = 0;
}

bool cbuffer_empty(cbuffer_t* buf) {
    return (buf->head == buf->tail);
}

void cbuffer_add(cbuffer_t* buf, uint8_t item) {
    if (cbuffer_full(buf) == true)
    {
        buf->tail = (buf->tail + 1) & BUFFER_MASK;
    }
    
    buf->buffer[buf->head] = item; // write the item
    buf->head = (buf->head + 1) & BUFFER_MASK; // make sure the head doesn't overflow
}

uint8_t cbuffer_get(cbuffer_t* buf) {
    if (cbuffer_empty(buf) == true)
    {
        return NULL;
    }
    uint8_t item = buf->buffer[buf->tail];
    buf->tail = (buf->tail + 1) & BUFFER_MASK;
    return item;
}


bool cbuffer_full(cbuffer_t* buf) {
    return ((buf->head - buf->tail) & BUFFER_MASK) == BUFFER_MASK;;
}


void cbuffer_clear(cbuffer_t* buf) {
    buf->head = 0;
    buf->tail = 0;
}