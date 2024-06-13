#pragma once
#include "Boleto.h"

ref class BoletoCRUD {
public:
    static void insertarBoleto(Boleto^ boleto, String^ connectionString);
    static void eliminarBoleto(String^ numeroBoleto, String^ connectionString);
    static void actualizarBoleto(Boleto^ boleto, String^ connectionString);
    static void leerBoletos(DataTable^ dt, String^ connectionString);
};
