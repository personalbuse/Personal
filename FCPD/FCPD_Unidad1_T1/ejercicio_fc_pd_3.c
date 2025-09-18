/**
 * ejercicio_pd_3.c: 
 * 
 * authority: Andres Felipe Jaimes Muñoz
 * 
 * Description: Determine the largest and smallest
 * of three numbers, Practicing ternary operators and functions
 * 
 * Input: three integers
 * Output: The largest and smallest number.
 *
 */

// Librerias
#include <stdio.h>   // data input and output.


// Prototypes
int higher  (int x, int y, int z);
int less  (int x, int y, int z);

// Main
int main(void) {
    int x,y,z;

    printf("Ingrese el primer numero: ");
    scanf("%d", &x);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &y);

    printf("Ingrese el tercer numero: ");
    scanf("%d", &z);

   printf("\nx=%d, y=%d, z=%d\n",x,y,z);

   int max=higher(x,y,z);
   int min=less(x,y,z);

   printf("el numero mayor es %d\n",max);
   printf("el numero menor es %d\n",min);

    return 0; 
}

// Function implementation

int higher (int x,int y, int z) {//higher
   int max_xy=(x > y) ? x : y;
   return (max_xy > z) ? max_xy : z;   
}

int less (int x,int y, int z) {//less
   int min_xy=(x < y) ? x : y;
   return (min_xy < z) ? min_xy : z;   
}
