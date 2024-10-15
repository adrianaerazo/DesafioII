#include "estaciones.h"
#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
#include "islas.h"


// Constructores
// Definir los parametros del constructor
Estaciones::Estaciones(std::string _nombreEstacion, short _codigoEstacion,std::string  _gerente, short _region, float _ubicacionGPS[2], int _preciosCombustible[3][3], int _NumIslas_actual)
{
    NumIslas_actual=0 ;
    CapacidadIslas=NumIslas_actual;// islas a crear en principio
    arregloIslas = new Islas[CapacidadIslas];  // Asignación de memoria dinámica
    aux_Surtidore_sinAsignar=0; //se pone en 0 porque todos por defecto se asignan, ya luego se necesitara
    
    if (CapacidadIslas>12)
    { //verificar que el numero sea menor a 12, ya que no pueden existir mas de  12 islas
        
        CapacidadIslas=12;
        std::cout << "El numero maximo de islas son 12" << std::endl;
        std::cout << "La estacion se creo con 12 islas" << std::endl;
    } 
    
    //inicialmente se va asignar 1 surtidor por cada isla a crear
    if (CapacidadIslas>1)
    {
        numero_total_surtidores=_NumIslas_actual;
        for (int i=0; i<_NumIslas_actual;i++){
            
            crearIsla(1);// i va a ser el codigo, la pos en el arreglo
        }
    }
    else if(CapacidadIslas==1)
    { // si solo se quiere crear una isla, se asignan la cantidad minima de susrtidores totales, que son 2
        
        numero_total_surtidores=2;
        crearIsla(2);// i va a ser el codigo, la pos en el arreglo
    }
    
    nombreEstacion=_nombreEstacion;
    codigoEstacion=_codigoEstacion;
    gerente=_gerente;
    region=_region; //0=sur, 1=centro, 2=norte
    ubicacionGPS[0] = _ubicacionGPS[0]; //latitud del gps
    ubicacionGPS[1] = _ubicacionGPS[1]; //longitud del gps
    
    //fijar el precio del combustible en cada estacion
    for(int j=0; j<3; j++)
    {
        //fija el precio de la gasolina en la estacion en especifico
        //arreglo 1x3, fila 1 de la region en la que esta la estacion y 3 columnas, categorias de gasolina
        preciosCombustible[_region][j]=_preciosCombustible[_region][j];
    }
    
}

//sobrecarga de constructor, para conocer el valor de la cantidad de constructores tiene la empresa
//ir agregando las estaciones al arreglo
Estaciones::Estaciones()
{
    // Inicialización por defecto
    NumTransacciones=20;
    // Inicializar el arreglo bidimensional con la capacidad inicial
    historial_Transacciones = new int*[NumTransacciones];
    for (int i = 0; i < NumTransacciones; i++)
    {
        historial_Transacciones[i] = new int[6];  // Cada fila tendrá 6 columnas
    }
    
    aux_Surtidore_sinAsignar=0;
    nombreEstacion = "";
    codigoEstacion = 0;
    gerente = "";
    region = 0; //0=sur, 1=centro, 2=norte
    ubicacionGPS[0] = 0.0; //inicializa en 0.0 el valor de la latgitud
    ubicacionGPS[1] = 0.0; //inicializa en 0.0 el valor de la longitud
    numero_ventas=0;
    NumIslas_actual=0; 
    CapacidadIslas=1; 
    
    //definir capacidad tanques Regular/Premium/Eco
    // Inicializa la semilla del generador de números aleatorios
    srand(static_cast<int>(time(0)));

    // Asignar valores aleatorios entre 100 y 200
    for (int i = 0; i < 3; ++i)
    {
        Capacidad_tanque[i] = static_cast<int>(rand() % 101 + 100); // Genera un número entre 100 y 200
    }
    
    //inicializar historial de ventas en 0
    for (int i=0; i<4; i++)
    {
        historial_Ventas[i]=0.0;
    }
    
    //poner precio de combustible definido
    for(int j=0; j<3; j++)
    {
        //inicializando los valores
        preciosCombustible[j];
    }

}

// Destructor
Estaciones::~Estaciones()
{
    delete[] arregloIslas;
    for (int i = 0; i < NumTransacciones; i++)
    {
        delete[] historial_Transacciones[i];
    }

}

//Implementacion metodos

void Estaciones::redimensionarTransacciones()
{
    
    // Aumentar la capacidad al doble
    int nuevaCapacidad = NumTransacciones * 2;

    // Crear un nuevo arreglo bidimensional con la nueva capacidad
    int** nuevoArreglo = new int*[nuevaCapacidad];
    for (int i = 0; i < nuevaCapacidad; i++)
    {
        nuevoArreglo[i] = new int[6];  // Cada fila sigue teniendo 6 columnas
    }

    // Copiar los datos del arreglo antiguo al nuevo
    for (int i = 0; i < numero_ventas; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            nuevoArreglo[i][j] = historial_Transacciones[i][j];
        }
    }

    // Liberar la memoria del arreglo antiguo
    for (int i = 0; i < NumTransacciones; i++)
    {
        delete[] historial_Transacciones[i];
    }
    delete[] historial_Transacciones;

    // Asignar el nuevo arreglo y actualizar la capacidad
    historial_Transacciones = nuevoArreglo;
    NumTransacciones = nuevaCapacidad;

}

