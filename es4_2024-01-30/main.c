struct record {
    int value;
    int next;
};

struct list {
    int size;
    int free;
    int first;
    struct record *buffer;
};

void esercizio(struct list *ptr, int k) {
    int *pos = &ptr->first;
    int tail;
    int count = 0;

    while (*pos != ptr->size) {
        count++;
        tail = *pos;
        pos = &(ptr->buffer[*pos].next);
    }

    if (count <= k)
        return;

    count = 0;

    pos = &ptr->first;

    while (count++ < k) {
        int moved = *pos;
        *pos = ptr->buffer[moved].next;
        ptr->buffer[tail].next = moved;
        ptr->buffer[moved].next = ptr->size;
        tail = moved;
    }
}