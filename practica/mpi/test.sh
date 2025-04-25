#!/bin/sh

echo "Hola mundo avanzado: "
echo "\n///////////////////"
mpirun -np 4 bin/hola_mundo_avanzado
echo "///////////////////\n"

echo "saludos: "
echo "\n///////////////////"
mpirun -np 4 bin/saludos
echo "///////////////////\n"

echo "Saludos en anillo: "
echo "\n///////////////////"
mpirun -np 4 bin/saludos_anillo
echo "///////////////////\n"
