#ifndef ECO_MISION_H
#define ECO_MISION_H

#include <string>

class Reserva;
class Explorador;

// EcoShaper: clase principal del sistema. Coordina toda la experiencia.
// Es dueña (composicion) de la reserva y el explorador: los crea en
// su constructor (o en metodos auxiliares) y los destruye en su destructor.

class EcoShaper {
private:
    Reserva* reserva;
    Explorador* explorador;

    void prepararReserva();
    void crearExplorador(const std::string& nombre);
    void ubicarExploradorEn(const std::string& codigoZona);
    void mostrarEstadoActual() const;
    void ejecutarDemostracion();

    void modoInteractivo();
    void mostrarMenu() const;
public:
    EcoShaper();
    ~EcoShaper();

    // Punto de entrada
    void ejecutar();
};

#endif // ECO_MISION_H