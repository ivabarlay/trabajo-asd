#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int num_procesos;
  int id_proceso;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &id_proceso);
  MPI_Comm_size(MPI_COMM_WORLD, &num_procesos);
  printf("Soy el proceso %d de %d: !Hola mundo!\n", id_proceso, num_procesos);

  MPI_Finalize();

  return (0);
}
