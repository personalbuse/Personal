/** 
 * @title "Ejercicio 7 - Producto Escalar Secuencial"
 * @author "David Burbano Mariño"
 * @description "Implementación del producto escalar de dos vectores de tamaño N de forma secuencial."
 */

#include <stdio.h>
#include <stdlib.h>
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

    clock_t start_time = clock();  

    for (int i = 0; i < N; i++) {
        result += A[i] * B[i];
    }

    clock_t end_time = clock();  

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;  
    printf("Producto escalar secuencial: %f\n", result);
    printf("Tiempo de ejecución secuencial: %f segundos\n", time_taken);

    free(A);
    free(B);

    return 0;
}
