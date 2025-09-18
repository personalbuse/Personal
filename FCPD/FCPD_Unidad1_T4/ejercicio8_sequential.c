/**
 * @title "Sequential Matrix Multiplication"
 * @author "David Burbano Mariño"
 * @description "This program multiplies two large square matrices using the standard sequential i-j-k algorithm and measures its execution time."
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1024

int** crear_matriz();
void inicializar_matriz(int** mat);
void liberar_memoria(int** mat);

int main() {
    int **A, **B, **C;
    clock_t start_time, end_time;

    A = crear_matriz();
    B = crear_matriz();
    C = crear_matriz();

    srand(time(NULL));
    inicializar_matriz(A);
    inicializar_matriz(B);

    printf("--- Multiplicación Secuencial (Algoritmo i-j-k) ---\n");
    start_time = clock();
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    end_time = clock();
    
    double tiempo_total = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Tamaño de la matriz: %d x %d\n", N, N);
    printf("Tiempo de ejecución: %f segundos\n", tiempo_total);

    liberar_memoria(A);
    liberar_memoria(B);
    liberar_memoria(C);

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