#include "pch.h"
#include "DetallesVuelo.h"

using namespace AereopuertoProgra;

// Método para cargar datos en el DataGridView
void DetallesVuelo::LoadData() {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString); // Crear una nueva conexión MySQL
    MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT * FROM Vuelos", con); // Crear un adaptador de datos para la consulta SQL
    DataTable^ dt = gcnew DataTable(); // Crear una nueva tabla de datos

    try {
        con->Open(); // Abrir la conexión
        da->Fill(dt); // Llenar la tabla de datos con el resultado de la consulta
        dataGridViewVuelos->DataSource = dt; // Asignar la tabla de datos como fuente de datos del DataGridView
    }
    catch (Exception^ ex) {
        // Mostrar un mensaje de error si ocurre una excepción
        MessageBox::Show("Error: " + ex->Message, "Error de Conexión", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally {
        con->Close(); // Cerrar la conexión
    }
}

// Método para manejar el evento Click del botón Ver Detalles
void DetallesVuelo::buttonVerDetalles_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridViewVuelos->SelectedRows->Count > 0) { // Verificar si hay filas seleccionadas
        String^ numeroVuelo = dataGridViewVuelos->SelectedRows[0]->Cells["numero_vuelo"]->Value->ToString(); // Obtener el número de vuelo de la fila seleccionada
        MySqlConnection^ con = gcnew MySqlConnection(connectionString); // Crear una nueva conexión MySQL
        MySqlCommand^ cmd = gcnew MySqlCommand(
            "SELECT v.numero_vuelo, v.codigo_aerolinea, v.ruta_origen, v.ruta_destino, " +
            "r.fecha, r.hora_abordaje, r.hora_salida, r.hora_llegada, r.asiento, " +
            "p.nombre, p.apellido, p.email, p.telefono, a.nombre_aerolinea " +
            "FROM Vuelos v " +
            "JOIN Reservas r ON v.numero_vuelo = r.numero_vuelo " +
            "JOIN Boletos b ON r.numero_reserva = b.numero_reserva " +
            "JOIN Pasajeros p ON b.numero_reserva = p.numero_pasajero " +
            "JOIN Aerolineas a ON v.codigo_aerolinea = a.codigo_aerolinea " +
            "WHERE v.numero_vuelo = @numero", con); // Crear una consulta SQL para obtener detalles del vuelo
        cmd->Parameters->AddWithValue("@numero", numeroVuelo); // Agregar el parámetro del número de vuelo

        try {
            con->Open(); // Abrir la conexión
            MySqlDataReader^ reader = cmd->ExecuteReader(); // Ejecutar la consulta y obtener un lector de datos
            if (reader->Read()) {
                // Mostrar los detalles del vuelo en el TextBox
                textBoxDetalles->Text = "Número de Vuelo: " + reader["numero_vuelo"]->ToString() + "\r\n" +
                    "Código Aerolínea: " + reader["codigo_aerolinea"]->ToString() + "\r\n" +
                    "Aerolinea: " + reader["nombre_aerolinea"]->ToString() + "\r\n" +
                    "Ruta Origen: " + reader["ruta_origen"]->ToString() + "\r\n" +
                    "Ruta Destino: " + reader["ruta_destino"]->ToString() + "\r\n" +
                    "Fecha: " + reader["fecha"]->ToString() + "\r\n" +
                    "Hora Abordaje: " + reader["hora_abordaje"]->ToString() + "\r\n" +
                    "Hora Salida: " + reader["hora_salida"]->ToString() + "\r\n" +
                    "Hora Llegada: " + reader["hora_llegada"]->ToString() + "\r\n" +
                    "Asiento: " + reader["asiento"]->ToString() + "\r\n" +
                    "Nombre Pasajero: " + reader["nombre"]->ToString() + "\r\n" +
                    "Apellido Pasajero: " + reader["apellido"]->ToString() + "\r\n" +
                    "Email: " + reader["email"]->ToString() + "\r\n" +
                    "Teléfono: " + reader["telefono"]->ToString();
            }
            reader->Close(); // Cerrar el lector de datos
        }
        catch (Exception^ ex) {
            // Mostrar un mensaje de error si ocurre una excepción
            MessageBox::Show("Error: " + ex->Message, "Error de Conexión", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            con->Close(); // Cerrar la conexión
        }
    }
    else {
        // Mostrar un mensaje si no hay filas seleccionadas
        MessageBox::Show("Por favor, selecciona una fila para ver los detalles.", "Seleccionar Fila", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
}
