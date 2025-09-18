/**
 * ejercicio_pd_2.c: 
 * 
 * authority: Andres Felipe Jaimes Muñoz
 * 
 * Description: Swap the values ​​of two integers using pointers.
 * 
 * Input: two integers
 * Output: exchanged values
 *
 */

// Librerias
#include <stdio.h>   // data input and output.


// Prototypes
void exchange (int *x, int*y);

// Main
int main(void) {
    int x,y;

    printf("Ingrese el primer numero: ");
    scanf("%d", &x);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &y);

   printf("\nAntes del intercambio: x=%d, y=%d\n",x,y);

   exchange(&x, &y);

   printf("\nDespues del intercambio: x=%d, y=%d\n",x,y);

    return 0; 
}

// Function implementation

void exchange(int *a, int *b) {//exchange
    int temp=*a;
    *a=*b;
    *b=temp;
}

