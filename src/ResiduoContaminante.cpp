#include "ResiduoContaminante.h"
#include "Explorador.h"
#include <iostream>

ResiduoContaminante::ResiduoContaminante(const std::string& nombre,
                                         int costoEnergia,
                                         int puntosLimpieza)
    : ElementoInteractivo(nombre),
      costoEnergia(costoEnergia),
      puntosLimpieza(puntosLimpieza) {
    
}

ResiduoContaminante::~ResiduoContaminante() {
    
}

void ResiduoContaminante::interactuar(Explorador* explorador) {
    if (explorador == nullptr) return;

    std::cout << "  El explorador comienza a limpiar el residuo '"
              << nombre << "'.\n";

    if (explorador->getEnergia() < costoEnergia) {
        std::cout << "  [Atencion] " << explorador->getNombre()
                  << " no tiene suficiente energia para limpiar este residuo.\n"
                  << "  Necesita " << costoEnergia
                  << " pero solo tiene " << explorador->getEnergia() << ".\n";
        return;
    }

    explorador->perderEnergia(costoEnergia);
    explorador->aumentarPuntaje(puntosLimpieza);

    desactivar();
    std::cout << "  El residuo '" << nombre
              << "' ha sido eliminado de la zona.\n";
}

void ResiduoContaminante::describir() const {
    std::cout << "Residuo contaminante '" << nombre
              << "' (costo: " << costoEnergia << " energia, "
              << "recompensa: " << puntosLimpieza << " puntos, "
              << (activo ? "pendiente" : "ya limpiado") << ")\n";
}