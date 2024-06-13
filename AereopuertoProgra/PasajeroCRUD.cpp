#include "pch.h"
#include "PasajeroCRUD.h"
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient; // Para MySQL

void PasajeroCRUD::insertarPasajero(Pasajero^ pasajero, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO Pasajeros (numero_pasajero, nombre, apellido, email, telefono) VALUES (@numero, @nombre, @apellido, @correo, @telefono)", con);
    cmd->Parameters->AddWithValue("@numero", pasajero->NumeroPasajero);
    cmd->Parameters->AddWithValue("@nombre", pasajero->Nombre);
    cmd->Parameters->AddWithValue("@apellido", pasajero->Apellido);
    cmd->Parameters->AddWithValue("@correo", pasajero->Email);
    cmd->Parameters->AddWithValue("@telefono", pasajero->Telefono);

    try {
        con->Open();
        cmd->ExecuteNonQuery();
        MessageBox::Show("Registro insertado correctamente.");
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }
    finally {
        con->Close();
    }
}

void PasajeroCRUD::eliminarPasajero(String^ numeroPasajero, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM Pasajeros WHERE numero_pasajero = @numero;", con);
    cmd->Parameters->AddWithValue("@numero", numeroPasajero);
    try {
        con->Open();
        cmd->ExecuteNonQuery();
        MessageBox::Show("Registro eliminado correctamente.");
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }
    finally {
        con->Close();
    }
}

void PasajeroCRUD::actualizarPasajero(Pasajero^ pasajero, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlCommand^ cmd = gcnew MySqlCommand("UPDATE Pasajeros SET nombre = @nombre, apellido = @apellido, email = @correo, telefono = @telefono WHERE numero_pasajero = @numero", con);
    cmd->Parameters->AddWithValue("@numero", pasajero->NumeroPasajero);
    cmd->Parameters->AddWithValue("@nombre", pasajero->Nombre);
    cmd->Parameters->AddWithValue("@apellido", pasajero->Apellido);
    cmd->Parameters->AddWithValue("@correo", pasajero->Email);
    cmd->Parameters->AddWithValue("@telefono", pasajero->Telefono);
    try {
        con->Open();
        cmd->ExecuteNonQuery();
        MessageBox::Show("Registro actualizado correctamente.");
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }
    finally {
        con->Close();
    }
}

void PasajeroCRUD::leerPasajeros(DataTable^ dt, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT * FROM Pasajeros", con);

    try {
        con->Open();
        da->Fill(dt);
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Error: " + ex->Message);
    }
    finally {
        con->Close();
    }
}
