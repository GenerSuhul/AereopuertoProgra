#pragma once

using namespace System;
using namespace System::Data;

ref class Reserva {
public:
    Reserva(String^ numeroReserva, String^ ruta, DateTime fecha, TimeSpan horaAbordaje, TimeSpan horaSalida, TimeSpan horaLlegada, String^ numeroVuelo, String^ asiento) {
        this->NumeroReserva = numeroReserva;
        this->Ruta = ruta;
        this->Fecha = fecha;
        this->HoraAbordaje = horaAbordaje;
        this->HoraSalida = horaSalida;
        this->HoraLlegada = horaLlegada;
        this->NumeroVuelo = numeroVuelo;
        this->Asiento = asiento;
    }

    // GETTERS Y SETTERS
    property String^ NumeroReserva {
        String^ get() {
            return numeroReserva;
        }
        void set(String^ valor) {
            numeroReserva = valor;
        }
    }

    property String^ Ruta {
        String^ get() {
            return ruta;
        }
        void set(String^ valor) {
            ruta = valor;
        }
    }

    property DateTime Fecha {
        DateTime get() {
            return fecha;
        }
        void set(DateTime valor) {
            fecha = valor;
        }
    }

    property TimeSpan HoraAbordaje {
        TimeSpan get() {
            return horaAbordaje;
        }
        void set(TimeSpan valor) {
            horaAbordaje = valor;
        }
    }

    property TimeSpan HoraSalida {
        TimeSpan get() {
            return horaSalida;
        }
        void set(TimeSpan valor) {
            horaSalida = valor;
        }
    }

    property TimeSpan HoraLlegada {
        TimeSpan get() {
            return horaLlegada;
        }
        void set(TimeSpan valor) {
            horaLlegada = valor;
        }
    }

    property String^ NumeroVuelo {
        String^ get() {
            return numeroVuelo;
        }
        void set(String^ valor) {
            numeroVuelo = valor;
        }
    }

    property String^ Asiento {
        String^ get() {
            return asiento;
        }
        void set(String^ valor) {
            asiento = valor;
        }
    }
    property DataTable^ Data; // Propiedad para almacenar los datos

private:
    String^ numeroReserva;
    String^ ruta;
    DateTime fecha;
    TimeSpan horaAbordaje;
    TimeSpan horaSalida;
    TimeSpan horaLlegada;
    String^ numeroVuelo;
    String^ asiento;
};
