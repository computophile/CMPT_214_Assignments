//
// Created by Mark Eramian on 2020-10-26.
//

#include "randomindex.h"
#include <time.h>
#include <stdlib.h>

static int initialized = 0;
/*
 * Initialize the random index generator.  Must be called before random_index().
 */
void init_random() {
    srand(time(NULL));
}

/*
 * Return a random integer between 0 and n-1.
 */
unsigned int random_index(unsigned int n) {
    if(!initialized) {
        init_random();
        initialized = 1;
    }
    return (unsigned int) rand() % n;
}

