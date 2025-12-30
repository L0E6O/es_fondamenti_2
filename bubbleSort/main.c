#include <stdio.h>

bool swap(int v[], int n, int m);

int bubbleSort(int *v, int n) {
    bool swapFound = false;
    int iter=0;
    do {
        for (int i = 0; i<n-iter-1; i++) {
            if (v[i]>v[i+1]) {
                swap(v, i, i+1);
                swapFound = true;
            }
        }
        iter++; //si conta l'iterazione che è uguale al numero di elementi già nella posizione
                //giusta. Il numero più grande di tutti sarà infondo e quindi non sarà più da
                //considerare. IL BUBBLE SORT SI ORDINA DALLA CODA ALLA TESTA
    } while (swapFound);
}