#include <stdio.h>
#include <stdint.h>



typedef struct movie {
    char *title;
    uint8_t rating;
    uint16_t release_year;
} Movie;


int main(){

    printf("%d\n",sizeof(Movie));

    return 0;
}
