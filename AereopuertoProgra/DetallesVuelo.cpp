#include "pch.h"
#include "DetallesVuelo.h"

using namespace AereopuertoProgra;

void DetallesVuelo::LoadData() {
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT * FROM Vuelos", con);
    DataTable^ dt = gcnew DataTable();

    try {
        con->Open();
        da->Fill(dt);
        dataGridViewVuelos->DataSource = dt;
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message, "Error de Conexión", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally {
        con->Close();
    }
}

void DetallesVuelo::buttonVerDetalles_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridViewVuelos->SelectedRows->Count > 0) {
        String^ numeroVuelo = dataGridViewVuelos->SelectedRows[0]->Cells["numero_vuelo"]->Value->ToString();
        MySqlConnection^ con = gcnew MySqlConnection(connectionString);
        MySqlCommand^ cmd = gcnew MySqlCommand(
            "SELECT v.numero_vuelo, v.codigo_aerolinea, v.ruta_origen, v.ruta_destino, " +
            "r.fecha, r.hora_abordaje, r.hora_salida, r.hora_llegada, r.asiento, " +
            "p.nombre, p.apellido, p.email, p.telefono, a.nombre_aerolinea " +
            "FROM Vuelos v " +
            "JOIN Reservas r ON v.numero_vuelo = r.numero_vuelo " +
            "JOIN Boletos b ON r.numero_reserva = b.numero_reserva " +
            "JOIN Pasajeros p ON b.numero_reserva = p.numero_pasajero " +
            "JOIN Aerolineas a ON v.codigo_aerolinea = a.codigo_aerolinea " +
            "WHERE v.numero_vuelo = @numero", con);
        cmd->Parameters->AddWithValue("@numero", numeroVuelo);

        try {
            con->Open();
            MySqlDataReader^ reader = cmd->ExecuteReader();
            if (reader->Read()) {
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
            reader->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message, "Error de Conexión", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            con->Close();
        }
    }
    else {
        MessageBox::Show("Por favor, selecciona una fila para ver los detalles.", "Seleccionar Fila", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
}
