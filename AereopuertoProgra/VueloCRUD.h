#pragma once
#include "Vuelo.h"

ref class VueloCRUD {
public:
    static void insertarVuelo(Vuelo^ vuelo, String^ connectionString);
    static void eliminarVuelo(String^ numeroVuelo, String^ connectionString);
    static void actualizarVuelo(Vuelo^ vuelo, String^ connectionString);
    static void leerVuelos(DataTable^ dt, String^ connectionString);
};
