#include "pch.h"
#include "AerolineaCRUD.h"
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient; // Para MySQL

void AerolineaCRUD::insertarAerolinea(Aerolinea^ aerolinea, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO Aerolineas (codigo_aerolinea, nombre_aerolinea, ubicacion) VALUES (@codigo, @nombre, @ubicacion)", con);
    cmd->Parameters->AddWithValue("@codigo", aerolinea->CodigoAerolinea);
    cmd->Parameters->AddWithValue("@nombre", aerolinea->NombreAerolinea);
    cmd->Parameters->AddWithValue("@ubicacion", aerolinea->Ubicacion);

    try {
        con->Open();
        cmd->ExecuteNonQuery();
        MessageBox::Show("Record inserted successfully.");
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }
    finally {
        con->Close();
    }
}

void AerolineaCRUD::eliminarAerolinea(String^ codigo, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM aerolineas WHERE codigo_aerolinea = @codigo;", con);
    cmd->Parameters->AddWithValue("@codigo", codigo);
    try
    {
        con->Open();
        cmd->ExecuteNonQuery();
        MessageBox::Show("Record delete successfully.");
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    
    }

    finally {
        con->Close();
    }
}

void AerolineaCRUD::actualizarAerolinea(Aerolinea^ aerolinea, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlCommand^ cmd = gcnew MySqlCommand("UPDATE Aerolineas SET nombre_aerolinea = @nombre, ubicacion = @ubicacion WHERE codigo_aerolinea = @codigo", con);
    cmd->Parameters->AddWithValue("@codigo", aerolinea->CodigoAerolinea);
    cmd->Parameters->AddWithValue("@nombre", aerolinea->NombreAerolinea);
    cmd->Parameters->AddWithValue("@ubicacion", aerolinea->Ubicacion);
    try
    {
        con->Open();
        cmd->ExecuteNonQuery();
        MessageBox::Show("Record updated successfully.");
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    
    }

    finally {
        con->Close();
    }
}

void AerolineaCRUD::leerAerolinea(Aerolinea^ aerolinea, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT * FROM Aerolineas", con);
    DataTable^ dt = gcnew DataTable();

    try {
        con->Open();
        da->Fill(dt);
        aerolinea->Data = dt;
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Error: " + ex->Message);
    }
    finally {
        con->Close();
    }
}