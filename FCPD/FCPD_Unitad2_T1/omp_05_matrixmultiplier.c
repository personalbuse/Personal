#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 35000000  // Cambiar a 1000 para la otra prueba

int main() {
    int i, j, k;
    double **A, **B, **C;

    // Reserva de memoria
    A = (double**) malloc(N * sizeof(double*));
    B = (double**) malloc(N * sizeof(double*));
    C = (double**) malloc(N * sizeof(double*));
    for (i = 0; i < N; i++) {
        A[i] = (double*) malloc(N * sizeof(double));
        B[i] = (double*) malloc(N * sizeof(double));
        C[i] = (double*) malloc(N * sizeof(double));
    }

    // Inicialización con valores simples
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            A[i][j] = 1.0;
            B[i][j] = 2.0;
            C[i][j] = 0.0;
        }

    double start, end;

    // Secuencial
    start = omp_get_wtime();
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            for (k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
    end = omp_get_wtime();
    printf("Tiempo secuencial: %f segundos\n", end - start);

    // Paralelo
    start = omp_get_wtime();
    #pragma omp parallel for private(j, k) shared(A, B, C)
    for (i = 0; i < N; i++) {
        int tid = omp_get_thread_num();
        printf("Fila %d procesada por hilo %d\n", i, tid);
        for (j = 0; j < N; j++)
            for (k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
    }
    end = omp_get_wtime();
    printf("Tiempo paralelo: %f segundos\n", end - start);

    // Liberar memoria
    for (i = 0; i < N; i++) {
        free(A[i]); free(B[i]); free(C[i]);
    }
    free(A); free(B); free(C);

    return 0;
}
