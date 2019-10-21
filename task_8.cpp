#include <cstdio>
#include <omp.h>
#include <ctime>
#include <cstdlib>

//parallel multiplication
void parallel(int a[100][100], int b[100]) {
    int c[100];
    for (auto &i : c) {
        i = 0;
    }
    double lastTime = omp_get_wtime();
#pragma parallel for
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            c[j] += a[i][j] * b[j];
        }
    }
    double currTime = omp_get_wtime();
    printf("Parallel time: %f %f\n", currTime, lastTime);
}

//sequential multiplication
void consistent(int a[100][100], int b[100]) {
    int c[100];
    for (auto &i : c) {
        i = 0;
    }
    double lastTime = omp_get_wtime();
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            c[j] += a[i][j] * b[j];
        }
    }
    double currTime = omp_get_wtime();
    printf("Consistent time: %f %f ", currTime, lastTime);
}

int main() {
    int a[100][100];
    int b[100];
    //Заполнение матрицы
    for (auto &i : a) {
        for (int &j : i) {
            j = rand();
        }
    }
    //vector filling
    for (auto &i : b) {
        i = rand();
    }
    parallel(a, b);
    consistent(a, b);
    return 0;
}