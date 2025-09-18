/**
 * @title "Swap Values with Pointers"
 * @author "David Burbano Mariño"
 * @description "This program defines and tests a function that swaps the values of two integer variables using pointers."
 */

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1 = 10;
    int num2 = 20;
    printf("Valores originales: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("Valores intercambiados: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}