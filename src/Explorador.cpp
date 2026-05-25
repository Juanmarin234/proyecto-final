#include "Explorador.h"
#include "Zona.h"  
#include <iostream>

Explorador::Explorador(const std::string& nombre, int energiaInicial)
    : nombre(nombre), energia(energiaInicial), puntaje(0), zonaActual(nullptr) {

    if (energia < ENERGIA_MINIMA) energia = ENERGIA_MINIMA;
    if (energia > ENERGIA_MAXIMA) energia = ENERGIA_MAXIMA;
}

std::string Explorador::getNombre() const {
    return nombre;
}

int Explorador::getEnergia() const {
    return energia;
}

int Explorador::getPuntaje() const {
    return puntaje;
}

Zona* Explorador::getZonaActual() const {
    return zonaActual;
}

void Explorador::perderEnergia(int cantidad) {

    if (cantidad <= 0) return;

    energia -= cantidad;
    if (energia < ENERGIA_MINIMA) energia = ENERGIA_MINIMA;

    std::cout << "  " << nombre << " perdio " << cantidad
              << " de energia. Energia actual: " << energia << "\n";
}

void Explorador::recuperarEnergia(int cantidad) {
    if (cantidad <= 0) return;

    energia += cantidad;
    if (energia > ENERGIA_MAXIMA) energia = ENERGIA_MAXIMA;

    std::cout << "  " << nombre << " recupero " << cantidad
              << " de energia. Energia actual: " << energia << "\n";
}

void Explorador::aumentarPuntaje(int cantidad) {
    if (cantidad <= 0) return;
    puntaje += cantidad;

    std::cout << "  " << nombre << " gano " << cantidad
              << " puntos ambientales. Puntaje total: " << puntaje << "\n";
}

void Explorador::cambiarZona(Zona* nuevaZona) {
   
    zonaActual = nuevaZona;

    if (nuevaZona != nullptr) {
        std::cout << "  " << nombre << " se ha movido a la zona: "
                  << nuevaZona->getNombre() << "\n";
    }
}

bool Explorador::estaConVida() const {
    return energia > ENERGIA_MINIMA;
}

void Explorador::mostrarEstado() const {
    std::cout << "\n--- Estado del explorador ---\n";
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Energia: " << energia << "/" << ENERGIA_MAXIMA << "\n";
    std::cout << "Puntaje ambiental: " << puntaje << "\n";
    std::cout << "Zona actual: ";
    if (zonaActual != nullptr) {
        std::cout << zonaActual->getNombre();
    } else {
        std::cout << "(ninguna)";
    }
    std::cout << "\n-----------------------------\n";
}