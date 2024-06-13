#pragma once

using namespace System;
using namespace System::Data;

ref class Boleto {
public:
    Boleto(String^ numeroBoleto, String^ nombrePasajero, String^ numeroReserva) {
        this->NumeroBoleto = numeroBoleto;
        this->NombrePasajero = nombrePasajero;
        this->NumeroReserva = numeroReserva;
    }

    // GETTERS Y SETTERS
    property String^ NumeroBoleto {
        String^ get() {
            return numeroBoleto;
        }
        void set(String^ valor) {
            numeroBoleto = valor;
        }
    }

    property String^ NombrePasajero {
        String^ get() {
            return nombrePasajero;
        }
        void set(String^ valor) {
            nombrePasajero = valor;
        }
    }

    property String^ NumeroReserva {
        String^ get() {
            return numeroReserva;
        }
        void set(String^ valor) {
            numeroReserva = valor;
        }
    }
    property DataTable^ Data;

private:
    String^ numeroBoleto;
    String^ nombrePasajero;
    String^ numeroReserva;
};
