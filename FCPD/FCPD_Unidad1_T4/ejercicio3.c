/**
 * @title "Matrix with Double Pointers"
 * @author "David Burbano Mariño"
 * @description "This program dynamically allocates a 3x3 matrix using a double pointer (int **), initializes it, and prints its content."
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matriz;
    int filas = 3, columnas = 3;
    matriz = (int **)malloc(filas * sizeof(int *));

    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
    }

    printf("Contenido de la matriz 3x3:\n");
    int contador = 1;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            *(*(matriz + i) + j) = contador++;
            printf("%d\t", *(*(matriz + i) + j));
        }
        printf("\n");
    }

    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}