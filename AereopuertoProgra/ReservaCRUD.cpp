#include "pch.h"
#include "ReservaCRUD.h"
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient; // Para MySQL

void ReservaCRUD::insertarReserva(Reserva^ reserva, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO Reservas (numero_reserva, ruta, fecha, hora_abordaje, hora_salida, hora_llegada, numero_vuelo, asiento) VALUES (@numero, @ruta, @fecha, @abordaje, @salida, @llegada, @vuelo, @asiento)", con);
    cmd->Parameters->AddWithValue("@numero", reserva->NumeroReserva);
    cmd->Parameters->AddWithValue("@ruta", reserva->Ruta);
    cmd->Parameters->AddWithValue("@fecha", reserva->Fecha);
    cmd->Parameters->AddWithValue("@abordaje", reserva->HoraAbordaje);
    cmd->Parameters->AddWithValue("@salida", reserva->HoraSalida);
    cmd->Parameters->AddWithValue("@llegada", reserva->HoraLlegada);
    cmd->Parameters->AddWithValue("@vuelo", reserva->NumeroVuelo);
    cmd->Parameters->AddWithValue("@asiento", reserva->Asiento);

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

void ReservaCRUD::eliminarReserva(String^ numeroReserva, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM Reservas WHERE numero_reserva = @numero;", con);
    cmd->Parameters->AddWithValue("@numero", numeroReserva);
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

void ReservaCRUD::actualizarReserva(Reserva^ reserva, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlCommand^ cmd = gcnew MySqlCommand("UPDATE Reservas SET ruta = @ruta, fecha = @fecha, hora_abordaje = @abordaje, hora_salida = @salida, hora_llegada = @llegada, numero_vuelo = @vuelo, asiento = @asiento WHERE numero_reserva = @numero", con);
    cmd->Parameters->AddWithValue("@numero", reserva->NumeroReserva);
    cmd->Parameters->AddWithValue("@ruta", reserva->Ruta);
    cmd->Parameters->AddWithValue("@fecha", reserva->Fecha);
    cmd->Parameters->AddWithValue("@abordaje", reserva->HoraAbordaje);
    cmd->Parameters->AddWithValue("@salida", reserva->HoraSalida);
    cmd->Parameters->AddWithValue("@llegada", reserva->HoraLlegada);
    cmd->Parameters->AddWithValue("@vuelo", reserva->NumeroVuelo);
    cmd->Parameters->AddWithValue("@asiento", reserva->Asiento);
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

void ReservaCRUD::leerReservas(DataTable^ dt, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT * FROM Reservas", con);

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
