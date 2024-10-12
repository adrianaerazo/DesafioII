#include "estaciones.h"
#include <iostream>

// Constructores
Estaciones::Estaciones(std::string _nombreEstacion, int _codigoEstacion,std::string  _gerente, std::string _region,float _ubicacionGPS[2],float _preciosCombustible[3][3]))
{
    nombreEstacion=_nombreEstacion;
    codigoEstacion=_codigoEstacion;
    gerente=_gerente;
    region=_region;
    ubicacionGPS[0] = _ubicacionGPS[0];
    ubicacionGPS[1] = _ubicacionGPS[1];
    
    
    for(int i=0; i<3; i++) //Las columnas son Sur/Centro/Norte, las filas son el tipo de gasolina, Regular/Premium/EcoExtra
    {
        for(int j=0; j<3; j++)
        {
            preciosCombustible[i][j]=_preciosCombustible[i][j];
        }
    }
    
}
Estaciones::Estaciones() {
    // Inicialización por defecto
    nombreEstacion = "";
    codigoEstacion = 0;
    gerente = "";
    region = "";
    ubicacionGPS[0] = 0.0;
    ubicacionGPS[1] = 0.0;
    numero_ventas=0;
    

    for (int i=0; i<4; i++) {
        historial_Ventas[i]=0.0
    }
    
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            preciosCombustible[i][j]=0;
        }
    }
}

//Implementacion metodos

void venta(float _metodo_pago, float _cant_L, float _fecha, float _hora, float _categoria, tipo_gal){
    historial_Transacciones = new float[5]();// // info: metodo_pago, cantidad L vendida ,fecha ,hora, categoria de gasolina
    
    // Asignar valores a cada elemento del arreglo
    historial_Transacciones[0] = _metodo_pago;  // Método de pago
    historial_Transacciones[1] = _cant_L;       // Cantidad de litros vendida
    historial_Transacciones[2] = _fecha;        // Fecha
    historial_Transacciones[3] = _hora;         // Hora
    historial_Transacciones[4] = _categoria;    // Categoría de gasolina
    
    

    //Guardar valores totales de ventas
    precio_cobrar=preciosCombustible[region][tipo_gal]*_cant_L //Las columnas son Sur/Centro/Norte, las filas son el tipo de gasolina, Regular/Premium/
    historial_Ventas[0]=historial_Ventas[0]+precio_cobrar  // venta toal
    historial_Ventas[tipo_gal]=historial_Ventas[tipo_gal]+precio_cobrar  // venta tipo gasolina
}

//Implementacion get y set Nombre Estacion

std::string getregion(){
    return region;
}
}

void Estaciones::setNombreEstacion(std::string _nombreEstacion)
{
    nombreEstacion=_nombreEstacion;
}
std::string Estaciones::getNombreEstacion() const
{
    return nombreEstacion;
}

void Estaciones::venta(float _metodo_pago, float _cant_L, float _fecha, float _hora, float _categoria){

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


void Estaciones::agregarSurtidor(int codigoSurtidor, std::string modeloSurtidor)
{

}

void Estaciones::eliminarSurtidor(int codigoSurtidor, std::string modeloSurtidor)
{

}

void Estaciones::calcularVentasPorCategoria()
{

}

void Estaciones::fijarPreciosCombustible()
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


