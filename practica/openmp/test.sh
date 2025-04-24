#!/bin/sh

echo "Montecarlo serial: "
echo "\n///////////////////"
./bin/mcpi_serial $1
echo "///////////////////\n"

echo "Método de la integral serial: "
echo "\n///////////////////"
./bin/pi_serie $1
echo "///////////////////\n"

echo "Montecarlo paralelo: "
echo "\n///////////////////"
./bin/mcpi_par $1
echo "///////////////////\n"

echo "Método de la integral paralelo: "
echo "\n///////////////////"
./bin/pi_par $1
echo "///////////////////\n"

