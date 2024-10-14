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


public:
    int ventasTotales;
    Estaciones* arregloEstaciones; //  arreglo de Estaciones

    Empresa(std::string _nombreEmpresa, int _numeroEstaciones ); //constructor
    ~Empresa(); // Destructor


    //Definicion Metodos

    void crearEstacion(std::string _nombreEstacion,int codigoEstacion,  std::string _gerente, short _region, float _ubicacionGPS[2], int preciosCombustible[3][3], int _CapacidadIslas);
    void eliminarEstacion(int indice);
    int getnumeroEstaciones_actual();
    std::string getnombreEmpresa();
    int calculoMontoTotal();
    void cambiarPrecio(int precioBase, int precioAumentar);

    // Método get que devuelve un puntero al primer elemento del arreglo
    int (*getPreciosCombustible())[3];

};

#endif // EMPRESA_H
