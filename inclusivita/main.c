struct list {
    int head;
    int tail;
    int size;
    int *buffer;
};

bool is_included(struct list *l1, struct list *l2) {
    bool matching = false;

    int pos1 = l1->head;
    int pos2 = l2->head;
    int oldP2;

    while (pos2 != l2->tail) {
        if (l1->buffer[pos1] == l2->buffer[pos2]) {
            matching = true;
            oldP2 = pos2;
            while (pos1 != l1->tail && matching) {
                if (l1->buffer[pos1] == l2->buffer[pos2]) {
                    pos1 = (pos1 + 1)%l1->size;
                    pos2 = (pos2 + 1)%l2->size;
                } else
                    matching = false;
            }
            if (matching && pos1 == l1->tail) {
                return true;
            }
            pos2 = (oldP2 + 1)%l2->size;
            pos1 = l1->head;
        } else
            pos2 = (pos2 + 1)%l2->size;
    }
    return false;
}