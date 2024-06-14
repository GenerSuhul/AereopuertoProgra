#pragma once

using namespace System;
using namespace System::Data;

// Definición de la clase Pasajero
ref class Pasajero {
public:
    // Constructor de la clase Pasajero
    Pasajero(String^ numeroPasajero, String^ nombre, String^ apellido, String^ email, String^ telefono) {
        this->NumeroPasajero = numeroPasajero; // Inicializa la propiedad NumeroPasajero
        this->Nombre = nombre; // Inicializa la propiedad Nombre
        this->Apellido = apellido; // Inicializa la propiedad Apellido
        this->Email = email; // Inicializa la propiedad Email
        this->Telefono = telefono; // Inicializa la propiedad Telefono
    }

    // Propiedad para obtener y establecer el número de pasajero
    property String^ NumeroPasajero {
        String^ get() {
            return numeroPasajero; // Retorna el número de pasajero
        }
        void set(String^ valor) {
            numeroPasajero = valor; // Establece el número de pasajero
        }
    }

    // Propiedad para obtener y establecer el nombre
    property String^ Nombre {
        String^ get() {
            return nombre; // Retorna el nombre
        }
        void set(String^ valor) {
            nombre = valor; // Establece el nombre
        }
    }

    // Propiedad para obtener y establecer el apellido
    property String^ Apellido {
        String^ get() {
            return apellido; // Retorna el apellido
        }
        void set(String^ valor) {
            apellido = valor; // Establece el apellido
        }
    }

    // Propiedad para obtener y establecer el email
    property String^ Email {
        String^ get() {
            return email; // Retorna el email
        }
        void set(String^ valor) {
            email = valor; // Establece el email
        }
    }

    // Propiedad para obtener y establecer el teléfono
    property String^ Telefono {
        String^ get() {
            return telefono; // Retorna el teléfono
        }
        void set(String^ valor) {
            telefono = valor; // Establece el teléfono
        }
    }

    // Propiedad para almacenar los datos
    property DataTable^ Data;

private:
    // Campos privados para almacenar los valores de las propiedades
    String^ numeroPasajero;
    String^ nombre;
    String^ apellido;
    String^ email;
    String^ telefono;
};
