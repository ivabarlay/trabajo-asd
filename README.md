# trabajo-asd
Trabajo de la asignatura ASD

## Makefile

Instalar <em>make<em>.
En linux, ejecutar `$ sudo apt install make`.

<-Instrucciones para usar el Makefile:
- Para compilar todo: `$ make`
- Para borrar los archivos creados: `$ make clean`
- Para ejecutar bear (opcional), usar: `$ make bear`

## Ejecución

Instalar **mpi**:

- `$ sudo apt install openmpi-bin`

Sobre los ejecutables, una vez compilado:

- `$ mpirun -np <númeroProcesos> <fichero>`
