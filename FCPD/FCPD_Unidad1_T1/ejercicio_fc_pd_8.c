/*
file: ejercicio_fc_pd_8.c
author: David Burbano Mariño
description: Program that assigns a letter grade based on a numeric score
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int nota;
    printf("Ingrese una nota entre 0 y 100: ");
    scanf("%d", &nota);

    if (nota < 0 || nota > 100) {
        printf("Nota fuera de rango.\n");
        return 0;
    }

    switch (nota / 10) {
        case 10:
        case 9:
            printf("Calificación: A\n");
            break;
        case 8:
            printf("Calificación: B\n");
            break;
        case 7:
            printf("Calificación: C\n");
            break;
        case 6:
            printf("Calificación: D\n");
            break;
        default:
            printf("Calificación: F\n");
            break;
    }
    return 0;
}
