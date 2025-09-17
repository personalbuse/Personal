/**
 * @title "Array Access with Pointers"
 * @author "David Burbano Mariño"
 * @description "This program initializes an integer array and prints its elements using pointer arithmetic."
 */

#include <stdio.h>

int main() {
    int arr[10];
    int *ptr = arr;

    for (int i = 0; i < 10; i++) {
        *(ptr + i) = i + 1;
    }

    printf("Valores del arreglo:\n");
    for (int i = 0; i < 10; i++) {
        printf("Elemento %d: %d\n", i, *(ptr + i));
    }

    return 0;
}

