#include <stddef.h>

struct list {
    int value;
    struct list *next_ptr;
};

void invert(struct list **ptr, int N, int K, struct list **pos) {
    int count, i;
    struct list *tmp, **pos_k;
    *pos = NULL;
    count = 1;
    while (*ptr != NULL && count < K) {
        count++;
        ptr = &((*ptr)->next_ptr);
    }
    if (count == K) {
        pos_k = ptr; // indirizzo elemento in posizione K
        for (i = 0; i < N; i++) {
            tmp = (*ptr)->next_ptr; //tmp è l'elemento dopo il cursore (e dopo il k originale anche)
            (*ptr)->next_ptr = tmp->next_ptr; //dove siamo ora (k originale), punta a dopo il tmp
            tmp->next_ptr = *pos_k; //adesso tmp punta al k originale
            *pos_k = tmp; //tmp si trova ora nella pos numero k
            ptr = &((*ptr)->next_ptr); //avanzo il cursore
        }
        *pos = *pos_k;
    }

    /*
     * essenzialmente:
     * 1) trovo la pos k e fermo il cursore
     * 2)mi salvo l'indirizzo dell'indirizzo all'el in pos k
     * 3)ed inizio il ciclo:
     *      1.mi salvo indirizzo di el dopo il cursore (che è sopra a k per ora) in tmp
     *      2.faccio puntare al cursore (che è sempre sopra k) a ciò che è dopo tmp
     *      3.faccio puntare il next di tmp a k (ora tmp sarà in pos k, avendolo messo prima)
     *      4. faccio puntare a *posK tmp (così che il prossimo numero sotto al cursore si trovi a
     *      doversi di nuovo semplicemente mettersi davanti a k
     *      5.avanzo il cursore
     * 4)salvo l'indirizzo di ciò che si trova in posizione k
     */
}