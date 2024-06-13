#pragma once

using namespace System;
using namespace System::Data;

ref class Pasajero {
public:
    Pasajero(String^ numeroPasajero, String^ nombre, String^ apellido, String^ email, String^ telefono) {
        this->NumeroPasajero = numeroPasajero;
        this->Nombre = nombre;
        this->Apellido = apellido;
        this->Email = email;
        this->Telefono = telefono;
    }

    // GETTERS Y SETTERS
    property String^ NumeroPasajero {
        String^ get() {
            return numeroPasajero;
        }
        void set(String^ valor) {
            numeroPasajero = valor;
        }
    }

    property String^ Nombre {
        String^ get() {
            return nombre;
        }
        void set(String^ valor) {
            nombre = valor;
        }
    }

    property String^ Apellido {
        String^ get() {
            return apellido;
        }
        void set(String^ valor) {
            apellido = valor;
        }
    }

    property String^ Email {
        String^ get() {
            return email;
        }
        void set(String^ valor) {
            email = valor;
        }
    }

    property String^ Telefono {
        String^ get() {
            return telefono;
        }
        void set(String^ valor) {
            telefono = valor;
        }
    }
    property DataTable^ Data; // Propiedad para almacenar los datos


private:
    String^ numeroPasajero;
    String^ nombre;
    String^ apellido;
    String^ email;
    String^ telefono;
};
