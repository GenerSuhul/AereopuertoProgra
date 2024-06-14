#include "pch.h"
#include "AerolineaCRUD.h"
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient; // Para MySQL

// Implementación del método insertarAerolinea
void AerolineaCRUD::insertarAerolinea(Aerolinea^ aerolinea, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString); // Establece una nueva conexión a la base de datos
    MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO Aerolineas (codigo_aerolinea, nombre_aerolinea, ubicacion) VALUES (@codigo, @nombre, @ubicacion)", con); // Comando SQL para insertar datos
    // Agrega parámetros al comando SQL
    cmd->Parameters->AddWithValue("@codigo", aerolinea->CodigoAerolinea);
    cmd->Parameters->AddWithValue("@nombre", aerolinea->NombreAerolinea);
    cmd->Parameters->AddWithValue("@ubicacion", aerolinea->Ubicacion);

    try {
        con->Open(); // Abre la conexión a la base de datos
        cmd->ExecuteNonQuery(); // Ejecuta el comando SQL
        MessageBox::Show("Record inserted successfully."); // Muestra un mensaje de éxito
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message); // Muestra un mensaje de error
    }
    finally {
        con->Close(); // Cierra la conexión a la base de datos
    }
}

// Implementación del método eliminarAerolinea
void AerolineaCRUD::eliminarAerolinea(String^ codigo, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString); // Establece una nueva conexión a la base de datos
    MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM aerolineas WHERE codigo_aerolinea = @codigo;", con); // Comando SQL para eliminar datos
    cmd->Parameters->AddWithValue("@codigo", codigo); // Agrega parámetro al comando SQL
    try {
        con->Open(); // Abre la conexión a la base de datos
        cmd->ExecuteNonQuery(); // Ejecuta el comando SQL
        MessageBox::Show("Record delete successfully."); // Muestra un mensaje de éxito
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message); // Muestra un mensaje de error
    }
    finally {
        con->Close(); // Cierra la conexión a la base de datos
    }
}

// Implementación del método actualizarAerolinea
void AerolineaCRUD::actualizarAerolinea(Aerolinea^ aerolinea, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString); // Establece una nueva conexión a la base de datos
    MySqlCommand^ cmd = gcnew MySqlCommand("UPDATE Aerolineas SET nombre_aerolinea = @nombre, ubicacion = @ubicacion WHERE codigo_aerolinea = @codigo", con); // Comando SQL para actualizar datos
    // Agrega parámetros al comando SQL
    cmd->Parameters->AddWithValue("@codigo", aerolinea->CodigoAerolinea);
    cmd->Parameters->AddWithValue("@nombre", aerolinea->NombreAerolinea);
    cmd->Parameters->AddWithValue("@ubicacion", aerolinea->Ubicacion);
    try {
        con->Open(); // Abre la conexión a la base de datos
        cmd->ExecuteNonQuery(); // Ejecuta el comando SQL
        MessageBox::Show("Record updated successfully."); // Muestra un mensaje de éxito
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message); // Muestra un mensaje de error
    }
    finally {
        con->Close(); // Cierra la conexión a la base de datos
    }
}

// Implementación del método leerAerolinea
void AerolineaCRUD::leerAerolinea(Aerolinea^ aerolinea, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString); // Establece una nueva conexión a la base de datos
    MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT * FROM Aerolineas", con); // Adaptador de datos para ejecutar la consulta SQL
    DataTable^ dt = gcnew DataTable(); // Crea un DataTable para almacenar los datos

    try {
        con->Open(); // Abre la conexión a la base de datos
        da->Fill(dt); // Llena el DataTable con los datos de la consulta
        aerolinea->Data = dt; // Asigna el DataTable a la propiedad Data de la clase Aerolinea
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Error: " + ex->Message); // Lanza una excepción si ocurre un error
    }
    finally {
        con->Close(); // Cierra la conexión a la base de datos
    }
}
