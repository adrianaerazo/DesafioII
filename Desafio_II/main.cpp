#include "estaciones.h"
#include <iostream>

int main() {
    // Datos de prueba para la estacion
    std::string nombre = "Estacion Central";
    int codigo = 123;
    std::string gerente = "Camila Erazo";
    std::string region = "Norte";
    float ubicacion[2] = {10.123, -74.567};  // Coordenadas GPS de ejemplo

    // Crear un objeto de la clase Estaciones
    Estaciones estacion3(nombre, codigo, gerente, region, ubicacion);
    Estaciones estacion2(nombre, codigo, gerente, region, ubicacion);
    Estaciones estacion1(nombre, codigo, gerente, region, ubicacion);

    // Usar los métodos get para imprimir los valores
    std::cout << "Nombre de la estacion: " << estacion2.getNombreEstacion() << std::endl;
    std::cout << "Codigo de la estacion: " << estacion3.getCodigoEstacion() << std::endl;
    std::cout << "Gerente: " << estacion1.getGerente() << std::endl;

    return 0;
}
