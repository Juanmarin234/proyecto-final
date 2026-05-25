#ifndef ELEMENTO_INTERACTIVO_H
#define ELEMENTO_INTERACTIVO_H

#include <string>

class Explorador;

class ElementoInteractivo {
protected:
    std::string nombre;
    bool activo;

public:
    // Constructor
    ElementoInteractivo(const std::string& nombre);

    virtual ~ElementoInteractivo();

    // Getters
    std::string getNombre() const;
    bool estaActivo() const;

    // Permite desactivar el elemento despues de usarse una vez
    void desactivar();
.
    virtual void interactuar(Explorador* explorador) = 0;

    virtual void describir() const;
};

#endif // ELEMENTO_INTERACTIVO_H