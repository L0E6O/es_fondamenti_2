struct record{
  int value;
  int next;
};

struct list {
    struct record *buffer;
    int free;
    int first;
    int size;
};

bool sufInsert(struct list *ptr, int value) {
    int *pos = &ptr->first;

    if (ptr->free == ptr->size)
        return false;

    while (*pos != ptr->size) {
        pos = &(ptr->buffer[*pos].next);
    }

    int moved = ptr->free;
    ptr->free = ptr->buffer[moved].next;
    ptr->buffer[moved].next = ptr->size;
    ptr->buffer[moved].value = value;
    *pos = moved;
    return true;
}