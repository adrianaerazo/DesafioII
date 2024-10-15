#ifndef SURTIDORES_H
#define SURTIDORES_H
#include<iostream>


class Surtidores
{
public:
    //Definir atributos
    int codigoSurtidor=0;
    std::string modeloSurtidor={0};
    bool surtidorActivo;

    int historial_Ventas[4]={0}; // venta total, venta regular ,venta prem , venta eco
    int** historial_Transacciones=nullptr; // info: metodo_pago, cantidad L vendida ,fecha ,hora, categoria de gasolina

    int NumTransacciones=0;// Capacidad de las transacciones
    int NumTransaccionesActuales=0; // Numero de transacciones actuales

public:
    //Definir metodos
    Surtidores();
    Surtidores(int _codigoSurtidor, std::string _modeloSurtidor);//constructor - crear surtidor

    void redimensionarTransacciones();
    void imprimirTransacciones();
    
    int*  ventaSurtidor(int _metodo_pago, int _cant_L, int tipo_gal, int _Capacidad_tanque, int preciosCombustible);

private:

};

#endif // SURTIDORES_H
