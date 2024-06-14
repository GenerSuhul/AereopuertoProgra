#pragma once
#include "Aerolinea.h"

// Definición de la clase AerolineaCRUD
ref class AerolineaCRUD
{
public:
    // Método estático para insertar una aerolínea en la base de datos
    static void insertarAerolinea(Aerolinea^ aerolinea, String^ connectionString);

    // Método estático para eliminar una aerolínea de la base de datos usando su código
    static void eliminarAerolinea(String^ codigo, String^ connectionString);

    // Método estático para actualizar una aerolínea en la base de datos
    static void actualizarAerolinea(Aerolinea^ aerolinea, String^ connectionString);

    // Método estático para leer los datos de una aerolínea de la base de datos
    static void leerAerolinea(Aerolinea^ aerolinea, String^ connectionString);
};
