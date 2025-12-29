#include <stdio.h>
#include <stdlib.h>

struct list {
    int value;
    struct list *next;
};

int completamentoADueListe(struct list **head1, struct list **head2) {
    int count = 0;

    // ptr1 è un "cursore" che punta al LINK che stiamo valutando in lista1.
    // All'inizio punta al puntatore di testa (*head1).
    struct list **ptr1 = head1;
    
    // ptr2 punta al LINK in lista2. ho cosi un offset che mi fa sempre stare dietro al nodo in esame, non sopra
    struct list **ptr2 = head2;

    // Finchè ci sono nodi in entrambe le liste
    while (*ptr1 != NULL && *ptr2 != NULL) {
        
        // Confrontiamo i valori dei nodi puntati
        if ((*ptr2)->value < (*ptr1)->value) {
            // CASO A: Il valore in lista2 è minore. Va inserito QUI in lista1.
            
            struct list *nodoDaSpostare = *ptr2; // 1. Prendiamo il nodo da L2
            
            // 2. Rimuoviamo il nodo da L2 (ricuciamo L2)
            *ptr2 = nodoDaSpostare->next;
            
            // 3. Inseriamo il nodo in L1 (agganciamo al nodo corrente di L1)
            nodoDaSpostare->next = *ptr1;
            
            // 4. Facciamo puntare il "link" precedente (o la testa) al nuovo nodo
            *ptr1 = nodoDaSpostare;
            
            // 5. Avanziamo il cursore ptr1 (ora siamo sul nodo appena inserito, andiamo al suo next)
            ptr1 = &((*ptr1)->next);
            
            count++;
        } 
        else if ((*ptr2)->value == (*ptr1)->value) {
            // CASO B: Valori uguali. NON copiare.
            // Avanziamo in entrambe le liste ignorando il nodo di L2 (rimane lì)
            ptr2 = &((*ptr2)->next);
            ptr1 = &((*ptr1)->next);
        } 
        else {
            // CASO C: Il valore di L1 è minore.
            // Il nodo di L2 potrebbe andare più avanti. Avanziamo solo su L1.
            ptr1 = &((*ptr1)->next);
        }
    }

    // CASO D: L1 è finita, ma L2 ha ancora elementi (che sono sicuramente maggiori).
    // Dobbiamo attaccare tutto il resto di L2 in coda a L1.
    while (*ptr2 != NULL) {
        struct list *nodoDaSpostare = *ptr2;
        *ptr2 = nodoDaSpostare->next; // Stacca da L2
        
        nodoDaSpostare->next = NULL;  // Sarà l'ultimo
        *ptr1 = nodoDaSpostare;       // Attacca in coda a L1
        
        ptr1 = &((*ptr1)->next);      // Avanza cursore
        count++;
    }

    return count;
}
