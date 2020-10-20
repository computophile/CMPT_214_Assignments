#include <stdio.h>
#include <stdlib.h>

void dostuff(double *x, size_t length_x) {
    for(int k=0; k < length_x; k = k+1) {
        x[ k ] = 9.0/5.0 * x[ k ] + 32.0;
    }
}

int main() {
    const size_t len_t = 5;
    double *t = malloc(len_t*sizeof(int));

    // ... code to initialize t omitted ...
    t[2] = 18.0;
    dostuff(t, len_t);

    printf("%lf\n", t[2]);

    free(t);
}