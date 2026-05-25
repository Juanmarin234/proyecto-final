#ifndef PORTAL_DE_RUTA_H
#define PORTAL_DE_RUTA_H

#include "ElementoInteractivo.h"

class Reserva;
class Zona;

class PortalDeRuta : public ElementoInteractivo {
private:
    std::string codigoDestino;  
    Reserva* reserva;           
    int costoEnergia;

public:
    PortalDeRuta(const std::string& nombre,
                 const std::string& codigoDestino,
                 Reserva* reserva,
                 int costoEnergia);

    ~PortalDeRuta() override;

    void interactuar(Explorador* explorador) override;
    void describir() const override;
};

#endif // PORTAL_DE_RUTA_H