#include "Zona.h"
#include "ElementoInteractivo.h"  
#include "Explorador.h"
#include <iostream>

Zona::Zona(const std::string& nombre) : nombre(nombre) {
    
}

Zona::~Zona() {
    
    for (ElementoInteractivo* elemento : elementos) {
        delete elemento;
    }
    elementos.clear();  
}

std::string Zona::getNombre() const {
    return nombre;
}

int Zona::cantidadElementos() const {
    return static_cast<int>(elementos.size());
}

void Zona::agregarElemento(ElementoInteractivo* elemento) {
    if (elemento == nullptr) return; 
    elementos.push_back(elemento);
}

void Zona::mostrarElementos() const {
    std::cout << "\n--- Elementos en zona [" << nombre << "] ---\n";
    if (elementos.empty()) {
        std::cout << "  (sin elementos)\n";
        return;
    }
    for (size_t i = 0; i < elementos.size(); ++i) {
        std::cout << "  [" << i << "] ";
        // Polimorfismo: llama al describir() de la subclase real.
        elementos[i]->describir();
    }
    std::cout << "----------------------------------\n";
}

void Zona::interactuar(int indice, Explorador* explorador) {
    
    if (indice < 0 || indice >= static_cast<int>(elementos.size())) {
        std::cout << "  [Error] Indice " << indice
                  << " fuera de rango en zona " << nombre << "\n";
        return;
    }

    ElementoInteractivo* elemento = elementos[indice];

    if (!elemento->estaActivo()) {
        std::cout << "  El elemento '" << elemento->getNombre()
                  << "' ya fue usado y no puede interactuar de nuevo.\n";
        return;
    }

    std::cout << "\n>> " << explorador->getNombre()
              << " interactua con '" << elemento->getNombre() << "':\n";

    // POLIMORFISMO DINAMICO
    elemento->interactuar(explorador);
}

void Zona::interactuar(const std::string& nombreElemento, Explorador* explorador) {
    
    for (ElementoInteractivo* elemento : elementos) {
        if (elemento->getNombre() == nombreElemento) {

            if (!elemento->estaActivo()) {
                std::cout << "  El elemento '" << nombreElemento
                          << "' ya fue usado y no puede interactuar de nuevo.\n";
                return;
            }

            std::cout << "\n>> " << explorador->getNombre()
                      << " interactua con '" << nombreElemento << "':\n";

            elemento->interactuar(explorador);
            return; 
        }
    }

    std::cout << "  [Error] No se encontro elemento con nombre '"
              << nombreElemento << "' en zona " << nombre << "\n";
}