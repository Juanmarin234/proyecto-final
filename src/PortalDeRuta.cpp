#include "PortalDeRuta.h"
#include "Explorador.h"
#include "Reserva.h"
#include "Zona.h"
#include <iostream>

PortalDeRuta::PortalDeRuta(const std::string& nombre,
                           const std::string& codigoDestino,
                           Reserva* reserva,
                           int costoEnergia)
    : ElementoInteractivo(nombre),
      codigoDestino(codigoDestino),
      reserva(reserva),
      costoEnergia(costoEnergia) {

}

PortalDeRuta::~PortalDeRuta() {

}

void PortalDeRuta::interactuar(Explorador* explorador) {
    if (explorador == nullptr) return;

    
    if (reserva == nullptr) {
        std::cout << "  [Error] El portal '" << nombre
                  << "' no tiene reserva asociada. No puede activarse.\n";
        return;
    }

    std::cout << "  El portal '" << nombre << "' brilla y se activa.\n";

    if (explorador->getEnergia() < costoEnergia) {
        std::cout << "  [Atencion] " << explorador->getNombre()
                  << " no tiene suficiente energia para cruzar el portal.\n"
                  << "  Necesita " << costoEnergia
                  << " pero solo tiene " << explorador->getEnergia() << ".\n";
        return;
    }

    Zona* zonaDestino = reserva->buscarZona(codigoDestino);

    if (zonaDestino == nullptr) {
        std::cout << "  [Error] La zona destino con codigo '"
                  << codigoDestino << "' no existe en la reserva.\n";
        return;
    }

    if (explorador->getZonaActual() == zonaDestino) {
        std::cout << "  El portal lleva a la zona donde ya estas. Nada cambia.\n";
        return;
    }

    // Todo en orden: cobramos energia y movemos al explorador.
    explorador->perderEnergia(costoEnergia);
    explorador->cambiarZona(zonaDestino);

}

void PortalDeRuta::describir() const {
    std::cout << "Portal '" << nombre
              << "' (destino: zona [" << codigoDestino << "], "
              << "costo: " << costoEnergia << " energia)\n";
}