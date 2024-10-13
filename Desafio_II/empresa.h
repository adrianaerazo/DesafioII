#ifndef EMPRESA_H
#define EMPRESA_H
#include<iostream>
#include "estaciones.h"

class Empresa
{
private:
    //Definicion Atributos
    std::string nombreEmpresa;
    int preciosCombustible[3][3];//Las columnas son Sur/Centro/Norte, las filas son el tipo de gasolina, Regular/Premium/EcoExtra
    int numeroEstaciones_actual;        // Número actual de estaciones
    int numeroEstaciones_total;        // Número Total de estaciones
    Estaciones* arregloEstaciones; //  arreglo de Estaciones

    public:
        int ventasTotales;



public:
    Empresa(std::string _nombreEmpresa, int _numeroEstaciones ); //constructor
    ~Empresa(); // Destructor
    //Definicion Metodos
public:
    void crearEstacion(std::string _nombreEstacion, int _codigoEstacion, std::string _gerente, short _region, float _ubicacionGPS[2], int preciosCombustible[3][3]);
    void eliminarEstacion(int indice);
    int getnumeroEstaciones_actual();
    std::string getnombreEmpresa();
    int calculoMontoTotal();
    void cambiarPrecio(int precioBase, int precioAumentar);

};

#endif // EMPRESA_H
