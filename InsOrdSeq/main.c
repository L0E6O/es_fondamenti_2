#define epsilon 0.00001
#include <tgmath.h>

struct record {
    float value;
};

struct list {
    int size;
    int head;
    int tail;
    struct record *buffer;
};

bool is_equal(float a, float b) {
    float diff, largest;
    diff = fabsf(a-b);
    a = fabsf(a);
    b = fabsf(b);
    largest = a > b ? a : b;
    return (diff <= epsilon*largest);
}

bool InsOrd(struct list *ptr, float value) {
    int pos = ptr->head;

    if ((ptr->tail + 1) % ptr->size == ptr->head) { //controllo se è piena (l'ultimo elemento sarà sempre vuoto)
        return false;
    }

    while (pos != ptr->tail && ptr->buffer[pos].value < value && !is_equal(ptr->buffer[pos].value, value)) {
        pos = (pos + 1) % ptr->size;
    }

    ptr->tail = (ptr->tail + 1) % ptr->size;
    for (int i = (ptr->tail - 1 + ptr->size)%ptr->size; i != pos; i = (i - 1 + ptr->size) % ptr->size) {
        ptr->buffer[i].value = ptr->buffer[(i - 1 + ptr->size) % ptr->size].value;
    }
    ptr->buffer[pos].value = value;

    return true;
}
