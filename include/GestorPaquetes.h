#ifndef GESTORPAQUETES_H
#define GESTORPAQUETES_H
#include "Paquete.h"
#include <string>

class GestorPaquetes {
private:
    Paquete* frenteCola;
    Paquete* finalCola;
    Paquete* topePila;

public:
    GestorPaquetes();
    ~GestorPaquetes();

    void agregarPendiente(std::string id, std::string destino);
    void procesarPendiente();

    void agregarUrgente(std::string id, std::string destino);
    void procesarUrgente();

    void mostrarEstado();
};
#endif
