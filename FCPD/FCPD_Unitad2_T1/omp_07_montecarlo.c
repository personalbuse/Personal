#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

#define N 100000000  // Total de puntos

int main() {
    long long i, count = 0;

    double start = omp_get_wtime();

    #pragma omp parallel
    {
        unsigned int seed = omp_get_thread_num();
        long long local_count = 0;

        #pragma omp for
        for (i = 0; i < N; i++) {
            double x = (double) rand_r(&seed) / RAND_MAX;
            double y = (double) rand_r(&seed) / RAND_MAX;
            if (x*x + y*y <= 1.0)
                local_count++;
        }

        #pragma omp atomic
        count += local_count;
    }

    double pi = 4.0 * (double) count / (double) N;

    double end = omp_get_wtime();

    printf("Estimacion de PI = %f\n", pi);
    printf("Tiempo: %f segundos\n", end - start);

    return 0;
}
