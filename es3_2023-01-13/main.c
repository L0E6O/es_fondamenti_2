#include <stddef.h>
#include <stdlib.h>

struct list {
    int value;
    struct list *next;
};

void nodeSwap(struct list **ptr, struct list **ptr2) {
    struct list *tmp = *ptr; //mi salvo il puntatore ad A
    struct list *tmp2 = *ptr2; //mi salvo il puntatore a C
    struct list *next = (*ptr)->next; //mi salvo il puntatore a B
    struct list *next2 = (*ptr2)->next; //mi salvo il puntatore a D
    tmp2->next = next; //imposto il next di C per puntare a B (tmp2->next punta cmq al vero next di C)
    *ptr = tmp2; //imposto l'indirizzo del primo elemento uguale a quello di C
    tmp->next = next2; //imposto il next di A per puntare a D
    *ptr2 = tmp; //imposto l'indirizzo del secondo elemento (ex C) per puntare ad A
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