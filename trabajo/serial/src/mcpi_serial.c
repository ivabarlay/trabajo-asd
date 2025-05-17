/*
 * Algoritmo serie de Monte Carlo para estimar el valor de pi
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    unsigned short xi[3] = {1, 2, 3};
    unsigned long long count = 0;
    unsigned long long i;
    unsigned long long samples;
    double x, y, pi;
    clock_t begin = clock();

    if (argc > 1)
        samples = atoll(argv[1]);
    else {
        samples = 1000000;
    }

    for (i = 0; i < samples; ++i) {
        x = erand48(xi);
        y = erand48(xi);
        if (x * x + y * y <= 1.0) {
            ++count;
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    pi = 4.0 * count / samples;

    printf("Monte Carlo,SERIAL,%d,%f,%f,%lld\n", 1, time_spent, pi,
           samples);
    return 0;
}
