#ifndef RESIDUO_CONTAMINANTE_H
#define RESIDUO_CONTAMINANTE_H

#include "ElementoInteractivo.h"

// ResiduoContaminante: representa un problema ambiental que el
// explorador puede limpiar
class ResiduoContaminante : public ElementoInteractivo {
private:
    int costoEnergia;     
    int puntosLimpieza;

public:
    ResiduoContaminante(const std::string& nombre,
                        int costoEnergia,
                        int puntosLimpieza);

    ~ResiduoContaminante() override;

    // Sobreescritura
    void interactuar(Explorador* explorador) override;

    // Sobreescritura
    void describir() const override;
};

#endif // RESIDUO_CONTAMINANTE_H