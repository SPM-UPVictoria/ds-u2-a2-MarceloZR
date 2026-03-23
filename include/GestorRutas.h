#ifndef GESTORRUTAS_H
#define GESTORRUTAS_H
#include "Ruta.h"
#include <string>

class GestorRutas {
private:
    Ruta rutaPrincipal;

    std::string puntosControl[5];
    int frenteCamion;
    int finalCamion;
    int capacidadCamion;
    int cantidadActual;

    int distancias[5];
    int tiempos[5][5];
    int rutasPrioritarias[10][3];
    int numRutasPrioritarias;

public:
    GestorRutas();

    void gestionarRutasBase(std::string nombre, bool agregar);
    void mostrarRutaPrincipal();

    void cargarPuntoControl(std::string punto);
    void avanzarCamion();
    void mostrarPosicionCamion();

    void configurarMatrices();
    void mostrarMatrices();
};
#endif
