#include "estaciones.h"
#include <iostream>

// Constructores
Estaciones::Estaciones(std::string _nombreEstacion, int _codigoEstacion,std::string  _gerente, std::string _region,float _ubicacionGPS[2])
{
    nombreEstacion=_nombreEstacion;
    codigoEstacion=_codigoEstacion;
    gerente=_gerente;
    region=_region;
    ubicacionGPS[0] = _ubicacionGPS[0];
    ubicacionGPS[1] = _ubicacionGPS[1];
}
Estaciones::Estaciones() {
    // Inicialización por defecto
    nombreEstacion = "";
    codigoEstacion = 0;
    gerente = "";
    region = "";
    ubicacionGPS[0] = 0.0;
    ubicacionGPS[1] = 0.0;

    for (int i=0; i<4; i++) {
        historial_Ventas[i]=0.0
    }
}

//Implementacion metodos

//Implementacion get y set Nombre Estacion

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


