# EcoMisión

## Descripción

EcoMisión es un prototipo de experiencia interactiva sobre cuidado ambiental, desarrollado como proyecto final de Programación Orientada a Objetos. Una persona exploradora recorre una reserva natural compuesta por varias zonas, interactuando con elementos del entorno que afectan su energía y puntaje ambiental.

## Integrantes

- 

## Curso

Programación Orientada a Objetos 2026-1
Pontificia Universidad Javeriana Cali

## Estado del proyecto

En desarrollo.

## Cómo compilar y ejecutar


1. Abrir CLion y seleccionar **File → Open**
2. Navegar a la carpeta del proyecto y seleccionarla
3. CLion detectará el `CMakeLists.txt` automáticamente
4. Esperar a que termine la configuración de CMake
5. Click en el botón de Build para compilar
6. Click en el botón verde de Run  para ejecutar

## Uso del programa

Al ejecutar, el programa primero corre una **demostración automática** que muestra todas las funcionalidades del sistema. Luego pregunta si deseas continuar en **modo interactivo**.

### Modo interactivo

Si eliges continuar, accedes a un menú con las siguientes opciones:

1. **Ver mi estado actual**: muestra nombre, energía, puntaje y zona del explorador
2. **Ver elementos en mi zona actual**: lista los elementos disponibles para interactuar
3. **Interactuar con un elemento (por índice)**: usa la sobrecarga por número de posición
4. **Interactuar con un elemento (por nombre)**: usa la sobrecarga por nombre del elemento
5. **Ver todas las zonas de la reserva**: muestra el listado de zonas registradas
0. **Salir del modo interactivo**


## Estructura del proyecto

- `/src` — código fuente en C++
- `/docs` — documentación de diseño, decisiones y uso de IA

## Capturas del programa funcionando

### Inicio del programa y zonas registradas

![Inicio del programa](docs/imagenes/ejecucion-1-inicio.png)

### Demostración de interacción (sobrecarga por nombre)

![Interacción con elemento](docs/imagenes/ejecucion-2-interaccion.png)

### Menú interactivo

![Menú interactivo](docs/imagenes/ejecucion-3-menu.png)