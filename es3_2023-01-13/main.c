#include <stddef.h>
#include <stdlib.h>

struct list {
    int value;
    struct list *next;
};

void nodeSwap(struct list **ptr, struct list **ptr2) {
    struct list *tmp = *ptr;
    struct list *tmp2 = *ptr2;
    struct list *next = (*ptr)->next;
    struct list *next2 = (*ptr2)->next;
    tmp2->next = next;
    *ptr = tmp2;
    tmp->next = next2;
    *ptr2 = tmp;
}

void esercizio(struct list **ptr, int *count) {
    *count = 0;
    while (*ptr != NULL && (*ptr)->next != NULL) {
        if ((*ptr)->next->next != NULL) {
            if ((*ptr)->value > (*ptr)->next->next->value) {
                nodeSwap(ptr, &((*ptr)->next->next));
                (*count)++;
            }
        }
        ptr = &((*ptr)->next->next);
    }
}