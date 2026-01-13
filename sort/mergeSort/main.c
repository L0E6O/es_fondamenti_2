#include <stdio.h>
#include <stdlib.h>

struct record {
    int code;
    float value;
};

// Funzione merge ottimizzata: alloca solo metà memoria
void merge(struct record *v, int n, int m) {
    int i = 0;      // indice per temp (metà sinistra copiata)
    int j = m;      // indice per v (metà destra originale)
    int k = 0;      // indice di scrittura su v

    // Alloco SOLO per la metà sinistra (da 0 a m)
    struct record *temp = (struct record *)malloc(m * sizeof(struct record));

    if (temp == NULL) return;

    // Copio la metà sinistra nel temp
    for (int x = 0; x < m; x++) {
        temp[x] = v[x];
    }

    // Unisco temp (sinistra) e v[j...] (destra) scrivendo su v[k...]
    // Nota: v[j] legge dalla parte destra dell'array originale, v[k] sovrascrive da sinistra
    while (i < m && j < n) {
        if (temp[i].value <= v[j].value) {
            v[k++] = temp[i++]; // Prendo da temp
        } else {
            v[k++] = v[j++];    // Prendo dalla destra di v
        }
    }

    // IL TUO PUNTO CHIAVE:
    // Se rimangono elementi in temp (sinistra), devo copiarli.
    while (i < m) {
        v[k++] = temp[i++];
    }

    // E se rimangono elementi a destra (j < n)?
    // NON FACCIO NULLA.
    // Poiché j è sempre >= k, se finisco la roba in temp,
    // i numeri restanti a destra in v sono già "parcheggiati" nelle celle finali corrette.

    free(temp);
}

void mergeSort(struct record *v, int n) {
    if (n > 1) {
        int m = n / 2;

        // Divide
        mergeSort(v, m);
        mergeSort(v + m, n - m); //n-m è la lunghezza, non l'ultimo indice!!!

        // Impera (Merge ottimizzato)
        merge(v, n, m);
    }
}