#pragma once
#include "Vuelo.h"

// Definición de la clase VueloCRUD para manejar las operaciones CRUD en la base de datos
ref class VueloCRUD {
public:
    // Método estático para insertar un vuelo en la base de datos
    static void insertarVuelo(Vuelo^ vuelo, String^ connectionString);

    // Método estático para eliminar un vuelo de la base de datos usando el número de vuelo
    static void eliminarVuelo(String^ numeroVuelo, String^ connectionString);

    // Método estático para actualizar un vuelo en la base de datos
    static void actualizarVuelo(Vuelo^ vuelo, String^ connectionString);

    // Método estático para leer los datos de los vuelos de la base de datos
    static void leerVuelos(DataTable^ dt, String^ connectionString);
};
