/** 
 * @title "Ejercicio 7 - Producto Escalar Paralelo con OpenMP"
 * @author "David Burbano Mariño"
 * @description "Implementación del producto escalar de dos vectores de tamaño N con paralelización utilizando OpenMP y reducción."
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main() {
    int N = 1000000;
    double *A = (double*)malloc(N * sizeof(double));
    double *B = (double*)malloc(N * sizeof(double));
    double result = 0.0;

    for (int i = 0; i < N; i++) {
        A[i] = 1.0;
        B[i] = 2.0;
    }

    double start_time = omp_get_wtime(); 

    #pragma omp parallel reduction(+:result)
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        printf("Hilo %d de %d hilos está participando en el cálculo.\n", thread_id, num_threads);

        #pragma omp for
        for (int i = 0; i < N; i++) {
            result += A[i] * B[i];
        }
    }

    double end_time = omp_get_wtime(); 

    double time_taken = end_time - start_time; 
    printf("Producto escalar paralelo: %f\n", result);
    printf("Tiempo de ejecución paralelo: %f segundos\n", time_taken);

    free(A);
    free(B);

    return 0;
}
