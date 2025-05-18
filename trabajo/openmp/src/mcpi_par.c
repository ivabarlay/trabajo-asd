/*
 * Algoritmo serie de Monte Carlo para estimar el valor de pi
 */

#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    unsigned short xi[3];
    unsigned long long count = 0;
    unsigned long long i;
    unsigned long long samples;
    double x, y, pi;
    int size;
    double start, end;
    int num_threads;
    struct drand48_data buffer;

    if (argc > 2)
        num_threads = atoll(argv[2]);
    else {
        num_threads = 4;
    }

    if (argc > 1)
        samples = atoll(argv[1]);
    else {
        samples = 1000000;
    }

    omp_set_num_threads(num_threads);
    start = omp_get_wtime();

#pragma omp parallel private(i, xi, buffer)
    {
        size = omp_get_num_threads();
        xi[0] = xi[1] = xi[2] = omp_get_thread_num();
        memset(&buffer, 0, sizeof(buffer));
#pragma omp parallel for reduction(+ : count)
        for (int i = 0; i < samples; ++i) {
            erand48_r(xi, &buffer, &x);
            erand48_r(xi, &buffer, &y);
            if (x * x + y * y <= 1.0) {
                ++count;
            }
        }
    }

    end = omp_get_wtime();

    pi = 4.0 * count / samples;

    printf("Monte Carlo,OMP,%d,%f,%f,%f,%lld\n", size, end - start, pi,
           fabs(M_PI - pi), samples);
    return 0;
}
