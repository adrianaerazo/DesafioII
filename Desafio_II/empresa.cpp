#include "empresa.h"
#include "estaciones.h"


// Constructor
Empresa::Empresa(std::string _nombreEmpresa, int _numeroEstaciones )
{
    // Inicializar el arreglo dinámico de Estaciones
    numeroEstaciones_actual = 0; // Empieza en 0 porque no sean creado Estaciones aun
    numeroEstaciones_total=_numeroEstaciones;
    // Asignar memoria dinámica para el arreglo de Estaciones
    nombreEmpresa=_nombreEmpresa;
    ventasTotales=0;

    arregloEstaciones = new Estaciones[numeroEstaciones_total];  // Asignación de memoria dinámica




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
    delete[] arregloEstaciones;

}
void Empresa::crearEstacion(std::string _nombreEstacion, int _codigoEstacion, std::string _gerente, std::string _region, float _ubicacionGPS[2]) {

    // Verificamos si necesitamos redimensionar el arreglo
    if (numeroEstaciones_actual == numeroEstaciones_total) {
        // Si el arreglo está lleno, duplicamos la capacidad
        numeroEstaciones_total *= 2;  // Doblamos la capacidad del arreglo

        // Creamos un nuevo arreglo con la nueva capacidad
        Estaciones* nuevoArreglo = new Estaciones[numeroEstaciones_total];

        // Copiamos las estaciones existentes al nuevo arreglo
        for (int i = 0; i < numeroEstaciones_actual; i++) {
            nuevoArreglo[i] = arregloEstaciones[i];
        }

        // Liberamos la memoria del arreglo antiguo
        delete[] arregloEstaciones;

        // Asignamos el nuevo arreglo al puntero
        arregloEstaciones = nuevoArreglo;
    }

    // Asignar los valores a la nueva estación en el arreglo, usando acceso directo a los atributos públicos
    arregloEstaciones[numeroEstaciones_actual].nombreEstacion = _nombreEstacion;
    arregloEstaciones[numeroEstaciones_actual].codigoEstacion = _codigoEstacion;
    arregloEstaciones[numeroEstaciones_actual].gerente = _gerente;
    arregloEstaciones[numeroEstaciones_actual].region = _region;
    arregloEstaciones[numeroEstaciones_actual].ubicacionGPS[0] = _ubicacionGPS[0];
    arregloEstaciones[numeroEstaciones_actual].ubicacionGPS[1] = _ubicacionGPS[1];

    // Incrementar el número de estaciones
    numeroEstaciones_actual++;  // Incrementamos el número de estaciones

    std::cout << "Estacion creada correctamente." << std::endl;
}
//void Empresa::crearEstacion(std::string _nombreEstacion, int _codigoEstacion, std::string _gerente, std::string _region, float _ubicacionGPS[2]) {
//
//    // Asignar los valores a la estación en el arreglo, usando acceso directo a los atributos públicos
//    arregloEstaciones[numeroEstaciones_actual].nombreEstacion = _nombreEstacion;
//    arregloEstaciones[numeroEstaciones_actual].codigoEstacion = _codigoEstacion;
//    arregloEstaciones[numeroEstaciones_actual].gerente = _gerente;
//    arregloEstaciones[numeroEstaciones_actual].region = _region;
//    arregloEstaciones[numeroEstaciones_actual].ubicacionGPS[0] = _ubicacionGPS[0];
//    arregloEstaciones[numeroEstaciones_actual].ubicacionGPS[1] = _ubicacionGPS[1];
//
//    // Incrementar el número de estaciones
//    numeroEstaciones_actual++;
//
//}

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



