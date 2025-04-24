/*
 * Algoritmo serie de Monte Carlo para estimar el valor de pi
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>

int main (int argc, char *argv[]) {
  unsigned short xi[3];
  unsigned long long count = 0;
  unsigned long long i;
  unsigned long long samples;
  double x, y;
  struct drand48_data buffer;
  samples=3000000; /*Valor por defecto*/

  if (argc >1)
    samples = atoi(argv[1]);
    
# pragma omp parallel private(i, xi, buffer)
  {
      xi[0] = xi[1] = xi[2] = omp_get_thread_num();
      memset(&buffer, 0, sizeof(buffer));
# pragma omp parallel for reduction(+:count)
      for (int i = 0; i < samples; ++i) {
          erand48_r(xi, &buffer, &x);
          erand48_r(xi, &buffer, &y);
          if (x*x+y*y <= 1.0) {
              ++count;
          }
      }
  }

  printf ("Valor estimado de pi:  %.7f\n", 4.0*count/samples);
  return 0;
}
