/**
 * @title "Sequential vs Parallel Array Sum"
 * @author "David Burbano Mariño"
 * @description "This program calculates the sum of a large array's elements sequentially and then in parallel using OpenMP, comparing their execution times."
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main() {
    int *arr = (int *)malloc(N * sizeof(int));
    long long suma_sec = 0;
    long long suma_par = 0;
    double start_time, end_time;

    for (int i = 0; i < N; i++) {
        arr[i] = 1;
    }

    start_time = omp_get_wtime();
    for (int i = 0; i < N; i++) {
        suma_sec += arr[i];
    }
    end_time = omp_get_wtime();
    printf("--- Versión Secuencial ---\n");
    printf("Suma: %lld\n", suma_sec);
    printf("Tiempo de ejecución: %f segundos\n\n", end_time - start_time);
        
    /*
    #pragma omp parallel
    for (int i = 0; i < N; i++) {
        arr[i] = 1;
    }
    start_time = omp_get_wtime();
    #pragma omp parallel for reduction(+:suma_par)
    for (int i = 0; i < N; i++) {
        suma_par += arr[i];
    }
    end_time = omp_get_wtime();
    printf("--- Versión Paralela (OpenMP) ---\n");
    printf("Suma: %lld\n", suma_par);
    printf("Tiempo de ejecución: %f segundos\n", end_time - start_time);
    */

    free(arr);
    return 0;
}