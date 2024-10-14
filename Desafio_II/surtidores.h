#ifndef SURTIDORES_H
#define SURTIDORES_H
#include<iostream>


class Surtidores
{
private:
    //Definir atributos
    int codigoSurtidor;
    std::string modeloSurtidor;
    bool surtidorActivo;

public:
    Surtidores();
    Surtidores(int _codigoSurtidor, std::string _modeloSurtidor);

    //Definir metodos
    void ventaSurtidor(float _metodo_pago, float _cant_L, int tipo_gal);



private:

};

#endif // SURTIDORES_H
