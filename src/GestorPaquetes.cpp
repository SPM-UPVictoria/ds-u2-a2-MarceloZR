#include "GestorPaquetes.h"
#include <iostream>

GestorPaquetes::GestorPaquetes() {
    frenteCola = nullptr;
    finalCola = nullptr;
    topePila = nullptr;
}

GestorPaquetes::~GestorPaquetes() {
    while (frenteCola != nullptr) procesarPendiente();
    while (topePila != nullptr) procesarUrgente();
}

void GestorPaquetes::agregarPendiente(std::string id, std::string destino) {
    Paquete* nuevo = new Paquete(id, destino, false);
    if (finalCola == nullptr) {
        frenteCola = finalCola = nuevo;
    } else {
        finalCola->siguiente = nuevo;
        finalCola = nuevo;
    }
    std::cout << "Paquete pendiente agregado: " << id << std::endl;
}

void GestorPaquetes::procesarPendiente() {
    if (frenteCola == nullptr) {
        std::cout << "No hay paquetes pendientes en la cola." << std::endl;
        return;
    }
    Paquete* temp = frenteCola;
    frenteCola = frenteCola->siguiente;
    if (frenteCola == nullptr) finalCola = nullptr;
    std::cout << "Procesando pendiente de la cola: " << temp->id << " a " << temp->destino << std::endl;
    delete temp;
}

void GestorPaquetes::agregarUrgente(std::string id, std::string destino) {
    Paquete* nuevo = new Paquete(id, destino, true);
    nuevo->siguiente = topePila;
    topePila = nuevo;
    std::cout << "Paquete urgente apilado: " << id << std::endl;
}

void GestorPaquetes::procesarUrgente() {
    if (topePila == nullptr) {
        std::cout << "No hay paquetes urgentes en la pila." << std::endl;
        return;
    }
    Paquete* temp = topePila;
    topePila = topePila->siguiente;
    std::cout << "Procesando URGENTE de la pila: " << temp->id << " a " << temp->destino << std::endl;
    delete temp;
}

void GestorPaquetes::mostrarEstado() {
    std::cout << std::endl << "--- ESTADO DE PAQUETES ---" << std::endl;
    std::cout << "[PILA URGENTES]: TOPE -> ";
    Paquete* temp = topePila;
    while(temp != nullptr) {
        std::cout << temp->id << " -> ";
        temp = temp->siguiente;
    }
    std::cout << "BASE" << std::endl;

    std::cout << "[COLA PENDIENTES]: FRENTE -> ";
    temp = frenteCola;
    while(temp != nullptr) {
        std::cout << temp->id << " -> ";
        temp = temp->siguiente;
    }
    std::cout << "FINAL" << std::endl;
}
