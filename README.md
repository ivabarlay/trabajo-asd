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

Instalar **mpi**:

- `$ sudo apt install openmpi-bin`

Sobre los ejecutables, una vez compilado:

- `$ mpirun -np <númeroProcesos> <fichero>`
