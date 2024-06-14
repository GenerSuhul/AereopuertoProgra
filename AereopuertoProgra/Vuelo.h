#pragma once

using namespace System;
using namespace System::Data;

// Definición de la clase Vuelo
ref class Vuelo {
public:
    // Constructor que inicializa los atributos de la clase Vuelo
    Vuelo(String^ numeroVuelo, String^ codigoAerolinea, String^ rutaOrigen, String^ rutaDestino) {
        this->NumeroVuelo = numeroVuelo;
        this->CodigoAerolinea = codigoAerolinea;
        this->RutaOrigen = rutaOrigen;
        this->RutaDestino = rutaDestino;
    }

    // Propiedad para el número de vuelo
    property String^ NumeroVuelo {
        String^ get() {
            return numeroVuelo; // Retorna el número de vuelo
        }
        void set(String^ valor) {
            numeroVuelo = valor; // Establece el número de vuelo
        }
    }

    // Propiedad para el código de la aerolínea
    property String^ CodigoAerolinea {
        String^ get() {
            return codigoAerolinea; // Retorna el código de la aerolínea
        }
        void set(String^ valor) {
            codigoAerolinea = valor; // Establece el código de la aerolínea
        }
    }

    // Propiedad para la ruta de origen
    property String^ RutaOrigen {
        String^ get() {
            return rutaOrigen; // Retorna la ruta de origen
        }
        void set(String^ valor) {
            rutaOrigen = valor; // Establece la ruta de origen
        }
    }

    // Propiedad para la ruta de destino
    property String^ RutaDestino {
        String^ get() {
            return rutaDestino; // Retorna la ruta de destino
        }
        void set(String^ valor) {
            rutaDestino = valor; // Establece la ruta de destino
        }
    }

    // Propiedad para almacenar los datos en un DataTable
    property DataTable^ Data;

private:
    String^ numeroVuelo; // Variable para el número de vuelo
    String^ codigoAerolinea; // Variable para el código de la aerolínea
    String^ rutaOrigen; // Variable para la ruta de origen
    String^ rutaDestino; // Variable para la ruta de destino
};
