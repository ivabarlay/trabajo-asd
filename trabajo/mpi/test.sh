#!/bin/bash
runner=(mpirun -np 4)
if [[ -z "$1" ]]
then
    samples=10000000
else
    samples=$1
fi

# Crear csv
echo "method,implementation,threads,time (s),pi_value" > mpi_pi.csv
echo "method,implementation,threads,time (s),pi_value" > mpi_mcpi.csv

# Compilar todo
make

# PI MPI
${runner[@]} ./bin/pi_par $1 >> mpi_pi.csv
${runner[@]} ./bin/mcpi_par $1 >> mpi_mcpi.csv



