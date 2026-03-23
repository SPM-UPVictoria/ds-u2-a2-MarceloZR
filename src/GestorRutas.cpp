#include "GestorRutas.h"
#include <iostream>

GestorRutas::GestorRutas() {
    frenteCamion = 0;
    finalCamion = -1;
    capacidadCamion = 5;
    cantidadActual = 0;
    configurarMatrices();
}

void GestorRutas::gestionarRutasBase(std::string nombre, bool agregar) {
    if(agregar) rutaPrincipal.agregarCiudad(nombre);
    else rutaPrincipal.eliminarCiudad(nombre);
}

void GestorRutas::mostrarRutaPrincipal() {
    std::cout << "Recorrido: ";
    rutaPrincipal.mostrarRuta();
}

void GestorRutas::cargarPuntoControl(std::string punto) {
    if (cantidadActual == capacidadCamion) {
        std::cout << "Cola circular del camion llena." << std::endl;
        return;
    }
    finalCamion = (finalCamion + 1) % capacidadCamion;
    puntosControl[finalCamion] = punto;
    cantidadActual++;
    std::cout << "Punto de control cargado: " << punto << std::endl;
}

void GestorRutas::avanzarCamion() {
    if (cantidadActual == 0) {
        std::cout << "El camion no tiene puntos de control." << std::endl;
        return;
    }
    std::string puntoActual = puntosControl[frenteCamion];
    frenteCamion = (frenteCamion + 1) % capacidadCamion;
    cantidadActual--;
    std::cout << "Camion avanza por: " << puntoActual << std::endl;
}

void GestorRutas::mostrarPosicionCamion() {
    if (cantidadActual == 0) {
        std::cout << "Camion en base (inactivo)." << std::endl;
        return;
    }
    std::cout << "Posicion actual/siguiente del camion: " << puntosControl[frenteCamion] << std::endl;
}

void GestorRutas::configurarMatrices() {
    for(int i=0; i<5; i++) distancias[i] = (i+1)*15;
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) tiempos[i][j] = (i!=j) ? (i+j)*10 : 0;
    }
    rutasPrioritarias[0][0] = 0; rutasPrioritarias[0][1] = 2; rutasPrioritarias[0][2] = 1;
    rutasPrioritarias[1][0] = 1; rutasPrioritarias[1][1] = 4; rutasPrioritarias[1][2] = 2;
    numRutasPrioritarias = 2;
}

void GestorRutas::mostrarMatrices() {
    std::cout << std::endl << "--- MATRICES ---" << std::endl;
    std::cout << "1D (Distancias): ";
    for(int i=0; i<5; i++) std::cout << distancias[i] << "km ";
    std::cout << std::endl << "Dispersa (Prioritarias [Origen, Destino, Nivel]):" << std::endl;
    for(int i=0; i<numRutasPrioritarias; i++) {
        std::cout << "Ruta de " << rutasPrioritarias[i][0] << " a " << rutasPrioritarias[i][1] << " (Nivel " << rutasPrioritarias[i][2] << ")" << std::endl;
    }
}
