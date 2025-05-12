#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  double x, pi, sum = 0.0;
  long numSteps = atol(argv[1]);
  double step = 1.0 / (double)numSteps;
  int i;
#pragma omp parallel private(x, i) reduction(+ : sum)
  {
#pragma omp for
    for (i = 0; i < numSteps; ++i) {
      x = (i + 0.5) * step;
      sum += 4.0 / (1.0 + x * x);
    }
  }

  pi = step * sum;
  printf("Valor de pi: %f\n", pi);
  return 0;
}
