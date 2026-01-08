#define epsilon 0.0001
#include <math.h>

bool is_equal(float a, float b) {
    float difference = fabsf(a-b);
    a = fabs(a);
    b = fabs(b);
    float largest = (a > b) ? a : b;
    return (difference <= epsilon*largest) ? true : false;
}

bool binarySearch(float *a, int n, float target) {
    if (n >= 1) {
        if (is_equal(a[n/2], target)) {
            return true;
        } else if (a[n/2] > target)
            return binarySearch(a, n/2, target);
        else
            return binarySearch(a + (n/2 + 1), n - n/2 - 1, target);
    }
    return false;
}
