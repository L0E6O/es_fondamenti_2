#include <stdio.h>
#include <stdlib.h>

struct list {
    int val;
    struct list *next;
};

int strangeMerge(struct list **v1, struct list **v2, struct list **v3) {
    int count = 1;
    while ((*v1) != NULL && (*v2) != NULL) {
        if (count % 2 != 0) {
            struct list *temp = *v1;
            *v1 = (*v1)->next;
            (*v3) = temp;
            temp->next = NULL;
            v2 = &((*v2)->next);
        } else {
            struct list *temp = *v2;
            *v2 = (*v2)->next;
            (*v3) = temp;
            temp->next = NULL;
            v1 = &((*v1)->next);
        }
        count++;
        v3 = &((*v3)->next);
    }
    while ((*v2)->next != NULL) {
        struct list *temp = *v2;
        free(*v2);
        *v2 = (temp)->next;
    }
    while ((*v1)->next == NULL) {
        struct list *temp = *v1;
        free(*v1);
        *v1 = (temp)->next;
    }
}
