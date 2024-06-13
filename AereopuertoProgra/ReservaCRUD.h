#pragma once
#include "Reserva.h"

ref class ReservaCRUD {
public:
    static void insertarReserva(Reserva^ reserva, String^ connectionString);
    static void eliminarReserva(String^ numeroReserva, String^ connectionString);
    static void actualizarReserva(Reserva^ reserva, String^ connectionString);
    static void leerReservas(DataTable^ dt, String^ connectionString);
};
