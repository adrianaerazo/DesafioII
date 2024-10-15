#include "empresa.h"
#include "estaciones.h"
#include "surtidores.h"
#include "islas.h"
#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

void menuPrincipal(Empresa& empresaTerMax);
void menuEmpresa(Empresa& empresaTerMax);
void menuEstaciones(Empresa& empresaTerMax);
void menuSurtidorVenta();

int main()
{
    // Inicializar la semilla del generador de numeros aleatorios
    srand(static_cast<int>(time(0)));

    // Crear una empresa con capacidad para 10 estaciones
    Empresa empresaTerMax("TerMax", 10);

    // Mostrar el menu principal
    menuPrincipal(empresaTerMax);

    return 0;
}
//el & es para acceder a su posicion en memoria y dado el caso, poder cambiar su valor
void verificarOpcion(int& ingresado, int minimo, int maximo)
{
    bool esValido = false;

    while (!esValido)
    {
        // Verificar si la entrada es valida (numero) y esta dentro del rango
        if (std::cin && ingresado >= minimo && ingresado <= maximo)
        {
            esValido = true;  // Entrada válida
        }
        else
        {
            std::cin.clear(); // Limpiar el estado de error (por si ingreso un caracter no numerico)
            std::cin.ignore(1000, '\n'); // Limpiar el resto de la linea, puede eliminar hasta mil carceteres hsta encontrar el salto de linea

            std::cout << "Opcion invalida, por favor ingrese un numero valido dentro del rango." << std::endl;
            std::cout << "Ingrese una opcion entre " << minimo << " y " << maximo << ". "<<std::endl;
        }
    }
}
void menuPrincipal(Empresa &empresaTerMax)
{
    int opcion=0;

    do
    {
        std::cout << "Empresa TerMax" << std::endl;
        std::cout<<std::endl;
        std::cout << "\nMenu Principal" << std::endl;
        std::cout<<std::endl;
        std::cout << "1. Gestionar Empresa." << std::endl;
        std::cout << "2. Gestionar Estaciones." << std::endl;
        std::cout << "3. Realizar venta de combustible." << std::endl;
        std::cout << "4. Salir." << std::endl;
        std::cout << "Seleccione la opcion que desee consultar: ";
        std::cin >> opcion;

        verificarOpcion(opcion, 1, 4);

        switch (opcion)
        {
        case 1:
        {
            menuEmpresa(empresaTerMax);
            break;
        }
        case 2:
        {
            menuEstaciones(empresaTerMax);
            break;
        }
        case 3:
        {
            menuSurtidorVenta();
            break;
        }
        case 4:
        {
            std::cout << "Saliendo del programa." << std::endl;
            break;
        }
        default:
            std::cout << std::endl;
        }
    }
    while (opcion != 4);
}

