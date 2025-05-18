#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int i;
    double x, pi, sum = 0.0;
    unsigned long long numSteps;
    double step;
    clock_t begin = clock();

    if (argc > 1)
        numSteps = atoll(argv[1]);
    else {
        numSteps = 1000000;
    }
    step = 1.0 / (double)numSteps;

    for (i = 0; i < numSteps; ++i) {
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    pi = step * sum;

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Integration,SERIAL,%d,%f,%f,%f,%lld\n", 1, time_spent, pi,fabs(M_PI - pi),
           numSteps);
    return 0;
}
