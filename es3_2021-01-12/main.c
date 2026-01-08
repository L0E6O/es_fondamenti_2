#include <stdlib.h>

struct list {
    int head;
    int tail;
    int size;
    int *buffer;
};

void merge(struct list *ptr, int n, int n1) {
    int *v = (int*) malloc(sizeof(int) * n);

    int i = ptr->head;
    n1 = (ptr->head + n1)%ptr->size;
    int j = n1;
    int k = 0;
    while (i != n1 && j != ptr->tail) {
        if (ptr->buffer[i] <= ptr->buffer[j]) {
            v[k++] = ptr->buffer[i];
            i = (i+1)%ptr->size;
        } else {
            v[k++] = ptr->buffer[j];
            j = (j+1)%ptr->size;
        }
    }

    while (i != n1) {
        v[k++] = ptr->buffer[i];
        i = (i+1)%ptr->size;
    }

    while (j != ptr->tail) {
        v[k++] = ptr->buffer[j];
        j = (j+1)%ptr->size;
    }
}
