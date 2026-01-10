#include <stddef.h>

struct list {
    int value;
    struct list *next;
};

bool esercizio (struct list **l1, struct list **l2) {

    if (*l2 == NULL)
        return true;

    struct list **pos1 = l1;
    struct list **pos2 = l2;


    while (*pos1 != NULL) {
        struct list *old1 = (*pos1)->next;
        bool matching = true;
        while (*pos2 != NULL && *pos1 != NULL && matching) {
            if ((*pos1)->value == (*pos2)->value) {
                pos1 = &((*pos1)->next);
                pos2 = &((*pos2)->next);
            } else
                matching = false;
        }
        if (matching && *pos2 == NULL)
            return true;
        pos1 = &old1;
        pos2 = l2;
    }
    return false;
}