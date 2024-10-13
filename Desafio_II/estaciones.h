#ifndef ESTACIONES_H
#define ESTACIONES_H

#include <string>

class Estaciones
{
private:
    // Atributos
    std::string nombreEstacion;
    int codigoEstacion;
    std::string gerente;
    short region;//0=sur, 1=centro, 2=norte
    float ubicacionGPS[2];//Latitud y longitud
    int preciosCombustible[3][3];//arreglo de precios 1x3
    short Capacidad_tanque[3];//los 3 valores, el regular, premium, ecoextra
    
public:
    float historial_Ventas[4]; // venta total, venta regular ,venta prem , venta eco
    float *historial_Transacciones; // info: metodo_pago, cantidad L vendida ,fecha ,hora, categoria de gasolina
    int numero_ventas;
    //float historial_Transacciones[5];

public:
    // Constructor
    Estaciones();
    Estaciones(std::string _nombreEstacion, short _codigoEstacion, std::string _gerente, short _region, float _ubicacionGPS[2], int _preciosCombustible[3][3]);
    
    //Definir metodos

    void venta(float _metodo_pago, float _cant_L, float _fecha, float _hora, int tipo_gal);

    //Definir set y get Nombre Estacion
    void setNombreEstacion(std::string _nombreEstacion);
    std::string getNombreEstacion() const;

    //Definir set y get Codigo Estacion
    void setCodigoEstacion(int _codigoEstacion);
    int getCodigoEstacion() const;

    //Definir set y get Gerente
    void setGerente(std::string _gerente);
    std::string getGerente() const;
    int getregion();

    void actualizarPrecios(int nuevosPrecios[3][3]);
    void agregarSurtidor(int codigoSurtidor, std::string modeloSurtidor);
    void eliminarSurtidor(int codigoSurtidor, std::string modeloSurtidor);
    void calcularVentasPorCategoria();
    void actualizarDisponibilidadCombustible();
    void simularVentaCombustible();
    bool verificarFugaCombustible();
};

#endif // ESTACIONES_H
