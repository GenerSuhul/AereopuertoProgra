#include "pch.h"
#include "BoletoCRUD.h"
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient; // Para MySQL

// Implementación del método insertarBoleto
void BoletoCRUD::insertarBoleto(Boleto^ boleto, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString); // Establece una nueva conexión a la base de datos
    MySqlCommand^ cmd = gcnew MySqlCommand("INSERT INTO Boletos (numero_boleto, nombre_pasajero, numero_reserva) VALUES (@numero, @nombre, @reserva)", con); // Comando SQL para insertar datos
    // Agrega parámetros al comando SQL
    cmd->Parameters->AddWithValue("@numero", boleto->NumeroBoleto);
    cmd->Parameters->AddWithValue("@nombre", boleto->NombrePasajero);
    cmd->Parameters->AddWithValue("@reserva", boleto->NumeroReserva);

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

// Implementación del método eliminarBoleto
void BoletoCRUD::eliminarBoleto(String^ numeroBoleto, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString); // Establece una nueva conexión a la base de datos
    MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM Boletos WHERE numero_boleto = @numero;", con); // Comando SQL para eliminar datos
    cmd->Parameters->AddWithValue("@numero", numeroBoleto); // Agrega parámetro al comando SQL
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

// Implementación del método actualizarBoleto
void BoletoCRUD::actualizarBoleto(Boleto^ boleto, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString); // Establece una nueva conexión a la base de datos
    MySqlCommand^ cmd = gcnew MySqlCommand("UPDATE Boletos SET nombre_pasajero = @nombre, numero_reserva = @reserva WHERE numero_boleto = @numero", con); // Comando SQL para actualizar datos
    // Agrega parámetros al comando SQL
    cmd->Parameters->AddWithValue("@numero", boleto->NumeroBoleto);
    cmd->Parameters->AddWithValue("@nombre", boleto->NombrePasajero);
    cmd->Parameters->AddWithValue("@reserva", boleto->NumeroReserva);
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

// Implementación del método leerBoletos
void BoletoCRUD::leerBoletos(DataTable^ dt, String^ connectionString) {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString); // Establece una nueva conexión a la base de datos
    MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT * FROM Boletos", con); // Adaptador de datos para ejecutar la consulta SQL

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
