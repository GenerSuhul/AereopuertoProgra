#pragma once

using namespace System;
using namespace System::Data;

ref class Aerolinea
{
public:
    // Constructor de la clase Aerolinea
    Aerolinea(String^ codigoAerolinea, String^ nombreAerolinea, String^ ubicacion);

    // Propiedad para obtener y establecer el código de la aerolínea
    property String^ CodigoAerolinea {
        String^ get() {
            return codigoAerolinea; // Retorna el código de la aerolínea
        }
        void set(String^ valor) {
            codigoAerolinea = valor; // Establece el código de la aerolínea
        }
    }

    // Propiedad para obtener y establecer el nombre de la aerolínea
    property String^ NombreAerolinea {
        String^ get() {
            return nombreAerolinea; // Retorna el nombre de la aerolínea
        }
        void set(String^ valor) {
            nombreAerolinea = valor; // Establece el nombre de la aerolínea
        }
    }

    // Propiedad para obtener y establecer la ubicación de la aerolínea
    property String^ Ubicacion {
        String^ get() {
            return ubicacion; // Retorna la ubicación de la aerolínea
        }
        void set(String^ valor) {
            ubicacion = valor; // Establece la ubicación de la aerolínea
        }
    }

    property DataTable^ Data; // Propiedad para almacenar los datos de la aerolínea

private:
    // Campos privados para almacenar los valores de las propiedades
    property String^ codigoAerolinea;
    property String^ nombreAerolinea;
    property String^ ubicacion;
};
