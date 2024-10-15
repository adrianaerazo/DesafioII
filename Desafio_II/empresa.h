#ifndef EMPRESA_H
#define EMPRESA_H
#include<iostream>
#include "estaciones.h"

class Empresa
{
    //Definicion Atributos
private:
    std::string nombreEmpresa=" ";   //Nombre de la empresa
    int preciosCombustible[3][3]={0};//Las columnas son Sur/Centro/Norte, las filas son el tipo de gasolina, Regular/Premium/EcoExtra
    int numeroEstaciones_actual=0; // Número actual de estaciones
    int numeroEstaciones_total=0;  // Número Total de estaciones


public:
    int ventasTotales=0; //valor de ventas totales
    Estaciones* arregloEstaciones=nullptr; //  arreglo de Estaciones


    //Definicion Metodos
public:
    Empresa(std::string _nombreEmpresa, int _numeroEstaciones ); //constructor
    ~Empresa(); // Destructor

    void crearEstacion(std::string _nombreEstacion,int codigoEstacion,  std::string _gerente, short _region, float _ubicacionGPS[2], int preciosCombustible[3][3], int _CapacidadIslas);
    void eliminarEstacion(int indice);
    void getPreciosCombustible(int precios[3][3]);
    int getnumeroEstaciones_actual();
    std::string getnombreEmpresa();
    int calculoMontoTotal();
    void cambiarPrecio(int precioBase, int precioAumentar);

};

#endif // EMPRESA_H
