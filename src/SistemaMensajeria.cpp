#include "SistemaMensajeria.h"
#include <iostream>
#include <string>

void SistemaMensajeria::iniciar() {
    int opcion = 0;
    while (opcion != 5) {
        std::cout << std::endl << "=== SISTEMA DE MENSAJERIA ===" << std::endl;
        std::cout << "1. Gestionar Rutas" << std::endl;
        std::cout << "2. Gestionar Paquetes" << std::endl;
        std::cout << "3. Simular Recorrido de Camion" << std::endl;
        std::cout << "4. Ver Bases de Datos (Matrices)" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (opcion == 1) {
            std::string ciudad;
            std::cout << "Ingrese nombre de la ciudad a agregar: ";
            std::cin >> ciudad;
            gestorRutas.gestionarRutasBase(ciudad, true);
            gestorRutas.mostrarRutaPrincipal();
        } else if (opcion == 2) {
            gestorPaquetes.agregarPendiente("P-Base1", "CiudadA");
            gestorPaquetes.agregarUrgente("U-Flash1", "CiudadB");
            gestorPaquetes.mostrarEstado();
            gestorPaquetes.procesarUrgente();
            gestorPaquetes.procesarPendiente();
        } else if (opcion == 3) {
            gestorRutas.cargarPuntoControl("Control-Norte");
            gestorRutas.mostrarPosicionCamion();
            gestorRutas.avanzarCamion();
        } else if (opcion == 4) {
            gestorRutas.mostrarMatrices();
        }
    }
}
