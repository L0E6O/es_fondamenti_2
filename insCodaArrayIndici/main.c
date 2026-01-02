#include <stdio.h>

struct record {
    int value;
    int next;
};

struct list {
    struct record *buffer;
    int size;
    int free;
    int first;
};

int insCoda(struct list *ptr, int value) {
    int *pos;
    pos = &(ptr->first); //pos conterrà per tutto il tempo il valore di next, pur stando nell'elemento prima a quello in esame

    //così si puo sia accedere al corrente (in realtà next) sia al precedente
    //(in realtà il corrente in quanto operiamo grazie al next che sta nella sua area di memoria)

    if (ptr->free == ptr->size)
        return -1;

    while (*pos != ptr->size) {
        pos = &(ptr->buffer[*pos].next);
    }

    int moved = ptr->free;
    ptr->free = ptr->buffer[ptr->free].next;
    ptr->buffer[moved].value = value;
    *pos = moved;
    ptr->buffer[moved].next = ptr->size;

    return 0;
}