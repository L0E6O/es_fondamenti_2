#include <tgmath.h>
#define epsilon 0.0001

struct record {
    float value;
    int next;
};

struct list {
    int first;
    int free;
    int size;
    struct record *buffer;
};

bool is_equal(float a, float b) {
    float diff = fabsf(a-b);
    a = fabsf(a);
    b = fabsf(b);
    float largest = (a >= b) ? a : b;
    return (diff <= largest*epsilon) ? true : false;
}

bool removeAfterTarget(struct list *ptr, float target) {
    int *pos = &ptr->first;

    while (*pos != ptr->size) {
        if (is_equal(ptr->buffer[*pos].value, target) && ptr->buffer[*pos].next != ptr->size) {
            pos = &(ptr->buffer[*pos].next);
            int removed = *pos;
            *pos = ptr->buffer[removed].next;
            ptr->buffer[removed].next = ptr->free;
            ptr->free = removed;
            return true;
        }
        pos = &(ptr->buffer[*pos].next);
    }
    return false;
}