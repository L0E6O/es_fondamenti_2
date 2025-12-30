#include <math.h>
#include <stdio.h>
#define epsilon 0.00001

struct record {
    float value;
    int next;
};

struct list{
    struct record *buffer;
    int first;
    int free;
    int size;
};

bool isEqual(float a, float b) {
    float diff, largest;
    diff = fabs(a-b);
    a = fabs(a);
    b = fabs(b);
    largest = a > b ? a : b;
    if (diff <= epsilon*largest)
        return true;

    return false;
}

bool search(struct list *ptr, float target) {
    bool found = false;
    int  *pos, moved; //*pos punta all'area di memoria del nodo precedente dove è tenuto l'indice dell'attuale, a partire da *pos, con next vado due avanti
    if( ptr->first != ptr->size ) { // not void
        pos = &ptr->first;
        while( ptr->buffer[*pos].next != ptr->size )
            if( isEqual(ptr->buffer[*pos].value,target) ) {
                found = true;
                moved = *pos; //salvo l'indice del nodo da cancellare
                *pos = ptr->buffer[*pos].next; //agendo la memoria appartenente al nodo precedente, mettendo il valore del nodo successivo a quello cancellato
                ptr->buffer[moved].next = ptr->free; //collego il cancellato al vecchio primo libero
                ptr->free = moved; //metto il cancellato tra i liberi
            }
            else
                pos = &(ptr->buffer[*pos] .next);
    }
    return found;
}