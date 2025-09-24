#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define N 50000000

int main() {
    double *arr = (double*) malloc(N * sizeof(double));
    long long i;

    // Inicializar con números aleatorios entre 0 y 1
    for (i = 0; i < N; i++) {
        arr[i] = (double) rand() / RAND_MAX;
    }

    double mean = 0.0, var = 0.0, stddev = 0.0;

    double start = omp_get_wtime();

    // Promedio con reducción
    #pragma omp parallel for reduction(+:mean)
    for (i = 0; i < N; i++) {
        mean += arr[i];
    }
    mean /= N;

    // Varianza
    #pragma omp parallel for reduction(+:var)
    for (i = 0; i < N; i++) {
        var += (arr[i] - mean) * (arr[i] - mean);
    }
    var /= N;
    stddev = sqrt(var);

    double end = omp_get_wtime();

    printf("Promedio: %f\n", mean);
    printf("Desviacion estandar: %f\n", stddev);
    printf("Tiempo total: %f segundos\n", end - start);

    free(arr);
    return 0;
}
