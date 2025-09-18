/*
file: ejercicio_fc_pd_4.c
author: Daniel
description: Program that calculates the factorial of a positive integer 
             and checks if the result is even or odd.
*/

#include <stdio.h>

int factorial(int x);
void parity(int x);

int main() {
    int num;
    printf("Ingrese un número entero positivo: ");
    scanf("%d", &num);

    int result = factorial(num);
    if (result != -1) {
        printf("Factorial: %d\n", result);
        parity(result);
    }

    return 0;
}

int factorial(int x) {
    if (x < 0) {
        printf("No se le puede aplicar factorial a un número negativo.\n");
        return -1;
    }

    int aux = 1;
    for (int i = 1; i <= x; i++) {
        aux *= i;
    }

    return aux;
}

void parity(int x) {
    if (x % 2 == 0) {
        printf("El resultado es par.\n");
    } else {
        printf("El resultado es impar.\n");
    }
}
