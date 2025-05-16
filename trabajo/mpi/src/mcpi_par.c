/*
 * Algoritmo serie de Monte Carlo para estimar el valor de pi
 */

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  /* unsigned short xi[3] = {1, 2, 3}; */
  unsigned long long count = 0;
  unsigned long long i;
  unsigned long long samples;
  double x, y;
  struct drand48_data buffer;
  int rank, size;
  long long sum_count;
  double num_final;
  long long partition;
  samples = 1000000; /*Valor por defecto*/

  if (argc > 1)
    samples = atoll(argv[1]);

  double start, end;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  if (rank == 0) {
	start = MPI_Wtime();
  }

  partition = (long) (samples / size);

  unsigned short xi[3] = {rank, rank + 1, rank + 2};


  /* printf("partition: %ld\n", partition); */
  /* printf("samples: %lld\n", samples); */
  /* printf("size: %d\n", size); */
  for (i = rank * partition; i < rank*partition + partition; ++i) {
    /* x = erand48(xi); */
    /* y = erand48(xi); */
    erand48_r(xi, &buffer, &x);
    erand48_r(xi, &buffer, &y);
    if (x * x + y * y <= 1.0) {
      ++count;
    }
  }

  MPI_Reduce(&count, &sum_count, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  if (rank == 0) {
    end = MPI_Wtime();
    num_final = 4.0 * sum_count / samples;
    /* printf("Valor estimado de pi:  %.7f\n", num_final); */
    printf("Monte Carlo,MPI,%d,%f,%f\n", size, end - start, num_final);
  }
  MPI_Finalize();
  return 0;
}
