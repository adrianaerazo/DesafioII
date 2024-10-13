#include "empresa.h"
#include "estaciones.h"
#include "surtidores.h"
#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

void menuPrincipal(Empresa& miEmpresa);
void menuEmpresa(Empresa& miEmpresa);
void menuEstaciones();
void menuSurtidorVenta(Surtidores& surtidor);

int main()
{
    // Inicializar la semilla del generador de números aleatorios
    srand(static_cast<int>(time(0)));

    // Crear una empresa con capacidad para 5 estaciones
    Empresa miEmpresa("Terpel", 5);

    // Definición de precios de combustible
    int preciosCombustible[3][3] =
        {
            {1000, 4000, 7000}, // Precios para la región Sur
            {2000, 5000, 8000}, // Precios para la región Centro
            {3000, 6000, 10000}  // Precios para la región Norte
        };

    // Agregar estaciones iniciales
    float gps1[] = {19.4326, -99.1332}; // Ubicación de la estación 1
    float gps2[] = {40.7128, -74.0060}; // Ubicación de la estación 2
    miEmpresa.crearEstacion("Estacion A", 101, "Juan Perez", 1, gps1, preciosCombustible);
    miEmpresa.crearEstacion("Estacion B", 102, "Maria Gomez", 2, gps2, preciosCombustible);

    // Mostrar el menú principal
    menuPrincipal(miEmpresa);

    return 0;
}

void menuPrincipal(Empresa& miEmpresa)
{
    int opcion = 0;

    do
    {
        std::cout << "\nMenu Principal" << std::endl;
        std::cout << "1. Gestionar Empresa." << std::endl;
        std::cout << "2. Gestionar Estaciones." << std::endl;
        std::cout << "3. Realizar venta de combustible." << std::endl;
        std::cout << "4. Salir." << std::endl;
        std::cout << "Seleccione la opcion que desee consultar: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            menuEmpresa(miEmpresa);
            break;
        }
        case 2:
        {
            menuEstaciones();
            // Aquí puedes agregar la logica para elegir una estación
            // temporalmente llamamos a la primera estación
            // pero deberías permitir al usuario seleccionar una
           // if (miEmpresa.getnumeroEstaciones_actual() > 0)
            //{
            //    menuEstaciones(miEmpresa.getEstacion(0)); // Pasa la primera estacion como ejemplo
            //}
            //else
            //{
            //    std::cout << "No hay estaciones disponibles." << std::endl;
            //}
            break;
        }
        case 3:
        {
            // De nuevo, temporalmente elegimos la primera estación
            Surtidores surtidor; // Debes tener un surtidor adecuado asociado a la estación
            menuSurtidorVenta(surtidor);
            break;
        }
        case 4:
        {
            std::cout << "Saliendo del programa." << std::endl;
            break;
        }
        default:
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        }
    } while (opcion != 4);
}

void menuEmpresa(Empresa& miEmpresa)
{
    int opcion = 0;

    do
    {
        std::cout << "\nMenu Gestionar Empresa" << std::endl;
        std::cout << "1. Agregar estaciones de servicio." << std::endl;
        std::cout << "2. Eliminar una E/S de la red nacional." << std::endl;
        std::cout << "3. Calcular el monto total de las ventas en cada E/S del pais, discriminado por categoria de combustible." << std::endl;
        std::cout << "4. Fijar los precios del combustible para toda la red." << std::endl;
        std::cout << "5. Volver al menu principal." << std::endl;
        std::cout << "Seleccione la opcion que desee consultar: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            // Agregar estaciones de servicio
            std::string nombreEstacion;
            int codigoEstacion;
            std::string gerente;
            short region;
            float ubicacionGPS[2];

            std::cout << "Ingrese el nombre de la estacion: ";
            std::cin >> nombreEstacion;
            std::cout << "Ingrese el código de la estacion: ";
            std::cin >> codigoEstacion;
            std::cout << "Ingrese el nombre del gerente: ";
            std::cin >> gerente;
            std::cout << "Ingrese la región (0=Sur, 1=Centro, 2=Norte): ";
            std::cin >> region;
            std::cout << "Ingrese la latitud: ";
            std::cin >> ubicacionGPS[0];
            std::cout << "Ingrese la longitud: ";
            std::cin >> ubicacionGPS[1];

            int preciosCombustible[3][3] =
                {
                    {1000, 4000, 7000},
                    {2000, 5000, 8000},
                    {3000, 6000, 10000}
                };

            miEmpresa.crearEstacion(nombreEstacion, codigoEstacion, gerente, region, ubicacionGPS, preciosCombustible);
            break;
        }
        case 2:
        {
            // Eliminar una E/S de la red nacional
            int indice;
            std::cout << "Ingrese el indice de la estacion a eliminar: ";
            std::cin >> indice;
            miEmpresa.eliminarEstacion(indice);
            break;
        }
        case 3:
        {
            // Calcular el monto total de las ventas en cada E/S
            miEmpresa.calculoMontoTotal();
            break;
        }
        case 4:
        {
            // Fijar precios del combustible para toda la red
            int precioBase, precioAumentar;
            std::cout << "Ingrese el precio base: ";
            std::cin >> precioBase;
            std::cout << "Ingrese el incremento de precio: ";
            std::cin >> precioAumentar;
            miEmpresa.cambiarPrecio(precioBase, precioAumentar);
            break;
        }
        case 5:
        {
            std::cout << "Volviendo al menu principal." << std::endl;
            break;
        }
        default:
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        }
    } while (opcion != 5);
}

void menuEstaciones()
{
    int opcion = 0;

    do {
        std::cout << "\nMenu Gestionar Estaciones" << std::endl;
        std::cout << "1. Agregar surtidor a la estacion." << std::endl;
        std::cout << "2. Eliminar surtidor de la estacion." << std::endl;
        std::cout << "3. Activar surtidor de la estacion." << std::endl;
        std::cout << "4. Desactivar surtidor de la estacion." << std::endl;
        std::cout << "5. Historial de transacciones de cada surtidor." << std::endl;
        std::cout << "6. Reporte de ventas por categoria de combustible." << std::endl;
        std::cout << "7. Volver al menu principal." << std::endl;
        std::cout << "Seleccione la opcion que desee consultar: ";
        std::cin >> opcion;

        // Aquí debes implementar la funcionalidad para cada opción
        switch (opcion)
        {
        case 1:
        {
            // Lógica para agregar surtidor
            break;
        }
        case 2:
        {
            // Lógica para eliminar surtidor
            break;
        }
        case 7:
        {
            std::cout << "Volviendo al menu principal." << std::endl;
            break;
        }
        default:
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        }
    }
    while (opcion != 7);
}

void menuSurtidorVenta(Surtidores& surtidor)
{
    int opcion = 0;

    do
    {
        std::cout << "\nMenu Realizar Venta" << std::endl;
        std::cout << "1. Ver surtidores activos." << std::endl;
        std::cout << "2. Volver al menu principal." << std::endl;
        std::cout << "Seleccione la opcion que desee consultar: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            // Lógica para ver surtidores activos
            break;
        }
        case 2:
        {
            std::cout << "Volviendo al menu principal." << std::endl;
            break;
        }
        default:
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        }
    }
    while (opcion != 2);
}
