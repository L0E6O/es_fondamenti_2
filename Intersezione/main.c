#include <math.h>
#include <stdlib.h>
#define epsilon 0.001

struct list {
    int head;
    int tail;
    int size;
    float *buffer;
};

bool is_equal(float a, float b) {
    float diff = fabs(a-b);
    a = fabsf(a);
    b = fabsf(b);
    float largest = (a > b) ? a : b;
    return (diff <= largest*epsilon) ? true : false;
}

bool intersezione (struct list *l1, struct list *l2, struct list **l3) {
    bool intersection = false;
    int dimL1 = (l1->tail - l1->head + l1->size)%l1->size;
    int dimL2 = (l2->tail - l2->head + l2->size)%l2->size;
    int sizeL3 = (dimL1 >= dimL2) ? dimL2 + 1 : dimL1 + 1;

    (*l3)->buffer = (float*) malloc(sizeof(float)*sizeL3);
    (*l3)->size = sizeL3;
    (*l3)->head = 0;
    (*l3)->tail = 0;

    int pos1 = l1->head;

    while (pos1 != l1->tail) {
        int posS = l2->head;
        bool found = false;
        while (posS != l2->tail && !found) {
            if (is_equal(l1->buffer[pos1], l2->buffer[posS])) {
                intersection = true;
                found = true;
                (*l3)->buffer[(*l3)->tail] = l2->buffer[posS];
                (*l3)->tail = ((*l3)->tail + 1)%(*l3)->size;
            }
            posS = (posS + 1)%l2->size;
        }
        pos1 = (pos1 + 1)%l1->size;
    }
    return intersection;
}