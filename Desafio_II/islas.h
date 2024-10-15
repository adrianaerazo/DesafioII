#ifndef ISLAS_H
#define ISLAS_H
#include<iostream>
#include "surtidores.h"


class Islas
{
public:
    //Definir atributos
    int NumSurtidores_actual=0; // numero de surtidores asignados a la isla
    int CapacidadSurtidores=0; // capacidad actual de surtidores que la isla soporta
    int Codigo=0; // Id Isla para identificarla en la estacion
    Surtidores* arregloSurtidores=nullptr; //  arreglo de Surtidores
    

public:
    Islas();
    Islas(int _NumSurtidores, int _Codigo);//constructor-crear isla
    ~Islas(); // Destructor

    void asignarSurtidor( std::string _modeloSurtidor);
    void eliminarSurtidor(int _codigoSurtidor);
    int getNumeroTotalSurtidores();
    int getCodigoIsla();


private:

};

#endif // ISLAS_H
