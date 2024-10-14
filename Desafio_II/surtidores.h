#ifndef SURTIDORES_H
#define SURTIDORES_H
#include<iostream>


class Surtidores
{
public:
    //Definir atributos
    int codigoSurtidor;
    std::string modeloSurtidor;
    bool surtidorActivo;

public:
    Surtidores();
    Surtidores(int _codigoSurtidor, std::string _modeloSurtidor);
    void redimensionarTransacciones();
    void imprimirTransacciones();
    
    int historial_Ventas[4]; // venta total, venta regular ,venta prem , venta eco
    int** historial_Transacciones; ; // info: metodo_pago, cantidad L vendida ,fecha ,hora, categoria de gasolina
    int NumTransacciones;
    int Num_ventas;

    //Definir metodos
    int*  ventaSurtidor(int _metodo_pago, int _cant_L, int tipo_gal, int _Capacidad_tanque, int preciosCombustible);



private:

};

#endif // SURTIDORES_H
