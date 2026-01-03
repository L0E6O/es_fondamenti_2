struct record {
    float value;
    int next;
};

struct list {
    struct record *buffer;
    int size;
    int first;
    int free;
};

bool insOrdArrayIndici(struct list *ptr, float value) {
    if (ptr->free != ptr->size) {
        int *pos;
        pos = &(ptr->first);

        while (*pos != ptr->size && ptr->buffer[*pos].value < value) {
            pos = &(ptr->buffer[*pos].next);
        }

        int moved = ptr->free;

        ptr->free = ptr->buffer[ptr->free].next;
        ptr->buffer[moved].next = *pos;
        ptr->buffer[moved].value = value;
        *pos = moved;
        return true;
    }
    return false;
}