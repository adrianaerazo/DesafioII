#include "empresa.h"
#include "estaciones.h"



// Constructor
Empresa::Empresa(std::string _nombreEmpresa, int _numeroEstaciones)
{
    // Inicializar el arreglo dinámico de Estaciones
    numeroEstaciones_actual = 0; // Empieza en 0 porque no sean creado Estaciones aun
    numeroEstaciones_total=_numeroEstaciones;

    // Asignar memoria dinámica para el arreglo de Estaciones
    nombreEmpresa=_nombreEmpresa;
    ventasTotales=0;

    arregloEstaciones = new Estaciones[numeroEstaciones_total];  // Asignación de memoria dinámica


    //Poner precios que aumentan de 1000 en 1000
    //por defecto, en automatico
    int aux_precio=1000;
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
Empresa::~Empresa()
{
    delete[] arregloEstaciones;

}

void Empresa::crearEstacion(std::string _nombreEstacion,int codigoEstacion, std::string _gerente, short _region, float _ubicacionGPS[2], int preciosCombustible[3][3], int _CapacidadIslas)
{
    // Verificamos si necesitamos redimensionar el arreglo
    if (numeroEstaciones_actual == numeroEstaciones_total)
    {
        // Si el arreglo está lleno, duplicamos la capacidad
        numeroEstaciones_total *= 2;  // Doblamos la capacidad del arreglo

        // Creamos un nuevo arreglo con la nueva capacidad
        Estaciones* nuevoArreglo = new Estaciones[numeroEstaciones_total];

        // Copiamos las estaciones existentes al nuevo arreglo
        for (int i = 0; i < numeroEstaciones_actual; i++)
        {
            nuevoArreglo[i] = arregloEstaciones[i];
        }

        // Liberamos la memoria del arreglo antiguo
        delete[] arregloEstaciones;

        // Asignamos el nuevo arreglo al puntero
        arregloEstaciones = nuevoArreglo;
    }

    // Asignar los valores a la nueva estación en el arreglo, usando acceso directo a los atributos públicos
    arregloEstaciones[numeroEstaciones_actual]=Estaciones(_nombreEstacion, numeroEstaciones_actual, _gerente, _region, _ubicacionGPS, preciosCombustible, _CapacidadIslas);

    // Incrementar el número de estaciones
    numeroEstaciones_actual++;  // Incrementamos el número de estaciones

    std::cout << "Estacion creada correctamente." << std::endl;
}


// Método para eliminar una estación por su posicion
void Empresa::eliminarEstacion(int indice)
{

    if (indice >= 0 && indice < numeroEstaciones_actual)
    {
        // Mover las estaciones hacia adelante a partir del índice
        for (int i = indice; i < numeroEstaciones_actual - 1; i++)
        {
            arregloEstaciones[i] = arregloEstaciones[i + 1];
        }

        numeroEstaciones_actual = numeroEstaciones_actual - 1; // Reducimos el número de estaciones actuales

        std::cout << "Estacion eliminada correctamente.\n";
    }
    else
    {
        std::cout << "Posicion fuera de rango. No se pudo eliminar la estacion.\n";
    }
}
void Empresa::getPreciosCombustible(int precios[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            precios[i][j] = preciosCombustible[i][j]; // Copiamos cada valor
        }
    }
}

int Empresa::calculoMontoTotal()
{//Calcular ventas totales de la estacion
    
    std::cout << "Nombre estacion " << " Region "<<" Venta Total " << " V. Regular" << " V. Premium " << " V. EcoExtra\n";
    
    for (int i= 0; i<numeroEstaciones_actual;i++)
    {
        ventasTotales=ventasTotales+arregloEstaciones[i].historial_Ventas[0];
         std::cout <<nombreEmpresa <<arregloEstaciones[i].getregion()<< arregloEstaciones[i].historial_Ventas[0] << arregloEstaciones[i].historial_Ventas[1] << arregloEstaciones[i].historial_Ventas[2] << arregloEstaciones[i].historial_Ventas[3]<<".\n";
    }
    
    std::cout << "Las Ventas totales fueron "<< ventasTotales << "\n";
    
    return ventasTotales;
}

int Empresa::getnumeroEstaciones_actual()
{
    return numeroEstaciones_actual;
}

std::string Empresa::getnombreEmpresa()
{
    return nombreEmpresa;
}

void Empresa::cambiarPrecio(int precioBase, int precioAumentar)
{
    // Cambiar los precios en la matriz preciosCombustible de la clase Empresa
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            preciosCombustible[i][j] = precioBase;
            precioBase += precioAumentar;
        }
    }

    // Asignar los nuevos precios a cada estación existente
    for(int i = 0; i < numeroEstaciones_actual; i++)
    {
        arregloEstaciones[i].actualizarPrecios(preciosCombustible); // Método para actualizar precios en cada estación
    }

    std::cout <<"Cambios realizados exitosamente. "<<std::endl;
}





