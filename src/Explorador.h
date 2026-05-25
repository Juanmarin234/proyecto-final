#ifndef EXPLORADOR_H
#define EXPLORADOR_H

#include <string>

//el Explorador conoce su Zona actual medianteun puntero
class Zona;

class Explorador {
private:
    std::string nombre;
    int energia;
    int puntaje;
    Zona* zonaActual;  // Asociacion: el explorador conoce su zona, no la posee.

    // Constantes internas para validacion.
    static const int ENERGIA_MAXIMA = 100;
    static const int ENERGIA_MINIMA = 0;

public:
    // Constructor con energia inicial configurable (valor por defecto 100).
    Explorador(const std::string& nombre, int energiaInicial = 100);

    // Getters
    std::string getNombre() const;
    int getEnergia() const;
    int getPuntaje() const;
    Zona* getZonaActual() const;

    void perderEnergia(int cantidad);
    void recuperarEnergia(int cantidad);
    void aumentarPuntaje(int cantidad);
    void cambiarZona(Zona* nuevaZona);

    bool estaConVida() const;
    void mostrarEstado() const;
};

#endif // EXPLORADOR_H