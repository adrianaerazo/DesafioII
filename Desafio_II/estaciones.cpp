#include "estaciones.h"
#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
#include "islas.h"



// Inicializa la semilla del generador de números aleatorios
//srand(static_cast<int>(time(0)));


// Constructores
// Definir los parametros del constructor
Estaciones::Estaciones(std::string _nombreEstacion, short _codigoEstacion,std::string  _gerente, short _region, float _ubicacionGPS[2], int _preciosCombustible[3][3], int _NumIslas_actual)
{
    NumIslas_actual=0 ;
    CapacidadIslas=NumIslas_actual;// islas a crear en principio
    arregloIslas = new Islas[CapacidadIslas];  // Asignación de memoria dinámica
    aux_Surtidore_sinAsignar=0; //se pone en 0 porque todos por defecto se asignan, ya luego se necesitara
    
    if (CapacidadIslas>12) { //verificar que el numero sea menor a 12, ya que no pueden existir mas de  12 islas
        
        CapacidadIslas=12;
        std::cout << "El numero maximo de islas son 12" << std::endl;
        std::cout << "La estacion se creo con 12 islas" << std::endl;
    } 
    
    //inicialmente se va asignar 1 surtidor por cada isla a crear
    if (CapacidadIslas>1){
        numero_total_surtidores=_NumIslas_actual;
        for (int i=0; i<_NumIslas_actual;i++){
            
            crearIsla(1);// i va a ser el codigo, la pos en el arreglo
        }
    }
    else if(CapacidadIslas==1){ // si solo se quiere crear una isla, se asignan la cantidad minima de susrtidores totales, que son 2
        
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
    delete[] historial_Transacciones;

}

//Implementacion metodos

void Estaciones::venta(float _metodo_pago, float _cant_L, float _fecha, float _hora, int tipo_gal)
{
    //int precio_cobrar=0; almacena la operacion de la multiplicacion del precio * la cantidad de litros
    int precio_cobrar=0;
    //int aux_capacidad=0; almacena el valor, para verificar si el combustible del tanque es suficiente para la venta,
    //si la operacion obtiene como resultado un numero negativo, quiere decir que el tanque no cuenta con lo suficiente
    int aux_capacidad = Capacidad_tanque[tipo_gal] - _cant_L;
    
    //Actualizar cantidad de combustible en los tanques (Regular/Premium/Eco)
    aux_capacidad=Capacidad_tanque[tipo_gal]-_cant_L; // utilizar variable aux para verificar si hay suficiente para vender, si no vender lo que hay
    
    //verificar si el tanque esta contiene la cantidad necesaria para la venta
    //si la cantidad solicitada es negativa, se vende lo que hay y se vacia el tanque
    if (aux_capacidad<=0)
    {
        //la cantidad de litros solicitada pasa a ser la cantidad que hay en el tanque
        _cant_L=Capacidad_tanque[tipo_gal];//se vende lo del tanque
        //se actualiza el tanque
        Capacidad_tanque[tipo_gal]=0; //evitar negativos
        //desactivar surtidores
    }
    else
    {
        //si el tanque puede vender sin problema, se actualiza la cantidad de la categoria en especifico del tanque
        Capacidad_tanque[tipo_gal]=Capacidad_tanque[tipo_gal]-_cant_L;
    }
    
    //Informacion de venta
    historial_Transacciones = new float[5]();// info: metodo_pago, cantidad L vendida ,fecha ,hora, categoria de gasolina, precio_cobrar
    //historial_Transacciones = static float[6]();// 
    // Asignar valores a cada elemento del arreglo
    historial_Transacciones[0] = _metodo_pago;  // Método de pago
    historial_Transacciones[1] = _cant_L;       // Cantidad de litros vendida
    historial_Transacciones[2] = _fecha;        // Fecha
    historial_Transacciones[3] = _hora;         // Hora
    historial_Transacciones[4] = tipo_gal;    // Categoría de gasolina

    

    //Guardar valores totales de ventas
    precio_cobrar=preciosCombustible[region][tipo_gal]*_cant_L; //Las columnas son Sur/Centro/Norte, las filas son el tipo de gasolina, Regular/Premium/Eco
    historial_Ventas[0]=historial_Ventas[0]+precio_cobrar ; // venta total
    historial_Ventas[tipo_gal+1]=historial_Ventas[tipo_gal+1]+precio_cobrar ; // venta tipo gasolina

    //asignar el valor monetario al historial de transacciones
    historial_Transacciones[5] = precio_cobrar; //precio por transaccion cobrada
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

void Estaciones::eliminarIsla(int _codigoIsla){

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

void Estaciones::agregarSurtidor(int codigoSurtidor, std::string modeloSurtidor)
{

}

void Estaciones::eliminarSurtidor(int codigoSurtidor, std::string modeloSurtidor)
{

}

void Estaciones::calcularVentasPorCategoria()
{

}

void Estaciones::actualizarDisponibilidadCombustible()
{

}

void Estaciones::simularVentaCombustible()
{

}

bool Estaciones::verificarFugaCombustible()
{

}


