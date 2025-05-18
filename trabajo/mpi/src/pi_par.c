#include <math.h>
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int i;
    double x, pi, sum = 0.0;
    /* long numSteps = atol(argv[1]); */
    long long numSteps;
    double step;
    long partition;
    double start, end;

    if (argc > 1)
        numSteps = atoll(argv[1]);
    else {
        numSteps = 1000000;
    }
    step = 1.0 / (double)numSteps;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0) {
        start = MPI_Wtime();
    }

    partition = (long)(numSteps / size);

    /* printf("rank: %d\n", rank); */
    /* printf("size: %d\n", size); */
    /* printf("partition: %ld\n", partition); */

    for (i = rank * partition; i < rank * partition + partition; ++i) {
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }

    MPI_Reduce(&sum, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        end = MPI_Wtime();
        pi = pi * step;
        /* printf("Valor de pi: %f\n", pi); */
        printf("Integration,MPI,%d,%f,%f,%f,%lld\n", size, end - start, pi,
               fabs(M_PI - pi), numSteps);
    }
    MPI_Finalize();
    return 0;
}
