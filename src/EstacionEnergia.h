#ifndef ESTACION_ENERGIA_H
#define ESTACION_ENERGIA_H

#include "ElementoInteractivo.h"

// EstacionEnergia HEREDA publicamente de ElementoInteractivo.
class EstacionEnergia : public ElementoInteractivo {
private:
    int energiaQueOtorga;

public:
    
    EstacionEnergia(const std::string& nombre, int energiaQueOtorga);

    ~EstacionEnergia() override;

    // SOBREESCRITURA 
    void interactuar(Explorador* explorador) override;

    void describir() const override;
};

#endif // ESTACION_ENERGIA_H