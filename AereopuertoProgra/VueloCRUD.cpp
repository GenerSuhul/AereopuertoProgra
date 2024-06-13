#include "pch.h"
#include "VueloCRUD.h"
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient; // Para MySQL

void VueloCRUD::insertarVuelo(Vuelo^ vuelo, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO Vuelos (numero_vuelo, codigo_aerolinea, ruta_origen, ruta_destino) VALUES (@numero, @codigo, @origen, @destino)", con);
    cmd->Parameters->AddWithValue("@numero", vuelo->NumeroVuelo);
    cmd->Parameters->AddWithValue("@codigo", vuelo->CodigoAerolinea);
    cmd->Parameters->AddWithValue("@origen", vuelo->RutaOrigen);
    cmd->Parameters->AddWithValue("@destino", vuelo->RutaDestino);

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

void VueloCRUD::eliminarVuelo(String^ numeroVuelo, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM Vuelos WHERE numero_vuelo = @numero;", con);
    cmd->Parameters->AddWithValue("@numero", numeroVuelo);
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

void VueloCRUD::actualizarVuelo(Vuelo^ vuelo, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlCommand^ cmd = gcnew MySqlCommand("UPDATE Vuelos SET codigo_aerolinea = @codigo, ruta_origen = @origen, ruta_destino = @destino WHERE numero_vuelo = @numero", con);
    cmd->Parameters->AddWithValue("@numero", vuelo->NumeroVuelo);
    cmd->Parameters->AddWithValue("@codigo", vuelo->CodigoAerolinea);
    cmd->Parameters->AddWithValue("@origen", vuelo->RutaOrigen);
    cmd->Parameters->AddWithValue("@destino", vuelo->RutaDestino);
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

void VueloCRUD::leerVuelos(DataTable^ dt, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT * FROM Vuelos", con);

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
