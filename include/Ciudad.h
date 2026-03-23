#ifndef CIUDAD_H
#define CIUDAD_H
#include <string>

class Ciudad {
public:
    std::string nombre;
    Ciudad* siguiente;

    Ciudad(std::string nom);
};
#endif
