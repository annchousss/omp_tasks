#include <cstdio>
#include <omp.h>
#include <cmath>

int main() {
    int a[30] = {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1};
    int num = 0;
    int i = 0;
#pragma omp parallel for
    for (i = 0; i < 30; i++) {
#pragma omp atomic
        num += a[29 - i] * pow(2, i);
    }
    printf("Number = %d", num);
    return 0;
}