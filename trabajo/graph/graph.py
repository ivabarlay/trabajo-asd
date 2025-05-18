import matplotlib.pyplot as plt
import pandas as pd

# Cargo los datos con panda (ivan no me mates)

# files = [
#     "./data/integration_serial_ejemplo.csv",
#     "./data/integration_openmp_ejemplo.csv",
#     "./data/integration_mpi_ejemplo.csv",
#     "./data/montecarlo_serial_ejemplo.csv",
#     "./data/montecarlo_openmp_ejemplo.csv",
#     "./data/montecarlo_mpi_ejemplo.csv"
# ]

files = [
    "./data/omp_result.csv",
    "./data/mpi_result.csv",
    # "./data/serial_result.csv",

]

dataframes = [pd.read_csv(file) for file in files]
data = pd.concat(dataframes)
print(data)
plt.figure(figsize=(10, 6))
#Grafica de tiempos
for (method, implementation) in data[["method", "implementation"]].drop_duplicates().values: #voy diferenciando por metodo e imp
    subset = data[(data["method"] == method) & (data["implementation"] == implementation)]
    label = f"{method}-{implementation}"
    plt.plot(subset["threads"], subset["time (s)"], marker='o', linestyle='-', label=label)

plt.xlabel("Número de Hilos/Procesos")
plt.ylabel("Tiempo de Ejecución (s)")
plt.title("Comparativa de Métodos para la Estimación de π")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()
#Grafica de errores
plt.figure(figsize=(10, 6))
for (method, implementation) in data[["method", "implementation"]].drop_duplicates().values:
    subset = data[(data["method"] == method) & (data["implementation"] == implementation)]
    label = f"{method}-{implementation}"
    plt.plot(subset["threads"], subset["error"], marker='o', linestyle='-', label=label)

plt.xlabel("Número de hilos")
plt.ylabel("Valor Absoluto del error en la estimación de π")
plt.title("Comparativa del valor estimado de π")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()