void Estaciones::venta(int _metodo_pago, int _cant_L, int tipo_gal)
{
    bool asignado= false;
    int isla_seleccionada=0;
    int surtidor_seleccionado=0;

    while(asignado==false)
    { // buscar aleatoriamente un sutidor. Se realizara hasta encontrar uno activo
        
        isla_seleccionada = std::rand() % NumIslas_actual;  // Seleccionar isla aleatoria
        surtidor_seleccionado= std::rand() % arregloIslas[isla_seleccionada].NumSurtidores_actual;// Seleccionar surtidor de la isla aleatoria
        if (arregloIslas[isla_seleccionada].arregloSurtidores[surtidor_seleccionado].surtidorActivo==true)
        {
        asignado=true;
        }
    }
    //empezar venta con el surtidor seleccionado
    
    int capacidad_tanque_venta=Capacidad_tanque[tipo_gal]; // tanque seleccionado segun tipo gasolina
    int precioCombustible_venta=preciosCombustible[region][tipo_gal]; // precio de gal seleccionada
    // realizar venta y obtener nueva capacidad del tanque y info de venta, luego de venta
    int* resultado =arregloIslas[isla_seleccionada].arregloSurtidores[surtidor_seleccionado].ventaSurtidor( _metodo_pago, _cant_L, tipo_gal, capacidad_tanque_venta, precioCombustible_venta);
    
    Capacidad_tanque[tipo_gal]=resultado[0];
    if (numero_ventas==NumTransacciones)
    { // si el num ventas llega al max de transacciones, aumentar espacio
        redimensionarTransacciones();
    }
    // Asignar los valores a la siguiente fila disponible
    // guardar informacion de venta    
    int indice_numVenta=resultado[1];
    historial_Transacciones[numero_ventas] = arregloIslas[isla_seleccionada].arregloSurtidores[surtidor_seleccionado].historial_Transacciones[indice_numVenta];
    
    //sumar ventas del surtidor
    //Guardar valores totales de ventas
    int precio_cobrar=historial_Transacciones[numero_ventas][5]; // sacar info de la proporcionada por el surtidor
    historial_Ventas[0]=historial_Ventas[0]+precio_cobrar ; // venta total
    historial_Ventas[tipo_gal+1]=historial_Ventas[tipo_gal+1]+precio_cobrar ; // venta tipo gasolina
    
    numero_ventas=numero_ventas + 1;
    

    delete[] resultado;  // Libera la memoria asignada con 'new[]'
    
}


//Implementacion get y set Nombre Estacion

int Estaciones::getregion()
{
    return region;

}

void Estaciones::setNombreEstacion(std::string _nombreEstacion)
{
    nombreEstacion=_nombreEstacion;
}

std::string Estaciones::getNombreEstacion() const
{
    return nombreEstacion;
}


//Implementacion get y set Codigo de Estacion
void Estaciones::setCodigoEstacion(int _codigoEstacion)
{
    codigoEstacion=_codigoEstacion;
}
int Estaciones::getCodigoEstacion() const
{
    return codigoEstacion;
}

//Implementacion set y get Gerente
void Estaciones::setGerente(std::string _gerente)
{
    gerente=_gerente;
}
std::string Estaciones::getGerente() const
{
    return gerente;
}

void Estaciones::actualizarPrecios(int nuevosPrecios[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            preciosCombustible[i][j] = nuevosPrecios[i][j];
        }
    }
}



void Estaciones::crearIsla(int _CapacidadSurtidores){
  // Verificamos si necesitamos redimensionar el arreglo
    if (NumIslas_actual == CapacidadIslas)
    {
        // Si el arreglo está lleno, duplicamos la capacidad
        CapacidadIslas *= 2;  // Doblamos la capacidad del arreglo

        // Creamos un nuevo arreglo con la nueva capacidad
        Islas* nuevoArreglo = new Islas[CapacidadIslas];

        // Copiamos las estaciones existentes al nuevo arreglo
        for (int i = 0; i < NumIslas_actual; i++)
        {
            nuevoArreglo[i] = arregloIslas[i];
        }

        // Liberamos la memoria del arreglo antiguo
        delete[] arregloIslas;

        // Asignamos el nuevo arreglo al puntero
        arregloIslas = nuevoArreglo;
    }

    // Asignar los valores al nuevo surtidor en el arreglo, usando acceso directo a los atributos públicos
    arregloIslas[NumIslas_actual]=Islas( _CapacidadSurtidores, NumIslas_actual);

    // Incrementar el número de surtidores
    NumIslas_actual++;  // Incrementamos el número de surtidores

    std::cout << "Isla creada correctamente." << std::endl;
    
}

void Estaciones::eliminarIsla(int _codigoIsla)
{

    if (_codigoIsla >= 0 && _codigoIsla < NumIslas_actual)
    {
        // Mover las estaciones hacia adelante a partir del índice
        for (int i = _codigoIsla; i < NumIslas_actual - 1; i++)
        {
            arregloIslas[i] = arregloIslas[i + 1];
        }

        NumIslas_actual = NumIslas_actual - 1; // Reducimos el número de surtidores actuales

        std::cout << "Isla eliminado correctamente.\n";
    }
    else
    {
        std::cout << "Posicion fuera de rango. No se pudo eliminar la isla.\n";
    }
}
int Estaciones::getNumIslas_actual()
{
    return NumIslas_actual;
}
int Estaciones::getRegion()
{
    return region;
}
void Estaciones::actualizarDisponibilidadCombustible()
{

}

bool Estaciones::verificarFugaCombustible()
{

}


