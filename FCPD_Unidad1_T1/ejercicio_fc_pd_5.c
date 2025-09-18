/*
file: ejercicio_fc_pd_5.c
author: Daniel
description: Program that calculates the sum of digits of an integer 
             using recursion.
*/

#include <stdio.h>
#include <stdlib.h>

int sumaDigitos(int n) {
    if (n < 0) {
        n = abs(n);
    }
    
    if (n < 10) {
        return n;
    }

    int ultimo = n % 10;     
    int resto  = n / 10;     
    return ultimo + sumaDigitos(resto);
}

int main() {
    int n = 705;
    printf("La suma de dígitos de %d es %d\n", n, sumaDigitos(n));
    return 0;
}
