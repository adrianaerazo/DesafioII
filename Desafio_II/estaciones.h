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
    std::string region;
    float ubicacionGPS[2];

public:
    // Constructor
    Estaciones(std::string _nombreEstacion, int _codigoEstacion, std::string _gerente, std::string _region, float _ubicacionGPS[2]);
    //Definir metodos

    //Definir set y get Nombre Estacion
    void setNombreEstacion(std::string _nombreEstacion);
    std::string getNombreEstacion() const;

    //Definir set y get Codigo Estacion
    void setCodigoEstacion(int _codigoEstacion);
    int getCodigoEstacion() const;

    //Definir set y get Gerente
    void setGerente(std::string _gerente);
    std::string getGerente() const;

    void agregarSurtidor(int codigoSurtidor, std::string modeloSurtidor);
    void eliminarSurtidor(int codigoSurtidor, std::string modeloSurtidor);
    void calcularVentasPorCategoria();
    void fijarPreciosCombustible();
    void actualizarDisponibilidadCombustible();
    void simularVentaCombustible();
    bool verificarFugaCombustible();
};

#endif // ESTACIONES_H
