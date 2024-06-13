#include "pch.h"
#include "MainFormReserva.h"
#include "Reserva.h"
#include "ReservaCRUD.h"

using namespace AereopuertoProgra;

// Definición del método InitializePlaceholderText
void MainFormReserva::InitializePlaceholderText() {
    SetPlaceholder(textBoxNumeroReserva, "Número Reserva");
    SetPlaceholder(textBoxRuta, "Ruta");
    SetPlaceholder(textBoxFecha, "Fecha");
    SetPlaceholder(textBoxHoraAbordaje, "Hora Abordaje");
    SetPlaceholder(textBoxHoraSalida, "Hora Salida");
    SetPlaceholder(textBoxHoraLlegada, "Hora Llegada");
    SetPlaceholder(textBoxNumeroVuelo, "Número Vuelo");
    SetPlaceholder(textBoxAsiento, "Asiento");
}

// Definición del método SetPlaceholder
void MainFormReserva::SetPlaceholder(System::Windows::Forms::TextBox^ textBox, System::String^ placeholderText) {
    textBox->Text = placeholderText;
    textBox->ForeColor = System::Drawing::Color::Gray;

    textBox->Enter += gcnew System::EventHandler(this, &MainFormReserva::textBox_Enter);
    textBox->Leave += gcnew System::EventHandler(this, &MainFormReserva::textBox_Leave);
}

void MainFormReserva::textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender;
    if (textBox->ForeColor == System::Drawing::Color::Gray) {
        textBox->Text = "";
        textBox->ForeColor = System::Drawing::Color::Black;
    }
}

void MainFormReserva::textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender;
    if (String::IsNullOrWhiteSpace(textBox->Text)) {
        if (textBox == textBoxNumeroReserva) {
            textBox->Text = "Número Reserva";
        }
        else if (textBox == textBoxRuta) {
            textBox->Text = "Ruta";
        }
        else if (textBox == textBoxFecha) {
            textBox->Text = "Fecha";
        }
        else if (textBox == textBoxHoraAbordaje) {
            textBox->Text = "Hora Abordaje";
        }
        else if (textBox == textBoxHoraSalida) {
            textBox->Text = "Hora Salida";
        }
        else if (textBox == textBoxHoraLlegada) {
            textBox->Text = "Hora Llegada";
        }
        else if (textBox == textBoxNumeroVuelo) {
            textBox->Text = "Número Vuelo";
        }
        else if (textBox == textBoxAsiento) {
            textBox->Text = "Asiento";
        }
        textBox->ForeColor = System::Drawing::Color::Gray;
    }
}

void MainFormReserva::buttonCreate_Click(System::Object^ sender, System::EventArgs^ e) {
    Reserva^ reserva = gcnew Reserva(
        textBoxNumeroReserva->Text,
        textBoxRuta->Text,
        DateTime::Parse(textBoxFecha->Text),
        TimeSpan::Parse(textBoxHoraAbordaje->Text),
        TimeSpan::Parse(textBoxHoraSalida->Text),
        TimeSpan::Parse(textBoxHoraLlegada->Text),
        textBoxNumeroVuelo->Text,
        textBoxAsiento->Text
    );

    ReservaCRUD::insertarReserva(reserva, connectionString);
}

void MainFormReserva::buttonRead_Click(System::Object^ sender, System::EventArgs^ e) {
    DataTable^ dt = gcnew DataTable();
    ReservaCRUD::leerReservas(dt, connectionString);
    dataGridView1->DataSource = dt;
}

void MainFormReserva::buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
    Reserva^ reserva = gcnew Reserva(
        textBoxNumeroReserva->Text,
        textBoxRuta->Text,
        DateTime::Parse(textBoxFecha->Text),
        TimeSpan::Parse(textBoxHoraAbordaje->Text),
        TimeSpan::Parse(textBoxHoraSalida->Text),
        TimeSpan::Parse(textBoxHoraLlegada->Text),
        textBoxNumeroVuelo->Text,
        textBoxAsiento->Text
    );
    ReservaCRUD::actualizarReserva(reserva, connectionString);
}

void MainFormReserva::buttonDeleteRow_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridView1->SelectedRows->Count > 0) {
        String^ numeroReserva = dataGridView1->SelectedRows[0]->Cells["numero_reserva"]->Value->ToString();
        ReservaCRUD::eliminarReserva(numeroReserva, connectionString);
        buttonRead_Click(sender, e); // Refresca los datos del DataGridView
    }
    else {
        MessageBox::Show("Por favor, selecciona una fila para eliminar.");
    }
}
