#include <tgmath.h>
#define epsilon 0.0001

struct record {
    float value;
    int next;
};

struct list {
    int first;
    int size;
    int free;
    struct record *buffer;
};

bool is_equal(float a, float b) {
    float diff = fabsf(a - b);
    a = fabsf(a);
    b = fabsf(b);
    float largest = (a >= b) ? a : b;
    return (diff <= largest*epsilon) ? true : false;
}

bool esercizio(struct list *ptr) {
    int *pos = &ptr->first;
    bool removed = false;

    while (*pos != ptr->size && ptr->buffer[*pos].next != ptr->size) {
        int next = ptr->buffer[*pos].next;
        if (ptr->buffer[next].value < ptr->buffer[*pos].value && !is_equal(ptr->buffer[*pos].value, ptr->buffer[next].value)) {
            ptr->buffer[*pos].next = ptr->buffer[next].next;
            ptr->buffer[next].next = ptr->free;
            ptr->free = next;
            removed = true;
        } else
            pos = &(ptr->buffer[*pos].next);
    }
    return removed;
}