#include <cstdio>
#include <omp.h>
#include <time.h>
#include <cstdlib>

int main() {

    int d[6][8];
    srand(time(NULL));

    for (auto &i : d) {
        for (int &j : i) {
            j = rand();
        }
    }
    int min = d[0][0];
    int max = d[0][0];
omp_set_num_threads(4);
#pragma omp parallel for shared(min, max, d)
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            #pragma omp critical
            {
                if (d[i][j] > max) {
                    max = d[i][j];
                } else if (d[i][j] < min) {
                    min = d[i][j];
                }
            }
        }
    }

    printf("Min = %d Max = %d", min, max);
    return 0;
}