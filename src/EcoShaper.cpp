#include "EcoShaper.h"
#include "Reserva.h"
#include "Zona.h"
#include "Explorador.h"
#include "EstacionEnergia.h"
#include "ResiduoContaminante.h"
#include "PortalDeRuta.h"
#include <iostream>
#include <limits>
EcoShaper::EcoShaper() : reserva(nullptr), explorador(nullptr) {

}

EcoShaper::~EcoShaper() {

    delete explorador;
    delete reserva;

}

void EcoShaper::prepararReserva() {
    std::cout << "\n========================================\n";
    std::cout << "  Preparando la reserva natural EcoShaper\n";
    std::cout << "========================================\n";

    reserva = new Reserva();

    // Creamos las SEIS zonas que menciona el enunciado.
    Zona* bosque = new Zona("Bosque humedo");
    Zona* rio = new Zona("Rio contaminado");
    Zona* sendero = new Zona("Sendero de montana");
    Zona* centro = new Zona("Centro de recuperacion animal");
    Zona* vivero = new Zona("Vivero de restauracion");
    Zona* laboratorio = new Zona("Laboratorio ambiental");

    // Las registramos en la reserva con sus codigos.
    reserva->agregarZona("bosque", bosque);
    reserva->agregarZona("rio", rio);
    reserva->agregarZona("sendero", sendero);
    reserva->agregarZona("centro", centro);
    reserva->agregarZona("vivero", vivero);
    reserva->agregarZona("laboratorio", laboratorio);

    // -----------------------------------------------------------
    // BOSQUE HUMEDO: punto de inicio, varios caminos de salida.
    // -----------------------------------------------------------
    bosque->agregarElemento(new EstacionEnergia("Panel solar", 30));
    bosque->agregarElemento(new EstacionEnergia("Fuente de agua pura", 15));
    bosque->agregarElemento(new PortalDeRuta("Sendero al rio", "rio", reserva, 5));
    bosque->agregarElemento(new PortalDeRuta("Camino a la montana", "sendero", reserva, 10));

    // -----------------------------------------------------------
    // RIO CONTAMINADO: muchos residuos para limpiar.
    // -----------------------------------------------------------
    rio->agregarElemento(new ResiduoContaminante("Botellas plasticas", 10, 25));
    rio->agregarElemento(new ResiduoContaminante("Llantas viejas", 20, 50));
    rio->agregarElemento(new ResiduoContaminante("Bolsas plasticas", 5, 15));
    rio->agregarElemento(new PortalDeRuta("Sendero al bosque", "bosque", reserva, 5));
    rio->agregarElemento(new PortalDeRuta("Ruta al vivero", "vivero", reserva, 8));

    // -----------------------------------------------------------
    // SENDERO DE MONTANA: zona de paso con poca energia y un portal.
    // -----------------------------------------------------------
    sendero->agregarElemento(new EstacionEnergia("Mirador con bateria solar", 20));
    sendero->agregarElemento(new ResiduoContaminante("Residuos de excursionistas", 8, 20));
    sendero->agregarElemento(new PortalDeRuta("Bajada al bosque", "bosque", reserva, 10));
    sendero->agregarElemento(new PortalDeRuta("Camino al centro animal", "centro", reserva, 12));

    // -----------------------------------------------------------
    // CENTRO DE RECUPERACION ANIMAL: zona de alta recompensa.
    // -----------------------------------------------------------
    centro->agregarElemento(new EstacionEnergia("Punto de descanso", 25));
    centro->agregarElemento(new ResiduoContaminante("Residuos veterinarios", 15, 60));
    centro->agregarElemento(new PortalDeRuta("Ruta al sendero", "sendero", reserva, 8));
    centro->agregarElemento(new PortalDeRuta("Atajo al laboratorio", "laboratorio", reserva, 15));

    // -----------------------------------------------------------
    // VIVERO DE RESTAURACION: zona de soporte con buena energia.
    // -----------------------------------------------------------
    vivero->agregarElemento(new EstacionEnergia("Compostera energetica", 40));
    vivero->agregarElemento(new EstacionEnergia("Invernadero solar", 35));
    vivero->agregarElemento(new PortalDeRuta("Ruta al laboratorio", "laboratorio", reserva, 8));
    vivero->agregarElemento(new PortalDeRuta("Regreso al rio", "rio", reserva, 5));

    // -----------------------------------------------------------
    // LABORATORIO AMBIENTAL: zona final, alta dificultad y recompensa.
    // -----------------------------------------------------------
    laboratorio->agregarElemento(new ResiduoContaminante("Residuos quimicos", 25, 75));
    laboratorio->agregarElemento(new ResiduoContaminante("Materiales radioactivos", 35, 100));
    laboratorio->agregarElemento(new EstacionEnergia("Generador del laboratorio", 50));
    laboratorio->agregarElemento(new PortalDeRuta("Ruta al bosque", "bosque", reserva, 10));
    laboratorio->agregarElemento(new PortalDeRuta("Regreso al vivero", "vivero", reserva, 8));

    // Mostramos las zonas registradas para confirmar el estado inicial.
    reserva->mostrarZonas();
}
void EcoShaper::crearExplorador(const std::string& nombre) {
    std::cout << "\n----------------------------------------\n";
    std::cout << "  Creando explorador: " << nombre << "\n";
    std::cout << "----------------------------------------\n";

    // Energia inicial 80:
    explorador = new Explorador(nombre, 80);
}

