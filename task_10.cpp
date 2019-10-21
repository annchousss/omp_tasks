#include <cstdio>
#include <omp.h>
#include <time.h>
#include <cstdlib>

int main() {

    int a[30];
    srand(time(NULL));

    for (auto &i : a) {
        i = rand();
    }

    omp_set_num_threads(4);
#pragma parallel for
    int count = 0;
    for (int i = 0; i < 30; i++) {
        if (a[i] % 9 == 0) {
            #pragma omp atomic
            count++;
        }
    }
    printf("Multiples of 9: %d", count);
    return 0;
}