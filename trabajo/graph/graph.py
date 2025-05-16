import matplotlib.pyplot as plt
import pandas as pd

# Cargo los datos con panda (ivan no me mates)
# data = pd.read_csv('./data/ejemplo.csv')

plt.figure(figsize=(10, 6))

for method in data['method'].unique():
    subset = data[data['method'] == method] #Coge la fila del metodo method
    plt.plot(subset['threads'], subset['time (s)'], marker='o', label=method) #EjeX: threads, EjeY: tiempo en segundos

    # Esto lo he puesto pa anotar los valores de pi
    for _, row in subset.iterrows(): #Ignoro el indice, row son los datos
        plt.annotate(f"π={row['pi_value']:.5f}", 
                     (row['threads'], row['time (s)'] + 0.01), #En el ejeY he tenido que moverlo un poco pq se comia la grafica
                     fontsize=8, ha='center')

plt.xlabel("Número de Hilos/Procesos")
plt.ylabel("Tiempo de Ejecución (s)")
plt.title("Comparativa de Métodos para la Estimación de π")
plt.grid(True) #Pa la cuadricula
plt.legend()
plt.show()