void EcoShaper::ubicarExploradorEn(const std::string& codigoZona) {
    if (explorador == nullptr) {
        std::cout << "  [Error] No hay explorador creado para ubicar.\n";
        return;
    }

    Zona* zonaInicial = reserva->buscarZona(codigoZona);
    if (zonaInicial == nullptr) {
        std::cout << "  [Error] La zona '" << codigoZona
                  << "' no existe en la reserva.\n";
        return;
    }

    explorador->cambiarZona(zonaInicial);
}

void EcoShaper::mostrarEstadoActual() const {
    if (explorador == nullptr) {
        std::cout << "  [Aviso] Aun no hay explorador.\n";
        return;
    }

    explorador->mostrarEstado();

    // Tambien mostramos los elementos disponibles en la zona actual.
    Zona* zonaActual = explorador->getZonaActual();
    if (zonaActual != nullptr) {
        zonaActual->mostrarElementos();
    }
}

void EcoShaper::ejecutarDemostracion() {
    std::cout << "\n========================================\n";
    std::cout << "  Iniciando demostracion de interacciones\n";
    std::cout << "========================================\n";

    mostrarEstadoActual();

    // usar el panel solar (sobrecarga por indice)
    std::cout << "\n[Demostracion 1: interactuar por indice]\n";
    explorador->getZonaActual()->interactuar(0, explorador);

    // limpiar un residuo
    std::cout << "\n[Demostracion 2: cruzar portal al rio]\n";
    // Usamos la sobrecarga por nombre esta vez.
    explorador->getZonaActual()->interactuar(std::string("Sendero al rio"), explorador);

    mostrarEstadoActual();

    std::cout << "\n[Demostracion 3: limpiar residuo por indice]\n";
    explorador->getZonaActual()->interactuar(0, explorador);

    std::cout << "\n[Demostracion 4: limpiar residuo por nombre]\n";
    explorador->getZonaActual()->interactuar(std::string("Llantas viejas"), explorador);

    std::cout << "\n[Demostracion 5: cruzar portal de regreso]\n";
    explorador->getZonaActual()->interactuar(std::string("Sendero al bosque"), explorador);

    // Estado final.
    std::cout << "\n========================================\n";
    std::cout << "  Estado final del explorador\n";
    std::cout << "========================================\n";
    mostrarEstadoActual();
}

