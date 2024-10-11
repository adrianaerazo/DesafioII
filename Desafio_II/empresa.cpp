#include "empresa.h"
#include "estaciones.h"


// Constructor
Empresa::Empresa(std::string _nombreEmpresa, int _numeroEstaciones )
{
    // Inicializar el arreglo dinámico de Estaciones
    numeroEstaciones_actual = 0; // Empieza en 0 porque no sean creado Estaciones aun
    numeroEstaciones_total=10;
    // Asignar memoria dinámica para el arreglo de Estaciones
    nombreEmpresa=_nombreEmpresa;
    ventasTotales=0;


    //Poner precios que aumentan de 1000 en 1000
    int aux_precio=10000;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            preciosCombustible[i][j]=aux_precio;
            aux_precio+=1000;
        }
    }
}

// Destructor
Empresa::~Empresa() {

}

void Empresa::crearEstacion(std::string _nombreEstacion, int _codigoEstacion, std::string _gerente, std::string _region, float _ubicacionGPS[2]) {

    // Asignar los valores a la estación en el arreglo, usando acceso directo a los atributos públicos
    arregloEstaciones[numeroEstaciones_actual].nombreEstacion = _nombreEstacion;
    arregloEstaciones[numeroEstaciones_actual].codigoEstacion = _codigoEstacion;
    arregloEstaciones[numeroEstaciones_actual].gerente = _gerente;
    arregloEstaciones[numeroEstaciones_actual].region = _region;
    arregloEstaciones[numeroEstaciones_actual].ubicacionGPS[0] = _ubicacionGPS[0];
    arregloEstaciones[numeroEstaciones_actual].ubicacionGPS[1] = _ubicacionGPS[1];

    // Incrementar el número de estaciones
    numeroEstaciones_actual++;

}

// Método para eliminar una estación por su índice
void Empresa::EliminarEstacion(int indice) {
    if (indice >= 0 && indice < numeroEstaciones_actual) {
        // Mover las estaciones hacia adelante a partir del índice
        for (int i = indice; i < numeroEstaciones_actual - 1; i++) {
            arregloEstaciones[i] = arregloEstaciones[i + 1];
        }

        numeroEstaciones_actual = numeroEstaciones_actual - 1; // Reducimos el número de estaciones actuales

        std::cout << "Estacion eliminada correctamente.\n";
    } else {
        std::cout << "Indice fuera de rango. No se pudo eliminar la estacion.\n";
    }
}

int Empresa::getnumeroEstaciones_actual(){
    return numeroEstaciones_actual;
}



