#!/bin/bash
SRC_FOLDER="./results"

# Check if argument is passed

if [[ -z "$1" ]]; then
    samples=10000000
else
    samples=$1
    samples_list=()
    samples_tens=10

    # Generates a list of numbers starting at 10, ending
    # at the nearest 10th power less than the argument
    while [[ $samples_tens -le $samples ]]; do
        samples_list+=("$samples_tens")
        (( samples_tens= samples_tens * 10 ))
    done
    samples=${samples_list[@]}
fi

# Check if number of threads is passed

if [[ -z "$2" ]]; then
    threads=4
else
    # Generate a list beggining from 1 and ending in the number of threads
    threads=$2
    threads_list=()
    for ((i = 1; i <= ${threads}; i++)); do
        threads_list+=("$i")
    done
    threads=${threads_list[@]}
    
fi

# Check if results directory exits, then create it if it is not

if [ ! -d "$SRC_FOLDER" ]; then
    mkdir ${SRC_FOLDER}
fi

# Create csv
echo "method,implementation,threads,time (s),pi_value,samples" > ${SRC_FOLDER}/mpi_result.csv
# echo "method,implementation,threads,time (s),pi_value" > ${SRC_FOLDER}/mpi_mcpi.csv

# Compile everything
make

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


