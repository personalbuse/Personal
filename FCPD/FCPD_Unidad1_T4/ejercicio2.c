/**
 * @title "Sum of Array Elements with Pointers"
 * @author "David Burbano Mariño"
 * @description "This program calculates the sum of all elements in an integer array using pointers."
 */

#include <stdio.h>

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr = arr;
    int suma = 0;

    for (int i = 0; i < 10; i++) {
        suma += *(ptr + i);
    }

    printf("La suma de los elementos del arreglo es: %d\n", suma);

    return 0;
}