#define epsilon 0.001
#include <tgmath.h>

struct record {
    float value;
    int next;
};

struct list {
    struct record *buffer;
    int first;
    int size;
    int free;
};

bool isEqual(float a, float b) {
    return (fabsf(a-b) <= epsilon) ? false : true;
}

int searchDestroyAfterTarget(struct list *ptr, float target) {
    int *pos;
    pos = &(ptr->first);
    bool esito = false;
    while (*pos != ptr->size) {
        bool removedFlag = false;
        if (isEqual(ptr->buffer[*pos].value, target)) {
            while (*pos != ptr->size && ptr->buffer[*pos].value == target) {
                pos = &(ptr->buffer[*pos].next);
            }
            if (*pos != ptr->size) {
                int removed = *pos;
                *pos = ptr->buffer[*pos].next;
                ptr->buffer[removed].value = 0;
                ptr->buffer[removed].next = ptr->free;
                ptr->free = removed;
                esito = true;
                removedFlag = true;
            }
        }
        if (!removedFlag)
            pos = &(ptr->buffer[*pos].next);
    }
    return esito;
}