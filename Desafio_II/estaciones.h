#ifndef ESTACIONES_H
#define ESTACIONES_H

#include <string>
#include "islas.h"

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
    Islas* arregloIslas; //  arreglo de Surtidores
    
public:
    int aux_Surtidore_sinAsignar=0; 
    int numero_total_surtidores; //aleatorio entre 2 y 12
    int historial_Ventas[4]; // venta total, venta regular ,venta prem , venta eco
    int** historial_Transacciones; ; // info: metodo_pago, cantidad L vendida ,fecha ,hora, categoria de gasolina
    int numero_ventas;
    int NumIslas_actual;
    int CapacidadIslas;
    int NumTransacciones;
    void crearIsla(int _CapacidadSurtidores);
    void eliminarIsla(int _codigoIsla);
    //float historial_Transacciones[5];

public:
    // Constructor
    Estaciones();
    Estaciones(std::string _nombreEstacion, short _codigoEstacion, std::string _gerente, short _region, float _ubicacionGPS[2], int _preciosCombustible[3][3], int _CapacidadIslas);
    ~Estaciones(); // Destructor
    //Definir metodos

    void venta(int _metodo_pago, int _cant_L, int tipo_gal);
    void redimensionarTransacciones();

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
