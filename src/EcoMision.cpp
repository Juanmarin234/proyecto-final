#include "EcoMision.h"
#include "Reserva.h"
#include "Zona.h"
#include "Explorador.h"
#include "EstacionEnergia.h"
#include "ResiduoContaminante.h"
#include "PortalDeRuta.h"
#include <iostream>

EcoMision::EcoMision() : reserva(nullptr), explorador(nullptr) {

}

EcoMision::~EcoMision() {

    delete explorador;
    delete reserva;

}

void EcoMision::prepararReserva() {
    std::cout << "\n========================================\n";
    std::cout << "  Preparando la reserva natural EcoMision\n";
    std::cout << "========================================\n";

    reserva = new Reserva();
    
    Zona* bosque = new Zona("Bosque humedo");
    Zona* rio = new Zona("Rio contaminado");
    Zona* vivero = new Zona("Vivero de restauracion");
    Zona* laboratorio = new Zona("Laboratorio ambiental");

    // Las registramos en la reserva con sus codigos.
    reserva->agregarZona("bosque", bosque);
    reserva->agregarZona("rio", rio);
    reserva->agregarZona("vivero", vivero);
    reserva->agregarZona("laboratorio", laboratorio);

    // Poblamos cada zona con elementos interactivos.
    // POLIMORFISMO: cada zona recibe punteros a la clase base,
    // pero los objetos reales son de las distintas subclases.

    // BOSQUE: tiene una estacion de energia y un portal hacia el rio.
    bosque->agregarElemento(new EstacionEnergia("Panel solar", 30));
    bosque->agregarElemento(new PortalDeRuta("Sendero al rio", "rio", reserva, 5));

    // RIO: tiene dos residuos contaminantes y un portal de vuelta al bosque.
    rio->agregarElemento(new ResiduoContaminante("Botellas plasticas", 10, 25));
    rio->agregarElemento(new ResiduoContaminante("Llantas viejas", 20, 50));
    rio->agregarElemento(new PortalDeRuta("Sendero al bosque", "bosque", reserva, 5));

    // VIVERO: tiene una estacion de energia (mas potente) y un portal al laboratorio.
    vivero->agregarElemento(new EstacionEnergia("Compostera energetica", 40));
    vivero->agregarElemento(new PortalDeRuta("Ruta al laboratorio", "laboratorio", reserva, 8));

    // LABORATORIO: tiene un residuo de alto valor y un portal de regreso al bosque.
    laboratorio->agregarElemento(new ResiduoContaminante("Residuos quimicos", 25, 75));
    laboratorio->agregarElemento(new PortalDeRuta("Ruta al bosque", "bosque", reserva, 10));

    // Mostramos las zonas registradas para confirmar el estado inicial.
    reserva->mostrarZonas();
}

void EcoMision::crearExplorador(const std::string& nombre) {
    std::cout << "\n----------------------------------------\n";
    std::cout << "  Creando explorador: " << nombre << "\n";
    std::cout << "----------------------------------------\n";

    // Energia inicial 80:
    explorador = new Explorador(nombre, 80);
}

void EcoMision::ubicarExploradorEn(const std::string& codigoZona) {
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

void EcoMision::mostrarEstadoActual() const {
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

void EcoMision::ejecutarDemostracion() {
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

void EcoMision::ejecutar() {
    
    prepararReserva();
    crearExplorador("Ana");
    ubicarExploradorEn("bosque");
    ejecutarDemostracion();

    std::cout << "\n========================================\n";
    std::cout << "  EcoMision finalizada\n";
    std::cout << "========================================\n";
}