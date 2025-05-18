#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    double x, pi, sum = 0.0;
    long long numSteps;
    double step;
    int i;
    double start, end;
    int size;
    int num_threads;

    if (argc > 2)
        num_threads = atoll(argv[2]);
    else {
        num_threads = 4;
    }

    if (argc > 1)
        numSteps = atoll(argv[1]);
    else {
        numSteps = 1000000;
    }

    step = 1.0 / (double)numSteps;

    /* omp_set_num_threads(num_threads); */

    start = omp_get_wtime();


#pragma omp parallel num_threads(num_threads) private(x, i) reduction(+ : sum)
    size = omp_get_num_threads();
    /* printf("%d", size); */
    {
#pragma omp for
        for (i = 0; i < numSteps; ++i) {
            x = (i + 0.5) * step;
            sum += 4.0 / (1.0 + x * x);
        }
    }

    pi = step * sum;

    end = omp_get_wtime();
    printf("Integration,OMP,%d,%f,%f,%f,%lld\n", size, end - start, pi, fabs(M_PI - pi), numSteps);
    return 0;
}
