#!/bin/bash
SRC_FOLDER="./results"

# Check if argument is passed

if [[ -z "$1" ]]; then
    samples=10000000
else
    samples=$1
fi

# Check if number of threads is passed

if [[ -z "$2" ]]; then
    threads=4
else
    threads=$2
fi

# Check if results directory exits, then create it if it is not

if [ ! -d "$SRC_FOLDER" ]; then
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
    for THREAD in ${threads}
    do
        runner=(mpirun -np ${THREAD})
        echo "Número de iteraciones: " ${SAMPLE}
        echo "Número de hilos: " ${THREAD}
        ${runner[@]} ./bin/pi_par ${SAMPLE} >> ${SRC_FOLDER}/mpi_result.csv
        ${runner[@]} ./bin/mcpi_par ${SAMPLE} >> ${SRC_FOLDER}/mpi_result.csv
    done
done


