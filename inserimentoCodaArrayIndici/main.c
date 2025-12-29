#include <stdio.h>

struct list {
    int *buffer;
    int size;
    int head;
    int tail;
};

int tailInsert(struct list *ptr, int val) {
    if (ptr->head == (ptr->tail+1)%ptr->size)
        return -1;

    ptr->buffer[ptr->tail] = val;
    ptr->tail = (ptr->tail+1)%ptr->size;
    return 0;
}