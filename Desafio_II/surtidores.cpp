#include "surtidores.h"
#include <ctime>     // Para tiempo


Surtidores::Surtidores()
{
    codigoSurtidor=0;
    modeloSurtidor="";
    surtidorActivo=false;
    NumTransaccionesActuales=0;
    NumTransacciones=20;
    // Inicializar el arreglo bidimensional con la capacidad inicial
    historial_Transacciones = new int*[NumTransacciones];
    for (int i = 0; i < NumTransacciones; i++)
    {
        historial_Transacciones[i] = new int[6];  // Cada fila tendrá 6 columnas
    }

}

Surtidores::Surtidores(int _codigoSurtidor, std::string _modeloSurtidor)
{
    codigoSurtidor=_codigoSurtidor;
    modeloSurtidor=_modeloSurtidor;
    surtidorActivo=true;

}


void Surtidores::redimensionarTransacciones()
{
    
    // Aumentar la capacidad al doble
    int nuevaCapacidad = NumTransacciones * 2;

    // Crear un nuevo arreglo bidimensional con la nueva capacidad
    int** nuevoArreglo = new int*[nuevaCapacidad];
    for (int i = 0; i < nuevaCapacidad; i++) {
        nuevoArreglo[i] = new int[6];  // Cada fila sigue teniendo 6 columnas
    }

    // Copiar los datos del arreglo antiguo al nuevo
    for (int i = 0; i < NumTransaccionesActuales; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            nuevoArreglo[i][j] = historial_Transacciones[i][j];
        }
    }

    // Liberar la memoria del arreglo antiguo
    for (int i = 0; i < NumTransacciones; i++)
    {
        delete[] historial_Transacciones[i];
    }
    delete[] historial_Transacciones;

    // Asignar el nuevo arreglo y actualizar la capacidad
    historial_Transacciones = nuevoArreglo;
    NumTransacciones = nuevaCapacidad;

}

void Surtidores::imprimirTransacciones()
{
    std::cout << "Detalles de las transacciones:\n";
    std::cout << "---------------------------------------\n";
    std::cout << "Método Pago | Cantidad (L) | Fecha       | Hora       | Tipo Gasolina | Precio\n";
    std::cout << "---------------------------------------\n";

    for (int i = 0; i < NumTransacciones; i++)
    {
        std::cout << historial_Transacciones[i][0] << "          | "  // Método de pago
                  << historial_Transacciones[i][1] << "          | "  // Cantidad en litros
                  << historial_Transacciones[i][2] << " | "           // Fecha
                  << historial_Transacciones[i][3] << " | "           // Hora
                  << historial_Transacciones[i][4] << "          | "  // Tipo de gasolina
                  << historial_Transacciones[i][5] << "\n";           // Precio
    }

    std::cout << "---------------------------------------\n";
}

 int*  Surtidores::ventaSurtidor(int _metodo_pago, int _cant_L, int tipo_gal, int _Capacidad_tanque, int preciosCombustible)
 {
    int Capacidad_tanque=_Capacidad_tanque;
    // Obtener el tiempo actual
    std::time_t now = std::time(0);  // Tiempo actual en segundos desde Epoch
    std::tm* localTime = std::localtime(&now);  // Convertir a la hora local

    // Almacenar la fecha y hora como enteros
    int fecha = (localTime->tm_year + 1900) * 10000 + (localTime->tm_mon + 1) * 100 + localTime->tm_mday; // YYYYMMDD
    int hora = localTime->tm_hour * 10000 + localTime->tm_min * 100 + localTime->tm_sec; // HHMMSS

    
    //venta
    
    //int precio_cobrar=0; almacena la operacion de la multiplicacion del precio * la cantidad de litros
    int precio_cobrar=0;
    //int aux_capacidad=0; almacena el valor, para verificar si el combustible del tanque es suficiente para la venta,
    //si la operacion obtiene como resultado un numero negativo, quiere decir que el tanque no cuenta con lo suficiente
    int aux_capacidad =  Capacidad_tanque - _cant_L;
    
    //verificar si el tanque esta contiene la cantidad necesaria para la venta
    //si la cantidad solicitada es negativa, se vende lo que hay y se vacia el tanque
    if (aux_capacidad<=0)
    {
        //la cantidad de litros solicitada pasa a ser la cantidad que hay en el tanque
        _cant_L=Capacidad_tanque;//se vende lo del tanque
        //se actualiza el tanque
        Capacidad_tanque=0; //evitar negativos
        //desactivar surtidores
    }
    else
    {
        //si el tanque puede vender sin problema, se actualiza la cantidad de la categoria en especifico del tanque
        Capacidad_tanque=_Capacidad_tanque-_cant_L;
    }
    
    //Informacion de venta
    
    if (NumTransaccionesActuales==NumTransacciones)
    { // si el num ventas llega al max de transacciones, aumentar espacio
        redimensionarTransacciones();
    }
    
    // Asignar los valores a la siguiente fila disponible
    historial_Transacciones[NumTransaccionesActuales][0] = _metodo_pago;
    historial_Transacciones[NumTransaccionesActuales][1] = _cant_L;
    historial_Transacciones[NumTransaccionesActuales][2] = fecha;
    historial_Transacciones[NumTransaccionesActuales][3] = hora;
    historial_Transacciones[NumTransaccionesActuales][4] = tipo_gal;
    
    //Guardar valores totales de ventas
    precio_cobrar=preciosCombustible*_cant_L; //Las columnas son Sur/Centro/Norte, las filas son el tipo de gasolina, Regular/Premium/Eco
    historial_Ventas[0]=historial_Ventas[0]+precio_cobrar ; // venta total
    historial_Ventas[tipo_gal+1]=historial_Ventas[tipo_gal+1]+precio_cobrar ; // venta tipo gasolina

    //asignar el valor monetario al historial de transacciones
    historial_Transacciones[NumTransaccionesActuales][5] = precio_cobrar; //precio por transaccion cobrada
    
    imprimirTransacciones();
    

    NumTransaccionesActuales=NumTransaccionesActuales+1;
    
    // Crear un arreglo para retornar los resultados
    int* resultados = new int[2];
    resultados[0] = Capacidad_tanque;  // Capacidad restante
    resultados[1] = NumTransaccionesActuales;         // Número total de ventas

    return resultados; // Retornar el arreglo de resultados
    
 }

