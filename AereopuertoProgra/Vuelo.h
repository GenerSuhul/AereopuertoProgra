#pragma once

using namespace System;
using namespace System::Data;

ref class Vuelo {
public:
    Vuelo(String^ numeroVuelo, String^ codigoAerolinea, String^ rutaOrigen, String^ rutaDestino) {
        this->NumeroVuelo = numeroVuelo;
        this->CodigoAerolinea = codigoAerolinea;
        this->RutaOrigen = rutaOrigen;
        this->RutaDestino = rutaDestino;
    }

    // GETTERS Y SETTERS
    property String^ NumeroVuelo {
        String^ get() {
            return numeroVuelo;
        }
        void set(String^ valor) {
            numeroVuelo = valor;
        }
    }

    property String^ CodigoAerolinea {
        String^ get() {
            return codigoAerolinea;
        }
        void set(String^ valor) {
            codigoAerolinea = valor;
        }
    }

    property String^ RutaOrigen {
        String^ get() {
            return rutaOrigen;
        }
        void set(String^ valor) {
            rutaOrigen = valor;
        }
    }

    property String^ RutaDestino {
        String^ get() {
            return rutaDestino;
        }
        void set(String^ valor) {
            rutaDestino = valor;
        }
    }
    property DataTable^ Data; // Propiedad para almacenar los datos


private:
    String^ numeroVuelo;
    String^ codigoAerolinea;
    String^ rutaOrigen;
    String^ rutaDestino;
};
