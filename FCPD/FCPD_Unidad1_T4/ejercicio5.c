/**
 * @title "String Traversal with Pointers"
 * @author "David Burbano Mariño"
 * @description "This program iterates through a character string using a pointer, printing each character and its memory address."
 */

#include <stdio.h>

int main() {
    char cadena[] = "Fundamentos";
    char *ptr = cadena;

    printf("Recorriendo la cadena con punteros:\n");
    while (*ptr != '\0') {
        printf("Caracter: '%c' | Dirección de memoria: %p\n", *ptr, (void *)ptr);
        ptr++;
    }

    return 0;
}