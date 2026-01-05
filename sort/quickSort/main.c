#include <stdio.h>

struct record {
    int code;
    float value;
};

void swap(struct record *v, int i, int j) {
    struct record tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

int partition(struct record *v, int n) {
    int l = 0, r = n;
    struct record pivot = v[0]; //a fine funzione, dovrà essere nella pos giusta
    while (l < r) {
        //controllo che non si sia a fine
        do { r--; } while (v[r].value > pivot.value && r > l);
        //è già in ordine rispetto a pivot, guardo l'el precedente
        if (l!=r) { //controllo che nella istruzione sopra r non abbia raggiunto l prima di continuare inutilmente
            do { l++; } while (v[l].value <= pivot.value && l < r);
            //è già in ordine rispetto a pivot, guardo l'el successivo
            swap(v, l, r);
            //effettuo lo scambio tra i due, entrambi sicuramente dal lato sbagliato rispetto al pivot
        }
    } //da qui in poi l==r
    swap(v, 0, r);
    //metto il pivot nella giusta posizione, quella che a causa di ciò che è stato fatto è sicuramente nella pos giusta rispetto a tuttti gli altri elementi, la pos è ==r==l
    return l;
}

void quickSort(struct record *v, int n) {
    if (n > 1) { //controllo di non aver raggiunto la massima profondità
        int q = partition(v, n); //prendo la pos del pivot
        quickSort(v, q); //quicksort su metà sinistra
        quickSort(v + q + 1, n - q - 1); //quicksort su metà destra
    }
}
