/**
 * Написать программу, в которой объявить и присвоить начальные значения целочисленным
 * массивам a[10] и b[10]. Используя конструкцию parallel for и reduction вычислить средние
 * арифметические значения элементов массивов a и b, сравнить полученные значения,
 * результат выдать на экран.
 */

#include <cstdio>
#include <omp.h>

int main() {

    int a[10] = {5, 15, -8, 100, 99, -93, 0, 101, 55, 2};
    int b[10] = {4, 16, -9, 100, 54, -96, 0, 109, 56, 3};
    int sumA = 0;
    int sumB = 0;

#pragma omp parallel for reduction(+:sumA, sumB)
        for (int i = 0; i < 10; i++) {
            sumA += a[i];
            sumB += b[i];
        }
    printf("Average A = %d %s Average B = %d", sumA / 10, (sumA > sumB) ? ">" : "<", sumB / 10);
    return 0;
}
