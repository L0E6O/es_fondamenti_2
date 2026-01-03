#include <stdlib.h>

struct list {
    int * buffer; //array valori
    int head;
    int tail;
    int size;
};
bool merge_list(struct list * ptr, int N1) {
    int l, r, *tmp, N;
    tmp = (int *) malloc(sizeof(int)*N1);
    if( tmp == NULL )
        return false;
    for( l=0; l<N1; l++) //copio la parte sinistra in tmp
        tmp[l] = ptr->buffer[(ptr->head+l)%ptr->size]; //array temporaneo di appoggio per parte destra
    l=0;
    r=0;
    N = (ptr->tail-ptr->head+ptr->size)%ptr->size;
    while( l < N1 && r < N-N1 ) {
        if( tmp[l] < ptr->buffer[(ptr->head+N1+r)%ptr->size] ) {
            ptr->buffer[(ptr->head+r+l)%ptr->size] = tmp[l]; //r+l da la pos nell'array originale
            l++;
        }
        else {
            ptr->buffer[(ptr->head+r+l)%ptr->size] = ptr->buffer[(ptr->head+N1+r)%ptr->size];
            r++;
        }
    }
    while( l < N1 ) { //se il sinistro non è finito, copio le cose rimanenti
        ptr->buffer[(ptr->head+r+l)%ptr->size] = tmp[l];
        l++;
    }
    //per il destro non si fa perché di base la parte destra l'abbiamo lasciata su ptr,
    //quindi se quella è rimasta da finire, semplicemente c'è già tutto ciò che serve
    free(tmp);
    return true;
}