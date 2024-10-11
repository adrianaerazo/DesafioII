#include "empresa.h"
#include "estaciones.h"
#include <iostream>

int main() {
    int aux=0;

    // Crear una empresa con capacidad para 5 estaciones
    Empresa miEmpresa("Terpel", 5);

    // Crear dos estaciones
    float gps1[] = {19.4326, -99.1332}; // Ubicación de la estación 1
    float gps2[] = {40.7128, -74.0060}; // Ubicación de la estación 2

    miEmpresa.crearEstacion("Estación A", 101, "Juan Pérez", "Centro", gps1);
    miEmpresa.crearEstacion("Estación B", 102, "María Gómez", "Norte", gps2);

    // Verificar el número de estaciones antes de eliminar
    std::cout << "Numero de estaciones antes de eliminar: " << miEmpresa.getnumeroEstaciones_actual() << std::endl;

    // Eliminar la estación en el índice 0 (la primera estación)
    miEmpresa.EliminarEstacion(0);

    // Verificar el número de estaciones después de eliminar
    std::cout << "Numero de estaciones despues de eliminar: " << miEmpresa.getnumeroEstaciones_actual() << std::endl;

    // Intentar eliminar una estación con un índice fuera de rango
    miEmpresa.EliminarEstacion(5);  // Esto debe mostrar "indice fuera de rango"




    return 0;
}
