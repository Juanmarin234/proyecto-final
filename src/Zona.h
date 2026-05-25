#ifndef ZONA_H
#define ZONA_H

#include <string>
#include <vector>

// ElementoInteractivo: lo guardamos como puntero en el vector.
// Explorador: lo recibimos como puntero en interactuar().
class ElementoInteractivo;
class Explorador;

class Zona {
private:
    std::string nombre;
    std::vector<ElementoInteractivo*> elementos;

public:
    // Constructor
    Zona(const std::string& nombre);

    // Destructor
    ~Zona();

    // Getters
    std::string getNombre() const;
    int cantidadElementos() const;

    void agregarElemento(ElementoInteractivo* elemento);

    void mostrarElementos() const;

    void interactuar(int indice, Explorador* explorador);
    void interactuar(const std::string& nombreElemento, Explorador* explorador);
};

#endif // ZONA_H