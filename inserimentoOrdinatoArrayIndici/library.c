#include "library.h"

#include <stdio.h>

struct list {
    int *buffer;
    int head;
    int size;
    int tail;
};

int inserimentoOrdinato(struct list *ptr, int val) {
    if (ptr->head == (ptr->tail+1)%ptr->size) { //controllo che ci sia spazio
        return -1;
    }

    int pos = ptr->head;

    while (pos != ptr->tail && ptr->buffer[pos] < val) { //cerco posizione per inserimento
        pos = (pos+1)%ptr->size;
    }

    for (int i = ptr->tail; i != pos; i = (i-1+ptr->size)%ptr->size) { //shift di un passo a destra
        ptr->buffer[i] = ptr->buffer[(i-1 + ptr->size) % ptr->size];
        //non basta fare i-1, in quanto potrebbe dare un numero negativo e quindi errore
    }

    ptr->buffer[pos] = val;
    ptr->tail = (ptr->tail+1)%ptr->size;
    //non faccio +ptr->size perché sto sommando due numeri positivi e non rischio quindi di andare in negativo
    return 0;
}