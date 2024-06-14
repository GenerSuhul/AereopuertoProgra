#include "pch.h"
#include "ReservaCRUD.h"
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient; // Para MySQL

// Método para insertar una reserva en la base de datos
void ReservaCRUD::insertarReserva(Reserva^ reserva, String^ connectionString) {
    // Establece la conexión con la base de datos
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    // Comando SQL para insertar una reserva
    MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO Reservas (numero_reserva, ruta, fecha, hora_abordaje, hora_salida, hora_llegada, numero_vuelo, asiento) VALUES (@numero, @ruta, @fecha, @abordaje, @salida, @llegada, @vuelo, @asiento)", con);
    // Asigna los parámetros del comando SQL
    cmd->Parameters->AddWithValue("@numero", reserva->NumeroReserva);
    cmd->Parameters->AddWithValue("@ruta", reserva->Ruta);
    cmd->Parameters->AddWithValue("@fecha", reserva->Fecha);
    cmd->Parameters->AddWithValue("@abordaje", reserva->HoraAbordaje);
    cmd->Parameters->AddWithValue("@salida", reserva->HoraSalida);
    cmd->Parameters->AddWithValue("@llegada", reserva->HoraLlegada);
    cmd->Parameters->AddWithValue("@vuelo", reserva->NumeroVuelo);
    cmd->Parameters->AddWithValue("@asiento", reserva->Asiento);

    try {
        // Abre la conexión y ejecuta el comando SQL
        con->Open();
        cmd->ExecuteNonQuery();
        MessageBox::Show("Registro insertado correctamente.");
    }
    catch (Exception^ ex) {
        // Muestra un mensaje de error si ocurre una excepción
        MessageBox::Show("Error: " + ex->Message);
    }
    finally {
        // Cierra la conexión
        con->Close();
    }
}

// Método para eliminar una reserva de la base de datos
void ReservaCRUD::eliminarReserva(String^ numeroReserva, String^ connectionString) {
    // Establece la conexión con la base de datos
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    // Comando SQL para eliminar una reserva
    MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM Reservas WHERE numero_reserva = @numero;", con);
    // Asigna el parámetro del comando SQL
    cmd->Parameters->AddWithValue("@numero", numeroReserva);
    try {
        // Abre la conexión y ejecuta el comando SQL
        con->Open();
        cmd->ExecuteNonQuery();
        MessageBox::Show("Registro eliminado correctamente.");
    }
    catch (Exception^ ex) {
        // Muestra un mensaje de error si ocurre una excepción
        MessageBox::Show("Error: " + ex->Message);
    }
    finally {
        // Cierra la conexión
        con->Close();
    }
}

// Método para actualizar una reserva en la base de datos
void ReservaCRUD::actualizarReserva(Reserva^ reserva, String^ connectionString) {
    // Establece la conexión con la base de datos
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    // Comando SQL para actualizar una reserva
    MySqlCommand^ cmd = gcnew MySqlCommand("UPDATE Reservas SET ruta = @ruta, fecha = @fecha, hora_abordaje = @abordaje, hora_salida = @salida, hora_llegada = @llegada, numero_vuelo = @vuelo, asiento = @asiento WHERE numero_reserva = @numero", con);
    // Asigna los parámetros del comando SQL
    cmd->Parameters->AddWithValue("@numero", reserva->NumeroReserva);
    cmd->Parameters->AddWithValue("@ruta", reserva->Ruta);
    cmd->Parameters->AddWithValue("@fecha", reserva->Fecha);
    cmd->Parameters->AddWithValue("@abordaje", reserva->HoraAbordaje);
    cmd->Parameters->AddWithValue("@salida", reserva->HoraSalida);
    cmd->Parameters->AddWithValue("@llegada", reserva->HoraLlegada);
    cmd->Parameters->AddWithValue("@vuelo", reserva->NumeroVuelo);
    cmd->Parameters->AddWithValue("@asiento", reserva->Asiento);
    try {
        // Abre la conexión y ejecuta el comando SQL
        con->Open();
        cmd->ExecuteNonQuery();
        MessageBox::Show("Registro actualizado correctamente.");
    }
    catch (Exception^ ex) {
        // Muestra un mensaje de error si ocurre una excepción
        MessageBox::Show("Error: " + ex->Message);
    }
    finally {
        // Cierra la conexión
        con->Close();
    }
}

// Método para leer las reservas de la base de datos
void ReservaCRUD::leerReservas(DataTable^ dt, String^ connectionString) {
    // Establece la conexión con la base de datos
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    // Adaptador de datos para ejecutar el comando SQL de selección
    MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT * FROM Reservas", con);

    try {
        // Abre la conexión y llena el DataTable con los datos de las reservas
        con->Open();
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
