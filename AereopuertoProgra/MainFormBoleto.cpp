#include "pch.h"
#include "MainFormBoleto.h"
#include "Boleto.h"
#include "BoletoCRUD.h"

using namespace AereopuertoProgra;

// Definición del método InitializePlaceholderText
void MainFormBoleto::InitializePlaceholderText() {
    // Inicializa los textos de marcador de posición para los TextBox
    SetPlaceholder(textBoxNumeroBoleto, "Número Boleto");
    SetPlaceholder(textBoxNombrePasajero, "Nombre Pasajero");
    SetPlaceholder(textBoxNumeroReserva, "Número Reserva");
}

// Definición del método SetPlaceholder
void MainFormBoleto::SetPlaceholder(System::Windows::Forms::TextBox^ textBox, System::String^ placeholderText) {
    textBox->Text = placeholderText; // Establece el texto del marcador de posición
    textBox->ForeColor = System::Drawing::Color::Gray; // Establece el color del texto del marcador de posición

    // Asigna los eventos Enter y Leave para manejar el foco en los TextBox
    textBox->Enter += gcnew System::EventHandler(this, &MainFormBoleto::textBox_Enter);
    textBox->Leave += gcnew System::EventHandler(this, &MainFormBoleto::textBox_Leave);
}

// Maneja el evento Enter para los TextBox
void MainFormBoleto::textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender; // Convierte el sender a TextBox
    if (textBox->ForeColor == System::Drawing::Color::Gray) {
        textBox->Text = ""; // Limpia el texto si el color es gris (marcador de posición)
        textBox->ForeColor = System::Drawing::Color::Black; // Cambia el color del texto a negro
    }
}

// Maneja el evento Leave para los TextBox
void MainFormBoleto::textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender; // Convierte el sender a TextBox
    if (String::IsNullOrWhiteSpace(textBox->Text)) {
        // Restaura el texto del marcador de posición si el TextBox está vacío
        if (textBox == textBoxNumeroBoleto) {
            textBox->Text = "Número Boleto";
        }
        else if (textBox == textBoxNombrePasajero) {
            textBox->Text = "Nombre Pasajero";
        }
        else if (textBox == textBoxNumeroReserva) {
            textBox->Text = "Número Reserva";
        }
        textBox->ForeColor = System::Drawing::Color::Gray; // Cambia el color del texto a gris (marcador de posición)
    }
}

// Maneja el evento Click para el botón Create
void MainFormBoleto::buttonCreate_Click(System::Object^ sender, System::EventArgs^ e) {
    // Crea un objeto Boleto con los valores de los TextBox
    Boleto^ boleto = gcnew Boleto(
        textBoxNumeroBoleto->Text,
        textBoxNombrePasajero->Text,
        textBoxNumeroReserva->Text
    );

    // Llama al método insertarBoleto de BoletoCRUD para insertar el boleto en la base de datos
    BoletoCRUD::insertarBoleto(boleto, connectionString);
}

// Maneja el evento Click para el botón Read
void MainFormBoleto::buttonRead_Click(System::Object^ sender, System::EventArgs^ e) {
    DataTable^ dt = gcnew DataTable(); // Crea un DataTable para almacenar los datos
    BoletoCRUD::leerBoletos(dt, connectionString); // Llena el DataTable con los datos de los boletos
    dataGridView1->DataSource = dt; // Establece el DataTable como fuente de datos del DataGridView
}

// Maneja el evento Click para el botón Update
void MainFormBoleto::buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
    // Crea un objeto Boleto con los valores de los TextBox
    Boleto^ boleto = gcnew Boleto(
        textBoxNumeroBoleto->Text,
        textBoxNombrePasajero->Text,
        textBoxNumeroReserva->Text
    );
    // Llama al método actualizarBoleto de BoletoCRUD para actualizar el boleto en la base de datos
    BoletoCRUD::actualizarBoleto(boleto, connectionString);
}

// Maneja el evento Click para el botón Delete
void MainFormBoleto::buttonDeleteRow_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridView1->SelectedRows->Count > 0) {
        // Obtiene el número del boleto de la fila seleccionada
        String^ numeroBoleto = dataGridView1->SelectedRows[0]->Cells["numero_boleto"]->Value->ToString();
        // Llama al método eliminarBoleto de BoletoCRUD para eliminar el boleto de la base de datos
        BoletoCRUD::eliminarBoleto(numeroBoleto, connectionString);
        buttonRead_Click(sender, e); // Refresca los datos del DataGridView
    }
    else {
        MessageBox::Show("Por favor, selecciona una fila para eliminar."); // Muestra un mensaje si no hay filas seleccionadas
    }
}
