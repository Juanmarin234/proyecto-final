#ifndef RESERVA_H
#define RESERVA_H

#include <string>
#include <unordered_map>

class Zona;

class Reserva {
private:

    std::unordered_map<std::string, Zona*> zonas;

public:
    Reserva();

    ~Reserva();

    // Agrega una zona con un codigo unico.
    bool agregarZona(const std::string& codigo, Zona* zona);

    // Busca una zona por codigo
    Zona* buscarZona(const std::string& codigo) const;

    bool existeZona(const std::string& codigo) const;

    void mostrarZonas() const;

    int cantidadZonas() const;
};

#endif // RESERVA_H