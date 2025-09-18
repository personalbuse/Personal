/*
file: ejercicio_fc_pd_6.c
author: Daniel
description: Program that inverts the elements of an integer array 
             using pointers and prints the result.
*/

#include <stdio.h>

void invert(int *array, int n) {
    int *first = array;        
    int *last = array + n - 1;   
    int aux;

    while (first < last) {
        aux = *first;
        *first = *last;
        *last = aux;

        first++;
        last--;
    }
}

void print_array(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("[%d]", *(array + i));
    }
    printf("\n");
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Arreglo original:\n");
    print_array(array, n);

    invert(array, n);

    printf("Arreglo invertido:\n");
    print_array(array, n);

    return 0;
}
