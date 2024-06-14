#pragma once
#include "Reserva.h"

// Definición de la clase ReservaCRUD
ref class ReservaCRUD {
public:
    // Método estático para insertar una reserva en la base de datos
    static void insertarReserva(Reserva^ reserva, String^ connectionString);

    // Método estático para eliminar una reserva de la base de datos usando el número de reserva
    static void eliminarReserva(String^ numeroReserva, String^ connectionString);

    // Método estático para actualizar una reserva en la base de datos
    static void actualizarReserva(Reserva^ reserva, String^ connectionString);

    // Método estático para leer los datos de las reservas de la base de datos
    static void leerReservas(DataTable^ dt, String^ connectionString);
};