void EcoShaper::ejecutar() {
    // 1. Preparacion y demostracion automatica (lo que ya tenias).
    prepararReserva();
    crearExplorador("Ana");
    ubicarExploradorEn("bosque");
    ejecutarDemostracion();

    std::cout << "\n========================================\n";
    std::cout << "  Demostracion automatica finalizada\n";
    std::cout << "========================================\n";

    // 2. Preguntamos si el usuario quiere usar el modo interactivo.
    std::cout << "\n¿Deseas continuar en modo interactivo? (s/n): ";
    char opcion;
    std::cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
        modoInteractivo();
    } else {
        std::cout << "\nFinalizando EcoShaper. Hasta pronto!\n";
    }
}

void EcoShaper::mostrarMenu() const {
    std::cout << "\n----------------------------------------\n";
    std::cout << "  MENU INTERACTIVO\n";
    std::cout << "----------------------------------------\n";
    std::cout << "  1. Ver mi estado actual\n";
    std::cout << "  2. Ver elementos en mi zona actual\n";
    std::cout << "  3. Interactuar con un elemento (por indice)\n";
    std::cout << "  4. Interactuar con un elemento (por nombre)\n";
    std::cout << "  5. Ver todas las zonas de la reserva\n";
    std::cout << "  0. Salir del modo interactivo\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Opcion: ";
}

void EcoShaper::modoInteractivo() {
    std::cout << "\n========================================\n";
    std::cout << "  Bienvenido al modo interactivo\n";
    std::cout << "  Explorador: " << explorador->getNombre() << "\n";
    std::cout << "========================================\n";

    int opcion = -1;

    // Bucle principal: se repite hasta que el usuario elija salir (0).
    while (opcion != 0) {
        mostrarMenu();

        // Leer opcion. Si el usuario escribe algo no numerico, cin entra
        // en estado de error y hay que limpiarlo para no entrar en bucle infinito.
        if (!(std::cin >> opcion)) {
            std::cin.clear();  // Limpiamos el estado de error de cin.
            // Descartamos lo que el usuario haya escrito hasta el siguiente Enter.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "  [Error] Entrada invalida. Intenta de nuevo.\n";
            opcion = -1;
            continue;
        }

        // Procesamos cada opcion del menu.
        switch (opcion) {
            case 1: {
                explorador->mostrarEstado();
                break;
            }

            case 2: {
                Zona* zonaActual = explorador->getZonaActual();
                if (zonaActual != nullptr) {
                    zonaActual->mostrarElementos();
                } else {
                    std::cout << "  No estas en ninguna zona.\n";
                }
                break;
            }

            case 3: {
                Zona* zonaActual = explorador->getZonaActual();
                if (zonaActual == nullptr) {
                    std::cout << "  No estas en ninguna zona.\n";
                    break;
                }
                zonaActual->mostrarElementos();
                std::cout << "Ingresa el indice del elemento: ";
                int indice;
                if (!(std::cin >> indice)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "  [Error] Indice invalido.\n";
                    break;
                }
                // SOBRECARGA: aqui se llama la version con int.
                zonaActual->interactuar(indice, explorador);
                break;
            }

            case 4: {
                Zona* zonaActual = explorador->getZonaActual();
                if (zonaActual == nullptr) {
                    std::cout << "  No estas en ninguna zona.\n";
                    break;
                }
                zonaActual->mostrarElementos();
                std::cout << "Ingresa el nombre del elemento: ";
                // Limpiamos el buffer antes de leer una linea completa.
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string nombre;
                std::getline(std::cin, nombre);
                // SOBRECARGA: aqui se llama la version con string.
                zonaActual->interactuar(nombre, explorador);
                break;
            }

            case 5: {
                reserva->mostrarZonas();
                break;
            }

            case 0: {
                std::cout << "\nSaliendo del modo interactivo...\n";
                break;
            }

            default: {
                std::cout << "  [Aviso] Opcion no reconocida. Intenta de nuevo.\n";
                break;
            }
        }
    }

    // Estado final del explorador despues del modo interactivo.
    std::cout << "\n========================================\n";
    std::cout << "  Estado final tras modo interactivo\n";
    std::cout << "========================================\n";
    explorador->mostrarEstado();
    std::cout << "\nGracias por jugar EcoShaper!\n";
}