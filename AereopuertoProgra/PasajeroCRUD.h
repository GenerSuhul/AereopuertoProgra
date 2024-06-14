#pragma once
#include "Pasajero.h"

// Definición de la clase PasajeroCRUD
ref class PasajeroCRUD {
public:
    // Método estático para insertar un pasajero en la base de datos
    static void insertarPasajero(Pasajero^ pasajero, String^ connectionString);

    // Método estático para eliminar un pasajero de la base de datos usando su número de pasajero
    static void eliminarPasajero(String^ numeroPasajero, String^ connectionString);

    // Método estático para actualizar un pasajero en la base de datos
    static void actualizarPasajero(Pasajero^ pasajero, String^ connectionString);

    // Método estático para leer los datos de los pasajeros de la base de datos
    static void leerPasajeros(DataTable^ dt, String^ connectionString);
};
