#!/bin/bash
RUNNER=(mpirun -np 4)
SRC_FOLDER="./results"

# Check if argument is passed

if [[ -z "$1" ]]
then
    samples=10000000
else
    samples=$1
fi

# Check if results directory exits, then create it if it is not

if [ ! -d "$DIRECTORY" ]; then
    mkdir ./results
fi

# Create csv
echo "method,implementation,threads,time (s),pi_value" > ${SRC_FOLDER}/mpi_pi.csv
echo "method,implementation,threads,time (s),pi_value" > ${SRC_FOLDER}/mpi_mcpi.csv

# Compile everything
make bear

# PI MPI
${RUNNER[@]} ./bin/pi_par $1 >> ${SRC_FOLDER}/mpi_pi.csv
${RUNNER[@]} ./bin/mcpi_par $1 >> ${SRC_FOLDER}/mpi_mcpi.csv