void menuEmpresa(Empresa &empresaTerMax)
{
    int opcion = 0;

    do
    {
        std::cout<<std::endl;
        std::cout << "Empresa TerMax" << std::endl;
        std::cout<<std::endl;
        std::cout << "\nMenu Gestionar Empresa" << std::endl;
        std::cout<<std::endl;
        std::cout << "1. Agregar estaciones de servicio." << std::endl;
        std::cout << "2. Eliminar una estacion de servicio." << std::endl;
        std::cout << "3. Calcular el monto total de las ventas en cada E/S del pais, discriminado por categoria de combustible." << std::endl;
        std::cout << "4. Cambiar los precios del combustible para toda la red." << std::endl;
        std::cout << "5. Volver al menu principal." << std::endl;
        std::cout << "Seleccione la opcion que desee consultar: ";
        std::cin >> opcion;

        verificarOpcion(opcion, 1, 5);

        switch (opcion)
        {
        case 1:
        {
            // Agregar estaciones de servicio
            std::cout<<std::endl;
            std::cout << "Empresa TerMax" << std::endl;
            std::cout<<std::endl;
            std::cout<<std::endl;
            std::cout << "Datos para crear la estacion: "<<std::endl;
            std::string nombreEstacion;
            int codigoEstacion;
            std::string gerente;
            short region;
            float ubicacionGPS[2];
            short islas;

            std::cout << "Ingrese el nombre de la estacion: ";
            std::cin >> nombreEstacion;
            std::cout << "Ingrese el codigo de la estacion: ";
            std::cin >> codigoEstacion;
            std::cout << "Ingrese el nombre del gerente: ";
            std::cin >> gerente;
            std::cout << "Ingrese la region (0=Sur, 1=Centro, 2=Norte): ";
            std::cin >> region;
            std::cout << "Ingrese la latitud: ";
            std::cin >> ubicacionGPS[0];
            std::cout << "Ingrese la longitud: ";
            std::cin >> ubicacionGPS[1];
            std::cout<<"Ingresa la cantidad de islas: ";
            std::cin>>islas;


            // Declaramos la matriz para guardar los precios del combustible
            int preciosCombustible[3][3];

            // Llamar al metodo que copia los precios de la empresa a la matriz local
            empresaTerMax.getPreciosCombustible(preciosCombustible);

            empresaTerMax.crearEstacion(nombreEstacion, codigoEstacion, gerente, region, ubicacionGPS, preciosCombustible, islas);
            std::cout<<std::endl;

            std::cout<<"Actualizacion de estaciones: "<<std::endl;
            std::cout<<std::endl;
            for (int i = 0; i <= empresaTerMax.getnumeroEstaciones_actual(); i++)
            {
                for(int j = 0; j <= empresaTerMax.getnumeroEstaciones_actual(); j++)
                {
                    std::cout <<j<<". Estacion: ";
                    std::cout << empresaTerMax.arregloEstaciones[i].getNombreEstacion() << std::endl;
                }
            }

            int opcion;
            std::cout<<std::endl;
            std::cout<<"Seleccione una opcion: "<<std::endl;
            std::cout<<"1. Volver al menu gestion de empresa. "<<std::endl;
            std::cout<<"2. Volver al menu principal. "<<std::endl;
            std::cout<<"Ingrese la opcion: ";
            std::cin>>opcion;
            verificarOpcion(opcion, 1, 2);
            switch (opcion)
            {
            case 1:
            {
              menuEmpresa(empresaTerMax);
            }
            default:
            {
                menuPrincipal(empresaTerMax);
            }
            }
            break;
        }
        case 2:
        {
            std::cout<<std::endl;
            std::cout << "Empresa TerMax" << std::endl;
            std::cout<<std::endl;
            // Eliminar una E/S de la red nacional
            std::cout<<std::endl;
            std::cout<<"Lista de estaciones: "<<std::endl;
            std::cout<<std::endl;

            for (int i = 0; i < empresaTerMax.getnumeroEstaciones_actual(); i++)
            {
                for(int j = 0; j <= empresaTerMax.getnumeroEstaciones_actual(); j++)
                {
                    std::cout <<j<<". Estacion: ";
                    std::cout << empresaTerMax.arregloEstaciones[i].getNombreEstacion() << std::endl;
                }
            }

            std::cout<<std::endl;
            std::cout<<"Datos para eliminar la estacion: "<<std::endl;

            int indice;
            std::cout << "Ingrese la opcion de la estacion a eliminar: ";
            std::cin >> indice;

            verificarOpcion(indice,0,empresaTerMax.getnumeroEstaciones_actual() );
            empresaTerMax.eliminarEstacion(indice);

            std::cout<<"Actualizacion de estaciones: "<<std::endl;
            std::cout<<std::endl;
            for (int i = 0; i < empresaTerMax.getnumeroEstaciones_actual(); i++)
            {
                for(int j = 0; j <= empresaTerMax.getnumeroEstaciones_actual(); j++)
                {
                    std::cout <<j<<". Estacion: ";
                    std::cout << empresaTerMax.arregloEstaciones[i].getNombreEstacion() << std::endl;
                }
            }
            //opcion volver al menu
            int opcion;
            std::cout<<std::endl;
            std::cout<<"Seleccione una opcion: "<<std::endl;
            std::cout<<"1. Volver al menu gestion de empresa. "<<std::endl;
            std::cout<<"2. Volver al menu principal. "<<std::endl;
            std::cout<<"Ingrese la opcion: ";
            std::cin>>opcion;
            verificarOpcion(opcion, 1, 2);
            switch (opcion)
            {
            case 1:
            {
                menuEmpresa(empresaTerMax);
            }
            default:
            {
                menuPrincipal(empresaTerMax);
            }
            }

            break;
        }
        case 3:
        {
            // Calcular el monto total de las ventas en cada E/S
            std::cout<<std::endl;
            std::cout << "Empresa TerMax" << std::endl;
            std::cout<<std::endl;
            std::cout << "Calculo ventas totales de cada estacion: "<< std::endl;

            // Llamamos al metodo para calcular y mostrar las ventas totales de todas las estaciones
            empresaTerMax.calculoMontoTotal();  // imprime los detalles de cada estación
            std::cout<<std::endl;

            //opcion volver al menu
            int opcion;
            std::cout<<std::endl;
            std::cout<<"Seleccione una opcion: "<<std::endl;
            std::cout<<"1. Volver al menu gestion de empresa. "<<std::endl;
            std::cout<<"2. Volver al menu principal. "<<std::endl;
            std::cout<<"Ingrese la opcion: ";
            std::cin>>opcion;
            verificarOpcion(opcion, 1, 2);
            switch (opcion)
            {
            case 1:
            {
                menuEmpresa(empresaTerMax);
            }
            default:
            {
                menuPrincipal(empresaTerMax);
            }
            }
            break;
        }
        case 4:
        {
            // Fijar precios del combustible para toda la red
            std::cout << "Cambiar los precios para toda la red: " << std::endl;
            std::cout<<std::endl;
            std::cout << "A TENER EN CUENTA:" << std::endl;
            std::cout << "El precio base es el que se toma como valor constante, "<<std::endl;
            std::cout << "el incremento de precio es para hacer las cuentas automaticas. " << std::endl;
            std::cout << std::endl;

            //realizar los cambios
            int precioBase, precioAumentar;
            std::cout << "Ingrese el precio base: ";
            std::cin >> precioBase;
            std::cout << "Ingrese el incremento de precio: ";
            std::cin >> precioAumentar;
            empresaTerMax.cambiarPrecio(precioBase, precioAumentar);

            // Mostrar actualización de cambios
            std::cout << std::endl;
            std::cout << "Actualizacion de cambios: " << std::endl;
            std::cout << std::endl;

            for (int i = 0; i < 3; i++)
            {
                // Obtener la región de la estación
                short region = empresaTerMax.arregloEstaciones[i].getRegion();
                std::string regionesArreglo[3] = { "Sur", "Centro", "Norte" };
                std::cout << "Region: " << regionesArreglo[region] << std::endl;

                // Declaramos la matriz para guardar los precios del combustible (3x3)
                int preciosCombustible[3][3];

                // Llamar al metodo que copia los precios de la empresa a la matriz local
                empresaTerMax.getPreciosCombustible(preciosCombustible);

                // Imprimir los precios de la estación para cada tipo de combustible
                std::cout << "Precios de combustible: " << std::endl;
                std::cout << "Precio Gasolina Regular: " << preciosCombustible[0][i] << std::endl;
                std::cout << "Precio Gasolina Premium: " << preciosCombustible[1][i] << std::endl;
                std::cout << "Precio Gasolina EcoExtra: " << preciosCombustible[2][i] << std::endl;

                std::cout << std::endl;  // Salto de línea para separar las estaciones
            }

            //opcion volver al menu
            int opcion;
            std::cout<<std::endl;
            std::cout<<"Seleccione una opcion: "<<std::endl;
            std::cout<<"1. Volver al menu gestion de empresa. "<<std::endl;
            std::cout<<"2. Volver al menu principal. "<<std::endl;
            std::cout<<"Ingrese la opcion: ";
            std::cin>>opcion;

            verificarOpcion(opcion, 1, 2);
            switch (opcion)
            {
            case 1:
            {
                menuEmpresa(empresaTerMax);
            }
            default:
            {
                menuPrincipal(empresaTerMax);
            }
            }
            break;
        }
        case 5:
        {
            menuPrincipal(empresaTerMax);
            break;
        }
        default:
            std::cout << std::endl;
        }
    }
    while (opcion != 5);
}

