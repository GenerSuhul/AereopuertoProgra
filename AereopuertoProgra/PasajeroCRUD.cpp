#include "pch.h"
#include "PasajeroCRUD.h"
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient; // Para MySQL

// Implementación del método insertarPasajero
void PasajeroCRUD::insertarPasajero(Pasajero^ pasajero, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString); // Establece una nueva conexión a la base de datos
    MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO Pasajeros (numero_pasajero, nombre, apellido, email, telefono) VALUES (@numero, @nombre, @apellido, @correo, @telefono)", con); // Comando SQL para insertar datos
    // Agrega parámetros al comando SQL
    cmd->Parameters->AddWithValue("@numero", pasajero->NumeroPasajero);
    cmd->Parameters->AddWithValue("@nombre", pasajero->Nombre);
    cmd->Parameters->AddWithValue("@apellido", pasajero->Apellido);
    cmd->Parameters->AddWithValue("@correo", pasajero->Email);
    cmd->Parameters->AddWithValue("@telefono", pasajero->Telefono);

    try {
        con->Open(); // Abre la conexión a la base de datos
        cmd->ExecuteNonQuery(); // Ejecuta el comando SQL
        MessageBox::Show("Registro insertado correctamente."); // Muestra un mensaje de éxito
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message); // Muestra un mensaje de error
    }
    finally {
        con->Close(); // Cierra la conexión a la base de datos
    }
}

// Implementación del método eliminarPasajero
void PasajeroCRUD::eliminarPasajero(String^ numeroPasajero, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString); // Establece una nueva conexión a la base de datos
    MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM Pasajeros WHERE numero_pasajero = @numero;", con); // Comando SQL para eliminar datos
    cmd->Parameters->AddWithValue("@numero", numeroPasajero); // Agrega parámetro al comando SQL
    try {
        con->Open(); // Abre la conexión a la base de datos
        cmd->ExecuteNonQuery(); // Ejecuta el comando SQL
        MessageBox::Show("Registro eliminado correctamente."); // Muestra un mensaje de éxito
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message); // Muestra un mensaje de error
    }
    finally {
        con->Close(); // Cierra la conexión a la base de datos
    }
}

// Implementación del método actualizarPasajero
void PasajeroCRUD::actualizarPasajero(Pasajero^ pasajero, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString); // Establece una nueva conexión a la base de datos
    MySqlCommand^ cmd = gcnew MySqlCommand("UPDATE Pasajeros SET nombre = @nombre, apellido = @apellido, email = @correo, telefono = @telefono WHERE numero_pasajero = @numero", con); // Comando SQL para actualizar datos
    // Agrega parámetros al comando SQL
    cmd->Parameters->AddWithValue("@numero", pasajero->NumeroPasajero);
    cmd->Parameters->AddWithValue("@nombre", pasajero->Nombre);
    cmd->Parameters->AddWithValue("@apellido", pasajero->Apellido);
    cmd->Parameters->AddWithValue("@correo", pasajero->Email);
    cmd->Parameters->AddWithValue("@telefono", pasajero->Telefono);
    try {
        con->Open(); // Abre la conexión a la base de datos
        cmd->ExecuteNonQuery(); // Ejecuta el comando SQL
        MessageBox::Show("Registro actualizado correctamente."); // Muestra un mensaje de éxito
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message); // Muestra un mensaje de error
    }
    finally {
        con->Close(); // Cierra la conexión a la base de datos
    }
}

// Implementación del método leerPasajeros
void PasajeroCRUD::leerPasajeros(DataTable^ dt, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString); // Establece una nueva conexión a la base de datos
    MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT * FROM Pasajeros", con); // Adaptador de datos para ejecutar la consulta SQL

    try {
        con->Open(); // Abre la conexión a la base de datos
        da->Fill(dt); // Llena el DataTable con los datos de la consulta
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Error: " + ex->Message); // Lanza una excepción si ocurre un error
    }
    finally {
        con->Close(); // Cierra la conexión a la base de datos
    }
}
