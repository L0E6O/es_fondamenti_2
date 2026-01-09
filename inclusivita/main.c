struct list {
    int head;
    int tail;
    int size;
    int *buffer;
};

bool funzione(struct list *l1, struct list *l2) {
    if (l1->head == l1->tail)
        return true;

    int pos1 = l1->head;
    int pos2 = l2->head;
    int oldPos2;
    bool matching = true;

    while (pos2 != l2->tail) {
        oldPos2 = pos2;

        while (pos2 != l2->tail && pos1 != l1->tail && matching) {
            if (l2->buffer[pos2] == l1->buffer[pos1]) {
                pos1 = (pos1 + 1)%l1->size;
                pos2 = (pos2 + 1)%l2->size;
            } else
                matching = false;
        }

        if (matching && pos1 == l1->tail)
            return true;
        pos1 = l1->head;
        pos2 = (oldPos2 + 1)%l2->size;
        matching = true;
    }
    return false;
}