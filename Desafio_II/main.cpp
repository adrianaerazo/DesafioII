#include "empresa.h"
#include "estaciones.h"
#include <iostream>

int main() {
    int aux = 0;

    // Crear una empresa con capacidad para 5 estaciones
    Empresa miEmpresa("Terpel", 5);

    // Crear dos estaciones
    float gps1[] = {19.4326, -99.1332}; // Ubicacion de la estacion 1
    float gps2[] = {40.7128, -74.0060}; // Ubicacion de la estacion 2
    // Sur/Centro/Norte 0 1 2
    miEmpresa.crearEstacion("Estacion A", 101, "Juan Perez", 1, gps1);
    miEmpresa.crearEstacion("Estacion B", 102, "Maria Gomez", 2, gps2);

    // Verificar el numero de estaciones antes de eliminar
    std::cout << "Numero de estaciones antes de eliminar: " << miEmpresa.getnumeroEstaciones_actual() << std::endl;

    // Eliminar la estacion en el indice 0 (la primera estacion)
    miEmpresa.EliminarEstacion(0);

    // Verificar el numero de estaciones despues de eliminar
    std::cout << "Numero de estaciones despues de eliminar: " << miEmpresa.getnumeroEstaciones_actual() << std::endl;

    miEmpresa.crearEstacion("Estacion A", 101, "Juan Perez", 1, gps1);
    miEmpresa.crearEstacion("Estacion B", 102, "Maria Gomez", 2, gps2);
    miEmpresa.crearEstacion("Estacion A", 101, "Juan Perez", 1, gps1);
    miEmpresa.crearEstacion("Estacion B", 102, "Maria Gomez", 2, gps2);
    miEmpresa.crearEstacion("Estacion A", 101, "Juan Perez", 1, gps1);
    miEmpresa.crearEstacion("Estacion B", 102, "Maria Gomez", 2, gps2);
    miEmpresa.crearEstacion("Estacion A", 101, "Juan Perez", 1, gps1);
    miEmpresa.crearEstacion("Estacion B", 102, "Maria Gomez", 2, gps2);

    // Verificar el numero de estaciones despues de eliminar
    std::cout << "Numero de estaciones despues de eliminar: " << miEmpresa.getnumeroEstaciones_actual() << std::endl;

    return 0;
}

