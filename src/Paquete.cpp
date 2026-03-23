#include "Paquete.h"

Paquete::Paquete(std::string id, std::string destino, bool urgente) {
    this->id = id;
    this->destino = destino;
    this->urgente = urgente;
    this->siguiente = nullptr;
}
