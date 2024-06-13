#pragma once

using namespace System;
using namespace System::Data;

ref class Aerolinea
{
public:

	Aerolinea(String^ codigoAerolinea, String^ nombreAerolinea, String^ ubicacion);

	// GETTERS Y SETTERS
	property String^ CodigoAerolinea {
		String^ get() {
			return codigoAerolinea;
		}
		void set(String^ valor) {
			codigoAerolinea = valor;
		}
	}

	property String^ NombreAerolinea {
		String^ get() {
			return nombreAerolinea;
		}
		void set(String^ valor) {
			nombreAerolinea = valor;
		}
	}

	property String^ Ubicacion {
		String^ get() {
			return ubicacion;
		}
		void set(String^ valor) {
			ubicacion = valor;
		}
	}
	property DataTable^ Data; // Propiedad para almacenar los datos

private:
	property String^ codigoAerolinea;
	property String^ nombreAerolinea;
	property String^ ubicacion;

};

