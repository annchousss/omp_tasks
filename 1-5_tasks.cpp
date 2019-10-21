#include <iostream>
#include "omp.h"

void prog1();
void prog2();
void prog3();
void prog4();
void prog5();

int main() {

}

void prog1() {
    omp_set_num_threads(8);
    #pragma omp parallel
    {
        std::cout << "Total " << omp_get_num_threads() << " Proc " << omp_get_thread_num() << " Hello World!\n";
    }
}

void prog2() {
    omp_set_num_threads(3);
    int x = omp_get_num_threads();
#pragma omp parallel if(x)
    if(omp_get_num_threads() > 1) {
        std::cout << " Total "<< omp_get_num_threads() <<" Proc" << omp_get_thread_num();
    }
    omp_set_num_threads(1);
#pragma omp parallel if(x)
    if(omp_get_num_threads() > 1) {
        std::cout << " Total "<< omp_get_num_threads() <<" Proc" << omp_get_thread_num();
    }
}

void prog3() {
    int a = 2;
    int b = 4;
    std::cout << "a=" << a << " b=" << b << "\n";
    omp_set_num_threads(2);
#pragma omp parallel private(a), firstprivate(b)
    {
        a = 2;
        std::cout << " Proc " << omp_get_thread_num() << "\n";
        a += omp_get_thread_num();
        b += omp_get_thread_num();
        std::cout << "a=" << a << " b=" << b << "\n";
    }
    std::cout << "a = " << a << " b = " << b << "\n";
#pragma omp parallel shared(a), private(b)
    {
        b = 4;
        std::cout << " Proc " << omp_get_thread_num() << "\n";
        a -= omp_get_thread_num();
        b -= omp_get_thread_num();
        std::cout << "a = " << a << "b = " << b << "\n";
    }
}

void prog4() {
    int threadId;
    int a[] = {1, 12, 4, 5, 78, 6, 8, 3, 70, 43};
    int b[] = {8, 2, 3, 6, 1, 5, 12, 9, 10, 70};
    int min = 10000;
    int max = -10000;
    omp_set_num_threads(2);
#pragma omp parallel
    {
        threadId = omp_get_thread_num();
        if (threadId == 0) {
            for (int i = 0; i < 10; i++) {
                if(a[i] < min)
                    min = a[i];
            }
        } else {
            for (int i = 0; i < 10; i++) {
                if(a[i] > max)
                    max = a[i];
            }
        }
    }
    std::cout << "Min = " << min << "\n";
    std::cout << "Max = " << max << "\n";
}

void prog5() {
    int d[6][8];

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 8; j++) {
            d[i][j] = ((rand() % 10));
            std::cout « d[i][j] « " ";
        }
    std::cout « std::endl;
#pragma omp parallel sections
    {
#pragma omp section
        {
            float sum = 0;
            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 8; j++)
                    sum = sum + d[i][j];
            printf("avg = %f\n", sum / (6 + 8));
        }
#pragma omp section
        {
            int max = d[0][0];
            int min = d[0][0];

            for (int i = 0; i < 6; ++i)
            {
                for (int j = 0; j < 8; ++j)
                {
                    if (d[i][j] > max) max = d[i][j];
                    if (d[i][j] < min) min = d[i][j];
                }
            }
            printf("max = %d, min = %d\n", max, min);
        }
#pragma omp section
        {
            for (int i = 0; i < 6; ++i) {
                for (int j = 0; j < 8; ++j) {
                    if (d[i][j] % 3 == 0) {
                        printf("%d", d[i][j]);
                    }
                }
            }
        }
    }
}
