#pragma once

using namespace System;
using namespace System::Data;

// Definición de la clase Boleto
ref class Boleto {
public:
    // Constructor de la clase Boleto
    Boleto(String^ numeroBoleto, String^ nombrePasajero, String^ numeroReserva) {
        this->NumeroBoleto = numeroBoleto; // Inicializa la propiedad NumeroBoleto
        this->NombrePasajero = nombrePasajero; // Inicializa la propiedad NombrePasajero
        this->NumeroReserva = numeroReserva; // Inicializa la propiedad NumeroReserva
    }

    // Propiedad para obtener y establecer el número de boleto
    property String^ NumeroBoleto {
        String^ get() {
            return numeroBoleto; // Retorna el número de boleto
        }
        void set(String^ valor) {
            numeroBoleto = valor; // Establece el número de boleto
        }
    }

    // Propiedad para obtener y establecer el nombre del pasajero
    property String^ NombrePasajero {
        String^ get() {
            return nombrePasajero; // Retorna el nombre del pasajero
        }
        void set(String^ valor) {
            nombrePasajero = valor; // Establece el nombre del pasajero
        }
    }

    // Propiedad para obtener y establecer el número de reserva
    property String^ NumeroReserva {
        String^ get() {
            return numeroReserva; // Retorna el número de reserva
        }
        void set(String^ valor) {
            numeroReserva = valor; // Establece el número de reserva
        }
    }

    // Propiedad para almacenar los datos
    property DataTable^ Data;

private:
    // Campos privados para almacenar los valores de las propiedades
    String^ numeroBoleto;
    String^ nombrePasajero;
    String^ numeroReserva;
};
