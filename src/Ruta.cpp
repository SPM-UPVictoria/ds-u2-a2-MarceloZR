#include "Ruta.h"
#include <iostream>

Ruta::Ruta() { cabeza = nullptr; }

Ruta::~Ruta() {
    Ciudad* actual = cabeza;
    while (actual != nullptr) {
        Ciudad* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}

void Ruta::agregarCiudad(std::string nombre) {
    Ciudad* nueva = new Ciudad(nombre);
    if (cabeza == nullptr) {
        cabeza = nueva;
    } else {
        Ciudad* temp = cabeza;
        while (temp->siguiente != nullptr) temp = temp->siguiente;
        temp->siguiente = nueva;
    }
}

void Ruta::eliminarCiudad(std::string nombre) {
    if (cabeza == nullptr) return;
    if (cabeza->nombre == nombre) {
        Ciudad* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        return;
    }
    Ciudad* actual = cabeza;
    while (actual->siguiente != nullptr && actual->siguiente->nombre != nombre) {
        actual = actual->siguiente;
    }
    if (actual->siguiente != nullptr) {
        Ciudad* temp = actual->siguiente;
        actual->siguiente = temp->siguiente;
        delete temp;
    }
}

void Ruta::mostrarRuta() {
    Ciudad* temp = cabeza;
    while (temp != nullptr) {
        std::cout << temp->nombre << " -> ";
        temp = temp->siguiente;
    }
    std::cout << "FIN" << std::endl;
}
