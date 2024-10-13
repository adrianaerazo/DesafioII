#include "estaciones.h"
#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()



// Inicializa la semilla del generador de números aleatorios
//srand(static_cast<int>(time(0)));


// Constructores
// Definir los parametros del constructor
Estaciones::Estaciones(std::string _nombreEstacion, short _codigoEstacion,std::string  _gerente, short _region, float _ubicacionGPS[2], int _preciosCombustible[3][3])
{
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
    nombreEstacion = "";
    codigoEstacion = 0;
    gerente = "";
    region = 0; //0=sur, 1=centro, 2=norte
    ubicacionGPS[0] = 0.0; //inicializa en 0.0 el valor de la latgitud
    ubicacionGPS[1] = 0.0; //inicializa en 0.0 el valor de la longitud
    numero_ventas=0;
    
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
    //historial_Transacciones = static float[6]();// // info: metodo_pago, cantidad L vendida ,fecha ,hora, categoria de gasolina, precio_cobrar
    
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


