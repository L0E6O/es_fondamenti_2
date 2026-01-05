struct record {
    int value;
    int next;
};

struct list {
    int first;
    int free;
    int size;
    struct record *buffer;
};

bool inclusion(struct list *l1, struct list *l2) {
    bool inclusion = false;

    int *pos1 = &(l1->first);
    int *pos2;

    while (*pos1 != l1->size) { //giro su l1 (più grande per definizione
        pos2 = &(l2->first);
        int *oldPos1 = pos1; //salvo la pos1
        bool match = true;

        while ((*pos1 != l1->size) && (*pos2 != l2->size) && (match == true)) {
            if (l1->buffer[*pos1].value != l2->buffer[*pos2].value) {
                match = false;
            } else {
                pos1 = &(l1->buffer[*pos1].next);
                pos2 = &(l2->buffer[*pos2].next);
            }
        }
        if (*pos2 == l2->size && match)
            return true;

        pos1 = oldPos1;
        pos1 = &(l1->buffer[*pos1].next);
    }
    return false;
}
