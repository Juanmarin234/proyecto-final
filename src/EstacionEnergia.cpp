#include "EstacionEnergia.h"
#include "Explorador.h"
#include <iostream>

EstacionEnergia::EstacionEnergia(const std::string& nombre, int energiaQueOtorga)
    : ElementoInteractivo(nombre),       // Llama al constructor de la base.
      energiaQueOtorga(energiaQueOtorga) {
    
}

EstacionEnergia::~EstacionEnergia() {

}

void EstacionEnergia::interactuar(Explorador* explorador) {
    if (explorador == nullptr) return;  

    std::cout << "  La estacion de energia '" << nombre
              << "' libera " << energiaQueOtorga << " unidades de energia.\n";

    explorador->recuperarEnergia(energiaQueOtorga);

    desactivar();
    std::cout << "  La estacion ahora esta agotada.\n";
}

void EstacionEnergia::describir() const {
    std::cout << "Estacion de energia '" << nombre
              << "' (otorga " << energiaQueOtorga << " de energia, "
              << (activo ? "disponible" : "agotada") << ")\n";
}