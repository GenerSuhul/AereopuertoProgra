#include "pch.h"
#include "VueloCRUD.h"
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient; // Para MySQL

// Método para insertar un vuelo en la base de datos
void VueloCRUD::insertarVuelo(Vuelo^ vuelo, String^ connectionString) {
    // Crea una conexión MySQL
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    // Crea un comando MySQL con la consulta de inserción
    MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO Vuelos (numero_vuelo, codigo_aerolinea, ruta_origen, ruta_destino) VALUES (@numero, @codigo, @origen, @destino)", con);
    // Añade los parámetros al comando
    cmd->Parameters->AddWithValue("@numero", vuelo->NumeroVuelo);
    cmd->Parameters->AddWithValue("@codigo", vuelo->CodigoAerolinea);
    cmd->Parameters->AddWithValue("@origen", vuelo->RutaOrigen);
    cmd->Parameters->AddWithValue("@destino", vuelo->RutaDestino);

    try {
        // Abre la conexión
        con->Open();
        // Ejecuta el comando
        cmd->ExecuteNonQuery();
        // Muestra un mensaje de éxito
        MessageBox::Show("Registro insertado correctamente.");
    }
    catch (Exception^ ex) {
        // Muestra un mensaje de error
        MessageBox::Show("Error: " + ex->Message);
    }
    finally {
        // Cierra la conexión
        con->Close();
    }
}

// Método para eliminar un vuelo de la base de datos
void VueloCRUD::eliminarVuelo(String^ numeroVuelo, String^ connectionString) {
    // Crea una conexión MySQL
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    // Crea un comando MySQL con la consulta de eliminación
    MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM Vuelos WHERE numero_vuelo = @numero;", con);
    // Añade los parámetros al comando
    cmd->Parameters->AddWithValue("@numero", numeroVuelo);
    try {
        // Abre la conexión
        con->Open();
        // Ejecuta el comando
        cmd->ExecuteNonQuery();
        // Muestra un mensaje de éxito
        MessageBox::Show("Registro eliminado correctamente.");
    }
    catch (Exception^ ex) {
        // Muestra un mensaje de error
        MessageBox::Show("Error: " + ex->Message);
    }
    finally {
        // Cierra la conexión
        con->Close();
    }
}

// Método para actualizar un vuelo en la base de datos
void VueloCRUD::actualizarVuelo(Vuelo^ vuelo, String^ connectionString) {
    // Crea una conexión MySQL
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    // Crea un comando MySQL con la consulta de actualización
    MySqlCommand^ cmd = gcnew MySqlCommand("UPDATE Vuelos SET codigo_aerolinea = @codigo, ruta_origen = @origen, ruta_destino = @destino WHERE numero_vuelo = @numero", con);
    // Añade los parámetros al comando
    cmd->Parameters->AddWithValue("@numero", vuelo->NumeroVuelo);
    cmd->Parameters->AddWithValue("@codigo", vuelo->CodigoAerolinea);
    cmd->Parameters->AddWithValue("@origen", vuelo->RutaOrigen);
    cmd->Parameters->AddWithValue("@destino", vuelo->RutaDestino);
    try {
        // Abre la conexión
        con->Open();
        // Ejecuta el comando
        cmd->ExecuteNonQuery();
        // Muestra un mensaje de éxito
        MessageBox::Show("Registro actualizado correctamente.");
    }
    catch (Exception^ ex) {
        // Muestra un mensaje de error
        MessageBox::Show("Error: " + ex->Message);
    }
    finally {
        // Cierra la conexión
        con->Close();
    }
}

// Método para leer los vuelos de la base de datos
void VueloCRUD::leerVuelos(DataTable^ dt, String^ connectionString) {
    // Crea una conexión MySQL
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    // Crea un adaptador de datos MySQL con la consulta de selección
    MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT * FROM Vuelos", con);

    try {
        // Abre la conexión
        con->Open();
        // Llena el DataTable con los datos obtenidos
        da->Fill(dt);
    }
    catch (Exception^ ex) {
        // Lanza una excepción si ocurre un error
        throw gcnew Exception("Error: " + ex->Message);
    }
    finally {
        // Cierra la conexión
        con->Close();
    }
}
