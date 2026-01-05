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

void bubbleSort(struct record *v, int n) {
    int i, j;
    int scambiato;

    // i rappresenta quanti elementi sono già stati posizionati correttamente in fondo
    for (i = 0; i < n - 1; i++) {
        scambiato = 0; // Reset del flag ad ogni passata

        // j scorre l'array. Nota il "- i": non serve controllare gli ultimi i elementi
        // perché sappiamo che sono già "galleggiati" nella posizione corretta
        for (j = 0; j < n - 1 - i; j++) {

            // Confronto coppie adiacenti
            if (v[j].value > v[j+1].value) {
                swap(v, j, j+1);
                scambiato = 1; // Segnalo che è avvenuto uno scambio
            }
        }

        // SE non c'è stato neanche uno scambio in tutto il ciclo interno,
        // l'array è ordinato. Interrompo per evitare giri inutili (Best Case O(n))
        if (!scambiato) {
            break;
        }
    }
}