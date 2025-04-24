#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int mi_rango;      // rango de mi proceso
  int p;             // numero de procesos
  int fuente;        // rango del emisor
  int dest;          // rango del destinatario
  int etiqueta = 0;  // etiqueta para los mensajes
  char mensaje[100]; // almacenamiento para el mensaje
  MPI_Status status; // devuelve el status para el receptor

  MPI_Init(&argc, &argv); // Inicializa MPI

  MPI_Comm_rank(MPI_COMM_WORLD, &mi_rango);

  MPI_Comm_size(MPI_COMM_WORLD, &p);

  /* Crea mensaje */
  dest = (mi_rango + 1) % p;
  fuente = (mi_rango - 1 + p) % p;
  sprintf(mensaje, "Saludos desde el proceso %d al proceso %d!", mi_rango,
          dest);
  /* Usa strlen+1 para que '\0' sea transmitido */
  MPI_Send(mensaje, strlen(mensaje) + 1, MPI_CHAR, dest, etiqueta,
           MPI_COMM_WORLD);
  MPI_Recv(mensaje, 100, MPI_CHAR, fuente, etiqueta, MPI_COMM_WORLD, &status);
  printf("%s\n", mensaje);

  MPI_Finalize(); // Cierra el universo MPI
  return MPI_SUCCESS;
} // main
