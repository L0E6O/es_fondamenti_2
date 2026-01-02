#define epsilon 0.00001

void swap(float *a, float *b) {
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

bool isLower(float a, float b) {
    return (a<b && (b-a)>epsilon) ? true : false;
}

int antiBubbleSort(float *v, int n) {
    int iter = 0;
    bool swapFlag;
    if (n <= 0)
        return -1;
    do {
        swapFlag = false;
        for (int i = n-1; i > iter; --i) {
            if (isLower(v[i], v[i-1])) {
                swapFlag = true;
                swap(&(v[i]), &(v[i-1]));
            }
        }
        iter++;
    } while (swapFlag);
}