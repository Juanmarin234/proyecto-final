#include "ElementoInteractivo.h"
#include <iostream>

ElementoInteractivo::ElementoInteractivo(const std::string& nombre)
    : nombre(nombre), activo(true) {

}

ElementoInteractivo::~ElementoInteractivo() {
    // Destructor base: no hay recursos dinamicos que liberar aqui.
    // Pero existe como virtual para que las subclases puedan
    // liberar sus propios recursos cuando un puntero a la base se borre.
}

std::string ElementoInteractivo::getNombre() const {
    return nombre;
}

bool ElementoInteractivo::estaActivo() const {
    return activo;
}

void ElementoInteractivo::desactivar() {
    activo = false;
}

void ElementoInteractivo::describir() const {
    std::cout << "Elemento: " << nombre
              << " (estado: " << (activo ? "activo" : "agotado") << ")\n";
}