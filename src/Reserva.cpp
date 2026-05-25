#include "Reserva.h"
#include "Zona.h"   
#include <iostream>

Reserva::Reserva() {
}

Reserva::~Reserva() {
    // COMPOSICION: la Reserva destruye las zonas que contiene.
    for (auto& par : zonas) {
        delete par.second;
    }
    zonas.clear();  
}

bool Reserva::agregarZona(const std::string& codigo, Zona* zona) {
    // Validaciones basicas.
    if (zona == nullptr) {
        std::cout << "  [Error] No se puede agregar zona nula.\n";
        return false;
    }

    if (existeZona(codigo)) {
        std::cout << "  [Error] Ya existe una zona con codigo '"
                  << codigo << "'. No se agrego.\n";
        return false;
    }

    zonas[codigo] = zona;
    return true;
}

Zona* Reserva::buscarZona(const std::string& codigo) const {
    auto it = zonas.find(codigo);
    if (it == zonas.end()) {
        return nullptr; 
    }
    return it->second;  
}

bool Reserva::existeZona(const std::string& codigo) const {
    return zonas.find(codigo) != zonas.end();
}

void Reserva::mostrarZonas() const {
    std::cout << "\n=== Zonas registradas en la reserva ===\n";
    if (zonas.empty()) {
        std::cout << "  (la reserva esta vacia)\n";
        return;
    }
    for (const auto& par : zonas) {
        std::cout << "  [" << par.first << "] -> "
                  << par.second->getNombre() << "\n";
    }
    std::cout << "========================================\n";
}

int Reserva::cantidadZonas() const {
    return static_cast<int>(zonas.size());
}