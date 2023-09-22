import pandas as pd
import matplotlib.pyplot as plt

datos = pd.read_csv('distancias.txt')
cabeza = datos.columns.tolist()
head=int(cabeza[0])





plt.hist(datos, bins=10, edgecolor='black')
y= datos.max().max()
plt.xlim(0, y+0.01)  # Comienza en 0 y termina en el valor máximo de los datos

print(datos.max().max())
plt.xlabel('Valores')
plt.ylabel('Frecuencia')
plt.title(f'Histograma de las distancias entre puntos con dimension {head} ')

# Muestra el histograma
plt.show()