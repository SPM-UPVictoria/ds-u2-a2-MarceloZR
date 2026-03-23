cmake_minimum_required(VERSION 3.10)
project(ProyectoMensajeria)

set(CMAKE_CXX_STANDARD 17)

# Incluir la carpeta de cabeceras
include_directories(include)

# Buscar todos los archivos fuente
file(GLOB SOURCES "src/*.cpp")

# Crear el ejecutable
add_executable(ProyectoMensajeria ${SOURCES})
