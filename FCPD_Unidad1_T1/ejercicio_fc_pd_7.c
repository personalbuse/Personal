/*
file: ejercicio_fc_pd_7.c
author: David Burbano Mariño
description: Program that creates a square matrix with random numbers, 
             calculates the sum of the main and secondary diagonals, 
             and determines which one is greater.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d", &n);

    int matriz[n][n];
    int suma_principal = 0, suma_secundaria = 0;

    srand(1);

    printf("\nMatriz generada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100;
            printf("%3d ", matriz[i][j]);

            if (i == j) {
                suma_principal += matriz[i][j];
            }
            if (i + j == n - 1) {
                suma_secundaria += matriz[i][j];
            }
        }
        printf("\n");
    }

    printf("\nSuma diagonal principal: %d\n", suma_principal);
    printf("Suma diagonal secundaria: %d\n", suma_secundaria);

    if (suma_principal > suma_secundaria) {
        printf("La diagonal principal tiene mayor suma.\n");
    } else if (suma_secundaria > suma_principal) {
        printf("La diagonal secundaria tiene mayor suma.\n");
    } else {
        printf("Ambas diagonales tienen la misma suma.\n");
    }

    return 0;
}
