#pragma once
#include "Aerolinea.h"

ref class AerolineaCRUD
{
public:
	static void insertarAerolinea(Aerolinea^ aerolinea, String^ connectionString);
	static void eliminarAerolinea(String^ codigo, String^ connectionString);
	static void actualizarAerolinea(Aerolinea^ aerolinea, String^ connetionString);
	static void leerAerolinea(Aerolinea^ aerolinea, String^ connectionString);

};

