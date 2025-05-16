#!/bin/bash
runner=(mpirun -np 4)

# Crear csv
echo "method,implementation,threads,time (s),pi_value,error" > mpi_pi.csv

# Compilar todo
make

# PI MPI
${runner[@]} ./bin/pi_par 1000 >> mpi_pi.csv



