#include "pch.h"
#include "Aerolinea.h"

// Constructor de la clase Aerolinea
Aerolinea::Aerolinea(String^ codigoAerolinea, String^ nombreAerolinea, String^ ubicacion) {
    // Inicializa las propiedades con los valores proporcionados
    this->CodigoAerolinea = codigoAerolinea;
    this->NombreAerolinea = nombreAerolinea;
    this->Ubicacion = ubicacion;
}
