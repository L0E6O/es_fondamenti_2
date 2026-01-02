#include <stdlib.h>

struct list {
    int value;
    int pos;
    struct list *next;
};

int fibonacciRemove(struct list **ptr, int **v) {
    int size = 0;
    struct list **cursor;
    cursor = ptr;
    while ((*cursor) != NULL) {
        cursor = &((*cursor)->next);
        size++;
    }

    if (size == 0) {
        *v = NULL;
        return 0;
    }

    *v = (int *) malloc(sizeof(int) * size);

    cursor = ptr;

    int fibonacci[3];
    fibonacci[0] = 1;
    fibonacci[1] = 2;
    fibonacci[2] = 2;

    int iter = 1, vTail = 0;

    do {
        if (iter == 1 || iter==2) {
            fibonacci[2] = iter;
        } else {
            fibonacci[2] = fibonacci[0] + fibonacci[1];
            fibonacci[0] = fibonacci[1];
            fibonacci[1] = fibonacci[2];
        }

        int count  = 1;

        while (count++ != fibonacci[2]) {
            if (count > size) {
                return vTail;
            }
            cursor = &((*cursor)->next);
        }

        if (*cursor == NULL)
            return vTail;

        struct list *moving = *cursor;
        *cursor = (*cursor)->next;
        size--;
        (*moving).next = NULL;
        (*moving).pos = fibonacci[2];

        for (int i = vTail++; i > 0; i--) {
            (*v)[i] = (*v)[i-1];
        }
        (*v)[0] = moving->value;

        free(moving);
        iter++;
        cursor = ptr;
    } while (true);
}