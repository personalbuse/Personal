/**
 * @title "Optimized Parallel Matrix Multiplication"
 * @author "David Burbano Mariño"
 * @description "This program multiplies two large square matrices using an optimized parallel algorithm with OpenMP, featuring loop interchange (i-k-j) for superior cache performance."
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define N 1024

int** crear_matriz();
void inicializar_matriz(int** mat);
void liberar_memoria(int** mat);

int main() {
    int **A, **B, **C_par;
    double start_time, end_time;

    A = crear_matriz();
    B = crear_matriz();
    C_par = crear_matriz();

    srand(time(NULL));
    inicializar_matriz(A);
    inicializar_matriz(B);

    printf("--- Multiplicación Paralela Optimizada (Algoritmo i-k-j) ---\n");
    start_time = omp_get_wtime();

    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            int temp = A[i][k];
            for (int j = 0; j < N; j++) {
                C_par[i][j] += temp * B[k][j];
            }
        }
    }
    
    end_time = omp_get_wtime();

    printf("Tamaño de la matriz: %d x %d\n", N, N);
    printf("Tiempo de ejecución: %f segundos\n", end_time - start_time);

    liberar_memoria(A);
    liberar_memoria(B);
    liberar_memoria(C_par);

    return 0;
}

int** crear_matriz() {
    int **mat = (int **)malloc(N * sizeof(int *));
    for(int i = 0; i < N; i++) {
        mat[i] = (int *)calloc(N, sizeof(int));
    }
    return mat;
}

void inicializar_matriz(int **mat) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = rand() % 10;
        }
    }
}

void liberar_memoria(int **mat) {
    for(int i = 0; i < N; i++) {
        free(mat[i]);
    }
    free(mat);
}