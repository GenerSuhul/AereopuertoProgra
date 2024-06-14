#pragma once

using namespace System;
using namespace System::Data;

// Definición de la clase Reserva
ref class Reserva {
public:
    // Constructor de la clase Reserva
    Reserva(String^ numeroReserva, String^ ruta, DateTime fecha, TimeSpan horaAbordaje, TimeSpan horaSalida, TimeSpan horaLlegada, String^ numeroVuelo, String^ asiento) {
        this->NumeroReserva = numeroReserva; // Inicializa la propiedad NumeroReserva
        this->Ruta = ruta; // Inicializa la propiedad Ruta
        this->Fecha = fecha; // Inicializa la propiedad Fecha
        this->HoraAbordaje = horaAbordaje; // Inicializa la propiedad HoraAbordaje
        this->HoraSalida = horaSalida; // Inicializa la propiedad HoraSalida
        this->HoraLlegada = horaLlegada; // Inicializa la propiedad HoraLlegada
        this->NumeroVuelo = numeroVuelo; // Inicializa la propiedad NumeroVuelo
        this->Asiento = asiento; // Inicializa la propiedad Asiento
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

    // Propiedad para obtener y establecer la ruta
    property String^ Ruta {
        String^ get() {
            return ruta; // Retorna la ruta
        }
        void set(String^ valor) {
            ruta = valor; // Establece la ruta
        }
    }

    // Propiedad para obtener y establecer la fecha
    property DateTime Fecha {
        DateTime get() {
            return fecha; // Retorna la fecha
        }
        void set(DateTime valor) {
            fecha = valor; // Establece la fecha
        }
    }

    // Propiedad para obtener y establecer la hora de abordaje
    property TimeSpan HoraAbordaje {
        TimeSpan get() {
            return horaAbordaje; // Retorna la hora de abordaje
        }
        void set(TimeSpan valor) {
            horaAbordaje = valor; // Establece la hora de abordaje
        }
    }

    // Propiedad para obtener y establecer la hora de salida
    property TimeSpan HoraSalida {
        TimeSpan get() {
            return horaSalida; // Retorna la hora de salida
        }
        void set(TimeSpan valor) {
            horaSalida = valor; // Establece la hora de salida
        }
    }

    // Propiedad para obtener y establecer la hora de llegada
    property TimeSpan HoraLlegada {
        TimeSpan get() {
            return horaLlegada; // Retorna la hora de llegada
        }
        void set(TimeSpan valor) {
            horaLlegada = valor; // Establece la hora de llegada
        }
    }

    // Propiedad para obtener y establecer el número de vuelo
    property String^ NumeroVuelo {
        String^ get() {
            return numeroVuelo; // Retorna el número de vuelo
        }
        void set(String^ valor) {
            numeroVuelo = valor; // Establece el número de vuelo
        }
    }

    // Propiedad para obtener y establecer el asiento
    property String^ Asiento {
        String^ get() {
            return asiento; // Retorna el asiento
        }
        void set(String^ valor) {
            asiento = valor; // Establece el asiento
        }
    }

    // Propiedad para almacenar los datos
    property DataTable^ Data;

private:
    // Campos privados para almacenar los valores de las propiedades
    String^ numeroReserva;
    String^ ruta;
    DateTime fecha;
    TimeSpan horaAbordaje;
    TimeSpan horaSalida;
    TimeSpan horaLlegada;
    String^ numeroVuelo;
    String^ asiento;
};