void menuEstaciones(Empresa &empresaTerMax)
{
    int opcion = 0;

    do
    {
        std::cout << "\nMenu Gestionar Estaciones" << std::endl;
        std::cout<<std::endl;
        std::cout << "1. Agregar surtidor a la estacion." << std::endl;
        std::cout << "2. Eliminar surtidor de la estacion." << std::endl;
        std::cout << "3. Activar surtidor de la estacion." << std::endl;
        std::cout << "4. Desactivar surtidor de la estacion." << std::endl;
        std::cout << "5. Historial de transacciones de cada surtidor." << std::endl;
        std::cout << "6. Reporte de ventas por categoria de combustible." << std::endl;
        std::cout << "7. Volver al menu principal." << std::endl;
        std::cout << "Seleccione la opcion que desee consultar: ";
        std::cin >> opcion;

        verificarOpcion(opcion, 1, 7);

        // Aqui debes implementar la funcionalidad para cada opcion
        switch (opcion)
        {
        case 1:
        {
            std::cout << "Agregar surtidor a la estacion" << std::endl;
            std::cout << std::endl;
            std::cout << "LISTADO DE ESTACIONES" <<std::endl;

            for (int i = 0; i <= empresaTerMax.getnumeroEstaciones_actual(); i++)
            {
                for(int j = 0; j <= empresaTerMax.getnumeroEstaciones_actual(); j++)
                {
                    std::cout <<j<<". Estacion: ";
                    std::cout << empresaTerMax.arregloEstaciones[i].getNombreEstacion() << std::endl;
                }
            }
            int opcion;
            std::cout <<std::endl;
            std::cout << "Seleccione la estacion a la que le quiere agregar el surtidor: ";
            std::cin>>opcion;

            verificarOpcion(opcion, 1, empresaTerMax.getnumeroEstaciones_actual());

            // Obtener la estacion seleccionada
            for (int i = 0; i < empresaTerMax.getnumeroEstaciones_actual(); i++)
            {
                // Imprimir el nombre de la estacion
                std::cout << i << ". Estacion: " << empresaTerMax.arregloEstaciones[i].getNombreEstacion() << std::endl;

                // Obtener la region de la estacion
                short region = empresaTerMax.arregloEstaciones[i].getRegion();
                std::string regionesArreglo[3]={"Sur", "Centro","Norte"};
                std::cout << "Region: " << regionesArreglo[region] << std::endl;
            }


            //imprimir enunciado
            std::cout<<std::endl;
            std::cout<<"Islas: "<<std::endl;
            std::cout<<std::endl;

            std::cout<<std::endl;
            std::cout<<"Sutidores Activos: "<<std::endl;

            //opciones de los surtidores
            int opcionsurti=0;
            std::cout<<std::endl;
            std::cout << "Opciones: "<<std::endl;
            std::cout << "1. Crear Isla "<<std::endl;
            std::cout << "2. Crear Surtidor "<<std::endl;
            std::cout << "Ingrese la opcion:  ";
            std::cin>>opcionsurti;
            verificarOpcion(opcionsurti, 1, 2);


            //actualizacion de islas
            std::cout<<std::endl;
            std::cout << "Actualizacion de islas y surtidores "<<std::endl;
            // Obtener la estacion seleccionada
            for (int i = 0; i < empresaTerMax.getnumeroEstaciones_actual(); i++)
            {
                // Imprimir el nombre de la estacion
                std::cout << i << ". Estacion: " << empresaTerMax.arregloEstaciones[i].getNombreEstacion() << std::endl;

                // Obtener la region de la estacion
                short region = empresaTerMax.arregloEstaciones[i].getRegion();
                std::string regionesArreglo[3]={"Sur", "Centro","Norte"};
                std::cout << "Region: " << regionesArreglo[region] << std::endl;
            }


            //imprimir enunciado
            std::cout<<std::endl;
            std::cout<<"Islas: "<<std::endl;
            std::cout<<std::endl;

            std::cout<<std::endl;
            std::cout<<"Sutidores Activos: "<<std::endl;

            //estos espacios


            //opcion volver al menu
            int opcionvolver;
            std::cout<<std::endl;
            std::cout<<"Seleccione una opcion: "<<std::endl;
            std::cout<<"1. Volver al menu gestion de estaciones. "<<std::endl;
            std::cout<<"2. Volver al menu principal. "<<std::endl;
            std::cout<<"Ingrese la opcion: ";
            std::cin>>opcionvolver;
            verificarOpcion(opcionvolver, 1, 2);
            switch (opcionvolver)
            {
            case 1:
            {
                menuEstaciones(empresaTerMax);
            }
            default:
            {
                menuPrincipal(empresaTerMax);
            }
            }
            break;
        }
        case 2:
        {
            // Logica para eliminar surtidor
            break;
        }
        case 7:
        {
            std::cout << "Volviendo al menu principal." << std::endl;
            break;
        }
        default:
            std::cout << std::endl;
        }
    }
    while (opcion != 7);
}

void menuSurtidorVenta()
{
    int opcion = 0;

    do
    {
        std::cout << "\nMenu Realizar Venta" << std::endl;
        std::cout<<std::endl;
        std::cout << "1. Ver surtidores activos." << std::endl;
        std::cout << "2. Volver al menu principal." << std::endl;
        std::cout << "Seleccione la opcion que desee consultar: ";
        std::cin >> opcion;

        verificarOpcion(opcion, 1, 2);

        switch (opcion)
        {
        case 1:
        {
            // Logica para ver surtidores activos
            break;
        }
        case 2:
        {
            std::cout << "Volviendo al menu principal." << std::endl;
            break;
        }
        default:
            std::cout << std::endl;
        }
    }
    while (opcion != 2);
}

