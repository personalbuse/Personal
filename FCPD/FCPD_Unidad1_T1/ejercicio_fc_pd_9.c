/*
file: ejercicio_fc_pd_9.c
author: David Burbano Mariño
description: Program that creates a dynamic array, fills it with user values, 
             calculates the total sum, and frees the allocated memory.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr, suma = 0;

    printf("Ingrese el número de elementos: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error: no se pudo reservar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
        suma += arr[i];
    }

    printf("\nLa suma total de los elementos es: %d\n", suma);

    free(arr);

    return 0;
}
