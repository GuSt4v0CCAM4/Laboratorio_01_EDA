#include <iostream>
#include <vector>
#include <random>
#include <fstream>

int main() {
    // Semilla para la generación de números aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());

    // Definir un distribuidor uniforme para valores entre 0 y 1
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    // Configurar el número de dimensiones "d"
    int d = 5000; // Cambia esto para la cantidad de dimensiones que desees

    std::vector<std::vector<double>> puntos;

    // Generar 100 puntos aleatorios en "d" dimensiones
    for (int i = 0; i < 100; ++i) {
        std::vector<double> punto;
        for (int j = 0; j < d; ++j) {
            double valor = distribution(gen);
            punto.push_back(valor);
        }
        puntos.push_back(punto);
    }

    // Calcular y guardar las distancias en un archivo de texto
    std::ofstream archivo("distancias.txt");
    archivo << d << std::endl;
    for (int i = 0; i < 100; ++i) {
        for (int j = i + 1; j < 100; ++j) {
            double distancia = 0.0;
            for (int k = 0; k < d; ++k) {
                double diferencia = puntos[i][k] - puntos[j][k];
                distancia += diferencia * diferencia;
            }
            distancia = sqrt(distancia);
            archivo << distancia << std::endl;
        }
    }
    archivo.close();

    return 0;
}
