#include "surtidores.h"


Surtidores::Surtidores()
{
    codigoSurtidor=0;
    modeloSurtidor="";
    surtidorActivo=false;

}

Surtidores::Surtidores(int _codigoSurtidor, std::string _modeloSurtidor)
{
    codigoSurtidor=_codigoSurtidor;
    modeloSurtidor=_modeloSurtidor;
    surtidorActivo=true;

}

 void Surtidores::ventaSurtidor(float _metodo_pago, float _cant_L, int tipo_gal)
 {
    
 }

