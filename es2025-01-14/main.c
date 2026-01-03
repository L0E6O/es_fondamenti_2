#include <stddef.h>
#include <stdlib.h>

struct list {
    int value;
    struct list *next;
};

void func(struct list *ptr, int **a, int *n) {
    *n = 0;
    struct list **pos;
    pos = &ptr;
    int size = 0;
    while (*pos != NULL) {
        size++;
        pos = &((*pos)->next);
    }
    *a = (int *) malloc(sizeof(int) * size);
    if (*a == NULL) {
        return;
    }

    pos = &ptr;

    while ((*pos)->next != NULL) {
        if (((*pos)->value % (*pos)->next->value) != 0) {
            struct list *newnode = (struct list*) malloc(sizeof(struct list));
            if (newnode == NULL) {
                return;
            }
            newnode->value = (*pos)->value % (*pos)->next->value;
            newnode->next = (*pos)->next;
            (*pos)->next = newnode;
            pos = &((*pos)->next->next);
        } else {
            (*a)[(*n)++] = (*pos)->next->value;
            struct list *removing;
            removing = (*pos)->next;
            (*pos)->next = removing->next;
            free(removing);
        }
    }
}