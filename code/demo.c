#include <stdio.h>
#include <stdint.h>



typedef struct movie {
    char *title;
    uint8_t rating;
    uint16_t release_year;
} Movie;


/* Program2.c */ 
int main() 
{ 
    char chr = 'Z'; 
 
    char *p1 = "Hello"; 
 
    p1 = &chr; // OK: Value of p1 can be changed 
 
    int array[4][5];

    array[][5] = 20;

    printf("the value of p1: %p", p1);
    return 0; 
} 