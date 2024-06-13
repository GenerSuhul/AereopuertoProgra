#include "pch.h"
#include "BoletoCRUD.h"
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient; // Para MySQL

void BoletoCRUD::insertarBoleto(Boleto^ boleto, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO Boletos (numero_boleto, nombre_pasajero, numero_reserva) VALUES (@numero, @nombre, @reserva)", con);
    cmd->Parameters->AddWithValue("@numero", boleto->NumeroBoleto);
    cmd->Parameters->AddWithValue("@nombre", boleto->NombrePasajero);
    cmd->Parameters->AddWithValue("@reserva", boleto->NumeroReserva);

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

void BoletoCRUD::eliminarBoleto(String^ numeroBoleto, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM Boletos WHERE numero_boleto = @numero;", con);
    cmd->Parameters->AddWithValue("@numero", numeroBoleto);
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

void BoletoCRUD::actualizarBoleto(Boleto^ boleto, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlCommand^ cmd = gcnew MySqlCommand("UPDATE Boletos SET nombre_pasajero = @nombre, numero_reserva = @reserva WHERE numero_boleto = @numero", con);
    cmd->Parameters->AddWithValue("@numero", boleto->NumeroBoleto);
    cmd->Parameters->AddWithValue("@nombre", boleto->NombrePasajero);
    cmd->Parameters->AddWithValue("@reserva", boleto->NumeroReserva);
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

void BoletoCRUD::leerBoletos(DataTable^ dt, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT * FROM Boletos", con);

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
