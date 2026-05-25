# Diseño del sistema EcoMisión

Este documento contiene la evolución del diseño del sistema, las decisiones tomadas y sus justificaciones.

## Versión inicial del diagrama de clases
Esta versión refleja el diseño tal como fue concebido antes de comenzar a programar. Identifica las clases principales, sus responsabilidades básicas y las relaciones entre ellas.


### Explicación de las relaciones

**Composición** entre EcoMision-Reserva, EcoMision-Explorador, Reserva-Zona y Zona-ElementoInteractivo. En cada caso, el objeto contenedor crea y destruye a los objetos contenidos. Si se destruye una `Reserva`, sus zonas mueren con ella; si se destruye una `Zona`, sus elementos también.

**Asociación** entre Explorador-Zona y PortalDeRuta-Reserva. El explorador *conoce* su zona actual pero no la posee, y el portal *consulta* la reserva para resolver su zona destino pero no la administra.

**Herencia** entre ElementoInteractivo y sus tres subclases. Las subclases heredan la interfaz común y deben implementar el método virtual `interactuar`.

### Aplicación de los cuatro pilares de POO

- **Abstracción**: `ElementoInteractivo` define [qué] puede hacer un elemento (interactuar con el explorador) sin especificar [como]. Cada subclase define su propia respuesta.
- **Encapsulamiento**: todos los atributos son privados o protegidos. El estado solo se modifica mediante métodos públicos validados.
- **Herencia**: las tres clases concretas heredan estructura de `ElementoInteractivo`.
- **Polimorfismo**: cuando `Zona::interactuar` invoca `elementos[i]->interactuar(exp)`, el método ejecutado se resuelve en tiempo de ejecución según el tipo real del objeto.

### Caso de sobrecarga

En la clase `Zona` se incluyen dos versiones del método `interactuar`:

- `interactuar(int indice, Explorador* exp)`: para invocar interacción por posición en el vector.
- `interactuar(string nombre, Explorador* exp)`: para invocar interacción por nombre del elemento.

Esta es **sobrecarga** (no sobreescritura): mismo nombre de método, distinta firma, resolución en tiempo de compilación.

![Diagrama de clases - versión inicial](imagenes/diagrama-inicial.png)
## Versión ajustada del diagrama de clases


## Versión final del diagrama de clases


## Matriz de decisiones de diseño
