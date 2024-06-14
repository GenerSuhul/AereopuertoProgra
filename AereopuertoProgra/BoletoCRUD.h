#pragma once
#include "Boleto.h"

// Definición de la clase BoletoCRUD
ref class BoletoCRUD {
public:
    // Método estático para insertar un boleto en la base de datos
    static void insertarBoleto(Boleto^ boleto, String^ connectionString);

    // Método estático para eliminar un boleto de la base de datos usando su número de boleto
    static void eliminarBoleto(String^ numeroBoleto, String^ connectionString);

    // Método estático para actualizar un boleto en la base de datos
    static void actualizarBoleto(Boleto^ boleto, String^ connectionString);

    // Método estático para leer los datos de los boletos de la base de datos
    static void leerBoletos(DataTable^ dt, String^ connectionString);
};
