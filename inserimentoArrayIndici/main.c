#include <stdio.h>
#include <stdlib.h>

struct record {
    int value;
    int next;
};

struct list {
    struct record *buffer;
    int free;
    int first;
    int size;
};

int inserimentoOrdinato(struct list *ptr, int value) {
    int pos = ptr->first;
    if (ptr->free != ptr->size) {
        int previous;
        while ((pos != ptr->size) &&(ptr->buffer[pos].value < value)) {
            previous = pos;
            pos = ptr->buffer[pos].next;
        }
        int moved = ptr->free;
        ptr->free = ptr->buffer[moved].next;
        if (pos != ptr->first) {
            ptr->buffer[previous].next = moved;
        } else
            ptr->first = moved;
        ptr->buffer[moved].next = pos;
        ptr->buffer[moved].value = value;
        return 0;
    }
    return -1;
}