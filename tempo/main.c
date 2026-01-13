#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct list {
    int value;
    struct list *next;
};

bool tailInsert(struct list **ptr, int value) {
    struct list *newNode = (struct list*) malloc(sizeof(struct list));
    if (newNode == NULL)
        return false;

    while (*ptr != NULL) {
        ptr = &((*ptr)->next);
    }
    newNode->next = NULL;
    newNode->value = value;
    *ptr = newNode;
    return true;
}

void rimuovi(struct list **lA, struct list **lB, int v[], int n) {
    int i = 0;
    int count = 1;

    while (*lB != NULL) {
        lB = &((*lB)->next);
    }
    while (*lA != NULL && i < n) {

        if (count == v[i]) {
            *lB = *lA;
            *lA = (*lA)->next;
            (*lB)->next = NULL;

            lB = &((*lB)->next);

            i++;
            count++;
        }
        else {
            lA = &((*lA)->next);
            count++;
        }
    }
}

bool ordInsert(int *v, int n, int value) {
    for (int k = 0; k < n; k++) {
        if (v[k] == value) {
            return false;
        }
    }

    int i = 0;
    while (i < n && value > v[i]) {
        i++;
    }
    for (int j = n; j > i; --j) {
        v[j] = v[j-1];
    }
    v[i] = value;

    return true;
}

void visit(struct list **l) {
    while (*l != NULL) {
        printf("[%d] ", (*l)->value);
        l = &((*l)->next);
    }
    printf("\n");
}

int main() {
    printf("inizio programma...\n\n");
    bool esito;
    struct list *lA = NULL;
    struct list *lB = NULL;
    struct list **posA;
    struct list **posB;
    do {
        int input;
        printf("Inserire un numero nella lista A, inserire una lettera per terminare:\n");
        esito = scanf("%d", &input);
        if (esito)
            if (!tailInsert(&lA, input))
                return -1;
    } while (esito == 1);

    while (getchar() != '\n');

    do {
        int input;
        printf("Inserire un numero nella lista B, inserire una lettera per terminare:\n");
        esito = scanf("%d", &input);
        if (esito)
            if (!tailInsert(&lB, input))
                return -1;
    } while (esito == 1);

    while (getchar() != '\n');

    int n;
    int *v;

    do {
        printf("Inserire il numero di elementi che si intende spostare:\n");
        esito = scanf("%d", &n);
        if (esito == 0 || n < 0) {
            while (getchar() != '\n');
            esito = 0;
        }
    } while (esito == 0);

    v = (int*) malloc(sizeof(int)*n);
    if (v == NULL)
        return -1;

    for (int i = 0; i < n; ++i) {
        int val;
        printf("Inserire una posizione:\n");
        scanf("%d", &val);

        if (!ordInsert(v, i, val)) {
            printf("Errore: posizione %d gia' inserita! Riprova.\n", val);
            i--;
        }
    }

    printf("STAMPO VECCHIE LISTE...\n");

    visit(&lA);
    visit(&lB);

    printf("APPLICO RIMOZIONE MIRATA...");

    rimuovi(&lA, &lB, v, n);

    printf("STAMPO NUOVE LISTE...\n");

    visit(&lA);
    visit(&lB);

    return 0;
}
