#include <stdlib.h>

struct list {
    int value;
    struct list *next;
};

bool esercizio(struct list **ptr, int *v, int n) {
    if (n < 1)
        return false;

    int i = 0;

    while (i < n) {
        struct list *newNode = (struct list *) malloc(sizeof(struct list));
        newNode->value = v[i++];
        newNode->next = *ptr;
        *ptr = newNode;
        if ((*ptr)->next == NULL) {
            ptr = &((*ptr)->next);
        }else
            ptr = &((*ptr)->next->next);
    }
    return true;
}
