#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <omp.h>

int main() {
    int a[10];

    for (auto &i : a) {
        i = rand();
        printf("%d\n", i);
    }

    int result = 0;
#pragma omp parallel for
    for (int i = 0; i < 10; i++) {
        if (a[i] % 7 == 0) {
            #pragma omp critical
            {
                result++;
            }
        }
    }
    printf("Result = %d", result);
    return 0;
}