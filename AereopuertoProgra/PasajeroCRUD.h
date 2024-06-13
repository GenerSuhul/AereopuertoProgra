#pragma once
#include "Pasajero.h"

ref class PasajeroCRUD {
public:
    static void insertarPasajero(Pasajero^ pasajero, String^ connectionString);
    static void eliminarPasajero(String^ numeroPasajero, String^ connectionString);
    static void actualizarPasajero(Pasajero^ pasajero, String^ connectionString);
    static void leerPasajeros(DataTable^ dt, String^ connectionString);
};
