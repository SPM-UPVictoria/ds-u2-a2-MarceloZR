#ifndef SISTEMAMENSAJERIA_H
#define SISTEMAMENSAJERIA_H
#include "GestorRutas.h"
#include "GestorPaquetes.h"

class SistemaMensajeria {
private:
    GestorRutas gestorRutas;
    GestorPaquetes gestorPaquetes;
public:
    void iniciar();
};
#endif
