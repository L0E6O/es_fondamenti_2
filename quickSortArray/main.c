struct record {
    int code;
    float value;
};

void swap(struct record *v, int r, int l) {
    struct record tmp = v[r];
    v[r] = v[l];
    v[l] = tmp;
}

int partition(struct record *v, int n) {
    int r = n, l = 0;
    //eseguo partition
    float pivot = v[0].value;
    while (l < r) { //quando i limiti si incrociano, tutto ciò che è a sinistra è minore del pivot e viceversa
        do{r--;} while (pivot > v[r].value && r > l); //muovo il destro indietro
        do{l++;} while (pivot < v[l].value  && l < r);
        //quando finisco i numeri da un lato, r e l si incroceranno per forza e ciò significherà che tutto è ordinato rispetto al pivot
        swap(v, r, l);
    }
    swap(v, 0, l); //si sposta il pivot nell a sua pos effettiva
    return r;
}

void quickSort(struct record *v, int n) {
    if (n>1) {
        int q = partition(v, n);
        quickSort(v, q);
        quickSort(&(v[q+1]), n-q-1);
    }
}