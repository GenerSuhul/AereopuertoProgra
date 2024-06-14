#include "pch.h"
#include "MainFormReserva.h"
#include "Reserva.h"
#include "ReservaCRUD.h"

using namespace AereopuertoProgra;

// Definición del método InitializePlaceholderText
void MainFormReserva::InitializePlaceholderText() {
    // Establece los textos de marcador de posición para los TextBox
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
    // Establece el texto del marcador de posición y el color del texto
    textBox->Text = placeholderText;
    textBox->ForeColor = System::Drawing::Color::Gray;

    // Asigna los eventos Enter y Leave para manejar el foco en los TextBox
    textBox->Enter += gcnew System::EventHandler(this, &MainFormReserva::textBox_Enter);
    textBox->Leave += gcnew System::EventHandler(this, &MainFormReserva::textBox_Leave);
}

// Maneja el evento Enter para los TextBox
void MainFormReserva::textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender;
    if (textBox->ForeColor == System::Drawing::Color::Gray) {
        // Limpia el texto si el color es gris (marcador de posición)
        textBox->Text = "";
        textBox->ForeColor = System::Drawing::Color::Black; // Cambia el color del texto a negro
    }
}

// Maneja el evento Leave para los TextBox
void MainFormReserva::textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender;
    if (String::IsNullOrWhiteSpace(textBox->Text)) {
        // Restaura el texto del marcador de posición si el TextBox está vacío
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
        textBox->ForeColor = System::Drawing::Color::Gray; // Cambia el color del texto a gris (marcador de posición)
    }
}

// Maneja el evento Click para el botón Create
void MainFormReserva::buttonCreate_Click(System::Object^ sender, System::EventArgs^ e) {
    // Crea un objeto Reserva con los valores de los TextBox
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

    // Llama al método insertarReserva de ReservaCRUD para insertar la reserva en la base de datos
    ReservaCRUD::insertarReserva(reserva, connectionString);
}

// Maneja el evento Click para el botón Read
void MainFormReserva::buttonRead_Click(System::Object^ sender, System::EventArgs^ e) {
    DataTable^ dt = gcnew DataTable(); // Crea un DataTable para almacenar los datos
    ReservaCRUD::leerReservas(dt, connectionString); // Llena el DataTable con los datos de las reservas
    dataGridView1->DataSource = dt; // Establece el DataTable como fuente de datos del DataGridView
}

// Maneja el evento Click para el botón Update
void MainFormReserva::buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
    // Crea un objeto Reserva con los valores de los TextBox
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
    // Llama al método actualizarReserva de ReservaCRUD para actualizar la reserva en la base de datos
    ReservaCRUD::actualizarReserva(reserva, connectionString);
}

// Maneja el evento Click para el botón Delete
void MainFormReserva::buttonDeleteRow_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridView1->SelectedRows->Count > 0) {
        // Obtiene el número de la reserva de la fila seleccionada
        String^ numeroReserva = dataGridView1->SelectedRows[0]->Cells["numero_reserva"]->Value->ToString();
        // Llama al método eliminarReserva de ReservaCRUD para eliminar la reserva de la base de datos
        ReservaCRUD::eliminarReserva(numeroReserva, connectionString);
        buttonRead_Click(sender, e); // Refresca los datos del DataGridView
    }
    else {
        MessageBox::Show("Por favor, selecciona una fila para eliminar."); // Muestra un mensaje si no hay filas seleccionadas
    }
}
