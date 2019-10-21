#include <cstdio>
#include <omp.h>

int main() {
    int sum = 0;
#pragma parallel for
    for (int i = 1; i < 210; i++) {
        if (i % 2 != 0) {
#pragma omp atomic
            sum += i;
        }
    }
    printf("Square = %d", sum);
    return 0;
}