#include "islas.h"
#include "surtidores.h"


Islas::Islas()
{
     NumSurtidores_actual=0;
     CapacidadSurtidores=1;
     Codigo=0;
}
//constructor
Islas::Islas(int _NumSurtidores, int _Codigo)
{
     NumSurtidores_actual=0; 
     CapacidadSurtidores=_NumSurtidores; 
     Codigo=_Codigo; 
     arregloSurtidores = new Surtidores[CapacidadSurtidores]; 
     
    //DEFINIR OPCIONES DEL MODELO
    // Definir las opciones usando un arreglo estatico de std::string
    std::string opciones[] = {"ABD", "XYZ", "JCL"};

    // Seleccionar un indice aleatorio
    int indiceAleatorio = rand() % 3;
     
     //asignar surtidores a islas
    for (int i=0; i<_NumSurtidores;i++)
    {
        asignarSurtidor( opciones[indiceAleatorio]);
    }
}


// Destructor
Islas::~Islas()
{
    delete[] arregloSurtidores;

}

void Islas::asignarSurtidor( std::string _modeloSurtidor)
{
    // Verificamos si necesitamos redimensionar el arreglo
    if (NumSurtidores_actual == CapacidadSurtidores)
    {
        // Si el arreglo está lleno, duplicamos la capacidad
        CapacidadSurtidores *= 2;  // Doblamos la capacidad del arreglo

        // Creamos un nuevo arreglo con la nueva capacidad
        Surtidores* nuevoArreglo = new Surtidores[CapacidadSurtidores];

        // Copiamos las estaciones existentes al nuevo arreglo
        for (int i = 0; i < NumSurtidores_actual; i++)
        {
            nuevoArreglo[i] = arregloSurtidores[i];
        }

        // Liberamos la memoria del arreglo antiguo
        delete[] arregloSurtidores;

        // Asignamos el nuevo arreglo al puntero
        arregloSurtidores = nuevoArreglo;
    }

    // Asignar los valores al nuevo surtidor en el arreglo, usando acceso directo a los atributos publicos
    arregloSurtidores[NumSurtidores_actual]=Surtidores(NumSurtidores_actual , _modeloSurtidor);

    // Incrementar el numero de surtidores
    NumSurtidores_actual++;  // Incrementamos el numero de surtidores

    std::cout << "Surtidor asignado correctamente." << std::endl;
    
}

void Islas::eliminarSurtidor(int _codigoSurtidor)
{


    if (_codigoSurtidor >= 0 && _codigoSurtidor < NumSurtidores_actual)
    {
        // Mover los surtidores hacia adelante a partir del indice
        for (int i = _codigoSurtidor; i < NumSurtidores_actual - 1; i++)
        {
            arregloSurtidores[i] = arregloSurtidores[i + 1];
        }

        NumSurtidores_actual = NumSurtidores_actual - 1; // Reducimos el numero de surtidores actuales

        std::cout << "Surtidor eliminado correctamente.\n";
    }
    else
    {
        std::cout << "Posicion fuera de rango. No se pudo eliminar el surtidor.\n";
    }
    
}
// Implementacion get y set Numero Total Surtidores
int Islas::getNumeroTotalSurtidores()
{
    return NumSurtidores_actual;
}
int Islas::getCodigoIsla()
{
    return Codigo;
}
Surtidores& Islas::getSurtidor(int indice)
{
    return arregloSurtidores[indice];  // Devuelve el surtidor solicitado
}
// Activar surtidor
void Islas::activarSurtidor(int indice)
{
    if (indice >= 0 && indice < NumSurtidores_actual)
    {
        arregloSurtidores[indice].activarSurtidor();
    }
}

// Desactivar surtidor
void Islas::desactivarSurtidor(int indice)
{
    if (indice >= 0 && indice < NumSurtidores_actual)
    {
        arregloSurtidores[indice].desactivarSurtidor();
    }
}
