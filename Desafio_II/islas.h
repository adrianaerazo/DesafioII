#ifndef ISLAS_H
#define ISLAS_H
#include<iostream>
#include "surtidores.h"


class Islas
{
private:
    //Definir atributos
    int NumSurtidores_actual; // numero de surtidores asignados a la isla
    int CapacidadSurtidores; // capacidad actual de surtidores que la isla soporta
    int Codigo; // Id Isla para identificarla en la estacion
    Surtidores* arregloSurtidores; //  arreglo de Surtidores
    

public:
    Islas();
    Islas(int _NumSurtidores, int _Codigo);
    ~Islas(); // Destructor
    void asignarSurtidor( std::string _modeloSurtidor);
    void eliminarSurtidor(int _codigoSurtidor);



private:

};

#endif // ISLAS_H