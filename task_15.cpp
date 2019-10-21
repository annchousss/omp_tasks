#include <cstdio>
#include <omp.h>
#include <cmath>

int main() {
    int start;
    int end;
    bool isComplex;
    printf("Enter left border");
    scanf("%d", &start);
    printf("Enter right border");
    scanf("%d", &end);
#pragma parallel for
    for (int i = start; i <= end; i++) {
        isComplex = i == 1;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isComplex = true;
                break;
            }
        }
        if (!isComplex) {
            printf("%d\n", i);
        }
    }
    return 0;
}