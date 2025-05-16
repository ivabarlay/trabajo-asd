# trabajo-asd
Trabajo de la asignatura ASD

## Partes

Cada parte del trabajo está en su propia carpeta.
Dentro de éstas están tanto el código como los Makefiles.

## Makefile

Instalar <em>make<em>.
En linux, ejecutar `$ sudo apt install make`.

<-Instrucciones para usar el Makefile:
- Para compilar todo: `$ make`
- Para borrar los archivos creados: `$ make clean`
- Para ejecutar bear (opcional) y crear compile_commands.json, usar: `$ make bear`

## Ejecución

### General
- Ejecutar script de test:  `./test.sh`. Se pueden añadir pruebas con diferentes iteraciones introduciendo los números seguidos del comando.
- Ejecutar script de limpieza: `./clean.sh`

### OPENMP

- Instalar libreria de omp para gcc:  `$ sudo apt install libgomp1`
- Opcionalmente, instalar libomp para clangd:  `$ sudo apt install libomp-dev`
- Para ejecutar, simplemente `$ ./bin/<executable>`

### MPI

Instalar **mpi**:

- `$ sudo apt install openmpi-bin libopenmpi-bin`


Sobre los ejecutables, una vez compilado:

- `$ mpirun -np <númeroProcesos> <fichero>`
