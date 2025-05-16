#!/bin/bash
runner=(mpirun -np 4)

# Crear csv
echo "method,implementation,threads,time (s),pi_value" > mpi_pi.csv

# Compilar todo
make

# PI MPI
${runner[@]} ./bin/pi_par >> mpi_pi.csv



