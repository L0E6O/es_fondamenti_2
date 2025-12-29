#include <float.h>
#include <stdio.h>
#include <stdlib.h>

struct list {
    struct list *next;
    float value;
};

bool is_lower(float a, float b)
{
    if ( b-a > FLT_EPSILON )
        return true;

    return false;
}

int insertIntermidiate(struct list **ptr, int value) {
    struct list *newNode = (struct list *)malloc(sizeof(struct list));
    if (newNode == NULL)
        return -1;
    newNode->value = value;

    while (*ptr != NULL && is_lower((*ptr)->value, value)) {
        ptr = &((*ptr)->next);
    }

    newNode->next = *ptr;
    *ptr = newNode;
    return 0;
}