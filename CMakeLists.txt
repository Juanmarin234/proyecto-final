cmake_minimum_required(VERSION 3.20)
project(ecoshaper)

# Usamos C++17 (moderno y estable, soporta nullptr, auto, range-based for, etc.)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Avisos del compilador activados (ayuda a detectar errores comunes).
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Lista de archivos fuente del proyecto.
# A medida que agregues nuevas clases, añade aqui sus .cpp.
set(SOURCES
        src/ElementoInteractivo.cpp
        src/Explorador.cpp
        src/Zona.cpp
        src/Reserva.cpp
        src/EstacionEnergia.cpp
        src/ResiduoContaminante.cpp
        src/PortalDeRuta.cpp
        src/EcoShaper.cpp
        src/main.cpp
)

# Genera el EJECUTABLE (no una libreria) con los archivos fuente.
add_executable(ecoshaper ${SOURCES})

# Indica donde estan los headers para que #include "X.h" funcione.
target_include_directories(ecoshaper PRIVATE src)