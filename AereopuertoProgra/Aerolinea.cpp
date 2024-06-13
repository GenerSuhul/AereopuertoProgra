#include "pch.h"
#include "Aerolinea.h"

Aerolinea::Aerolinea(String^ codigoAerolinea, String^ nombreAerolinea, String^ ubicacion) {
	this->CodigoAerolinea = codigoAerolinea;
	this->NombreAerolinea = nombreAerolinea;
	this->Ubicacion = ubicacion;
}