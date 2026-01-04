#include <stddef.h>
#include <stdlib.h>

struct list {
    float value;
    struct list *next;
};

struct list** dupeTarget(struct list *ptr, float target, int *n) {
    struct list **pos = &ptr;
    int size = 0;
    *n = 0;
    while (*pos != NULL) {
        size++;
        pos = &((*pos)->next);
    }

    pos = &ptr;

    struct list **v = (struct list**) malloc(sizeof(struct list) * size);
    while (*pos != NULL) {
        if ((*pos)->value == target) {
            struct list *newNode = (struct list*) malloc(sizeof(struct list));
            newNode->value = target;
            newNode->next = (*pos)->next;
            (*pos)->next = newNode;
            v[(*n)++] = newNode;
            pos = &((*pos)->next->next);
        } else {
            pos = &((*pos)->next);
        }
    }
    return v;
}