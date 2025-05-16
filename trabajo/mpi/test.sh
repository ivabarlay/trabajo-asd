#!/bin/bash
RUNNER=(mpirun -np 4)
SRC_FOLDER="./results"

# Check if argument is passed

if [[ -z "$1" ]]; then
    samples=10000000
else
    samples=$@
fi

# Check if results directory exits, then create it if it is not

if [ ! -d "$DIRECTORY" ]; then
    mkdir ${SRC_FOLDER}
fi

# Create csv
echo "method,implementation,threads,time (s),pi_value,samples" > ${SRC_FOLDER}/mpi_result.csv
# echo "method,implementation,threads,time (s),pi_value" > ${SRC_FOLDER}/mpi_mcpi.csv

# Compile everything
make bear

# PI MPI

for SAMPLE in ${samples}
do
    echo "$SAMPLE"
    ${RUNNER[@]} ./bin/pi_par $SAMPLE >> ${SRC_FOLDER}/mpi_result.csv
    ${RUNNER[@]} ./bin/mcpi_par $SAMPLE >> ${SRC_FOLDER}/mpi_result.csv
done


