#include <stddef.h>

struct list{
    int value;
    struct list* next;
};

void scambio(struct list **l1, struct list **l2, int target1, int target2) {
    struct list **pos1 = l1;
    struct list **pos2 = l2;

    while (*pos1 != NULL && *pos2 != NULL) {
        bool f1 = false;
        bool f2 = false;

        while (*pos1 != NULL && !f1) {
            if ((*pos1)->value == target1)
                f1 = true;
            else
                pos1 = &((*pos1)->next);
        }

        while (*pos2 != NULL && !f2) {
            if ((*pos2)->value == target2)
                f2 = true;
            else
                pos2 = &((*pos2)->next);
        }

        if (f1 && f2) {
            struct list *tmp1 = *pos1;
            struct list *tmp2 = *pos2;
            struct list *Next2 = (*pos2)->next; //basterebbe anche solo questo next
            struct list *Next1 = (*pos1)->next;
            tmp2->next = Next1;
            *pos1 = tmp2;
            tmp1->next = Next2;
            *pos2 = tmp1;
        }
    }
}