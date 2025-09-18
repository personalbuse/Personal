/**
 * ejercicio_pd_1.c: 
 * 
 * authority: Andres Felipe Jaimes Muñoz
 * 
 * Description: Generate an array of random numbers and find how many are prime,
* using global constants, standard libraries, and function documentation.
 * 
 * Input: Array size.
 *
 */

#include <stdio.h>   // data input and output.
#include <stdlib.h>  // Generate random numbers.
#include <time.h>    // the numbers change on each run.


#define max_num 100 

void fill_array(int array[], int size);
void print_array(int array[], int size);
int es_primo(int num);
int count_primos (int array[],int size);

int main(void) {
    int size_array;

    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &size_array);

    while (size_array <= 0) {
        printf("Error: el tamaño debe ser mayor que 0.\n");
        printf("Ingrese nuevamente el tamaño del arreglo: ");
        scanf("%d", &size_array);
    }

    int counter = 0;
    int array_num_random[size_array];

    srand(time(NULL)); 

    fill_array(array_num_random, size_array);
    print_array(array_num_random, size_array);
    
    int primos = count_primos(array_num_random, size_array);
    printf("Cantidad de numeros primos en el arreglo: %d\n", primos);

    return 0; 
}

// Function implementation

void fill_array(int array[], int size) {//fill the array
    for (int i = 0; i < size; i++) {
        array[i] = rand() % max_num;
    }
}

void print_array(int array[], int size) { //prin the array
    printf("Array de numeros aleatorios:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int es_primo(int num){ //returns 0 if it is prime and 1 if it is not prime
    if(num<2) return 0;
    for(int i = 2; i*i <= num; i++){
        if(num % i == 0) return 0;
    }
        return 1;
}

int count_primos(int array[], int size){//prime counter function

    int count =0;
    for(int i =0; i < size; i++){
        if(es_primo(array[i])) count++;
    }
    return count;
}
