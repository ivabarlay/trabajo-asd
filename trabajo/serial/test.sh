#!/bin/bash
SRC_FOLDER="./results"

# Check if argument is passed

if [[ -z "$1" ]]; then
    samples=10000000
else
    samples=$1
    # samples_list=()
    # samples_tens=10
    #
    # # Generates a list of numbers starting at 10, ending
    # # at the nearest 10th power less than the argument
    # while [[ $samples_tens -le $samples ]]; do
    #     samples_list+=("$samples_tens")
    #     (( samples_tens= samples_tens * 10 ))
    # done
    # samples=${samples_list[@]}
fi

# Check if results directory exits, then create it if it is not

if [ ! -d "$SRC_FOLDER" ]; then
    mkdir ${SRC_FOLDER}
fi

# Create csv
echo "method,implementation,threads,time (s),pi_value,error,samples" > ${SRC_FOLDER}/serial_result.csv
# echo "method,implementation,threads,time (s),pi_value" > ${SRC_FOLDER}/mpi_mcpi.csv

# Compile everything
make

# PI MPI

echo "Número de iteraciones: " ${samples}
./bin/pi_serie ${samples} >> ${SRC_FOLDER}/serial_result.csv
./bin/mcpi_serial ${samples} >> ${SRC_FOLDER}/serial_result.csv
