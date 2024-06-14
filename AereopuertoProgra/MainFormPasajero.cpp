#include "pch.h"
#include "MainFormPasajero.h"
#include "Pasajero.h"
#include "PasajeroCRUD.h"

using namespace AereopuertoProgra;

// Definición del método InitializePlaceholderText
void MainFormPasajero::InitializePlaceholderText() {
    // Inicializa los textos de marcador de posición para los TextBox
    SetPlaceholder(textBoxNumeroPasajero, "Número Pasajero");
    SetPlaceholder(textBoxNombre, "Nombre");
    SetPlaceholder(textBoxApellido, "Apellido");
    SetPlaceholder(textBoxEmail, "Email");
    SetPlaceholder(textBoxTelefono, "Telefono");
}

// Definición del método SetPlaceholder
void MainFormPasajero::SetPlaceholder(System::Windows::Forms::TextBox^ textBox, System::String^ placeholderText) {
    textBox->Text = placeholderText; // Establece el texto del marcador de posición
    textBox->ForeColor = System::Drawing::Color::Gray; // Establece el color del texto del marcador de posición

    // Asigna los eventos Enter y Leave para manejar el foco en los TextBox
    textBox->Enter += gcnew System::EventHandler(this, &MainFormPasajero::textBox_Enter);
    textBox->Leave += gcnew System::EventHandler(this, &MainFormPasajero::textBox_Leave);
}

// Maneja el evento Enter para los TextBox
void MainFormPasajero::textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender; // Convierte el sender a TextBox
    if (textBox->ForeColor == System::Drawing::Color::Gray) {
        textBox->Text = ""; // Limpia el texto si el color es gris (marcador de posición)
        textBox->ForeColor = System::Drawing::Color::Black; // Cambia el color del texto a negro
    }
}

// Maneja el evento Leave para los TextBox
void MainFormPasajero::textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender; // Convierte el sender a TextBox
    if (String::IsNullOrWhiteSpace(textBox->Text)) {
        // Restaura el texto del marcador de posición si el TextBox está vacío
        if (textBox == textBoxNumeroPasajero) {
            textBox->Text = "Número Pasajero";
        }
        else if (textBox == textBoxNombre) {
            textBox->Text = "Nombre";
        }
        else if (textBox == textBoxApellido) {
            textBox->Text = "Apellido";
        }
        else if (textBox == textBoxEmail) {
            textBox->Text = "Email";
        }
        else if (textBox == textBoxTelefono) {
            textBox->Text = "Telefono";
        }
        textBox->ForeColor = System::Drawing::Color::Gray; // Cambia el color del texto a gris (marcador de posición)
    }
}

// Maneja el evento Click para el botón Create
void MainFormPasajero::buttonCreate_Click(System::Object^ sender, System::EventArgs^ e) {
    // Crea un objeto Pasajero con los valores de los TextBox
    Pasajero^ pasajero = gcnew Pasajero(
        textBoxNumeroPasajero->Text,
        textBoxNombre->Text,
        textBoxApellido->Text,
        textBoxEmail->Text,
        textBoxTelefono->Text
    );

    // Llama al método insertarPasajero de PasajeroCRUD para insertar el pasajero en la base de datos
    PasajeroCRUD::insertarPasajero(pasajero, connectionString);
}

// Maneja el evento Click para el botón Read
void MainFormPasajero::buttonRead_Click(System::Object^ sender, System::EventArgs^ e) {
    DataTable^ dt = gcnew DataTable(); // Crea un DataTable para almacenar los datos
    PasajeroCRUD::leerPasajeros(dt, connectionString); // Llena el DataTable con los datos de los pasajeros
    dataGridView1->DataSource = dt; // Establece el DataTable como fuente de datos del DataGridView
}

// Maneja el evento Click para el botón Update
void MainFormPasajero::buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
    // Crea un objeto Pasajero con los valores de los TextBox
    Pasajero^ pasajero = gcnew Pasajero(
        textBoxNumeroPasajero->Text,
        textBoxNombre->Text,
        textBoxApellido->Text,
        textBoxEmail->Text,
        textBoxTelefono->Text
    );
    // Llama al método actualizarPasajero de PasajeroCRUD para actualizar el pasajero en la base de datos
    PasajeroCRUD::actualizarPasajero(pasajero, connectionString);
}

// Maneja el evento Click para el botón Delete
void MainFormPasajero::buttonDeleteRow_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridView1->SelectedRows->Count > 0) {
        // Obtiene el número del pasajero de la fila seleccionada
        String^ numeroPasajero = dataGridView1->SelectedRows[0]->Cells["numero_pasajero"]->Value->ToString();
        // Llama al método eliminarPasajero de PasajeroCRUD para eliminar el pasajero de la base de datos
        PasajeroCRUD::eliminarPasajero(numeroPasajero, connectionString);
        buttonRead_Click(sender, e); // Refresca los datos del DataGridView
    }
    else {
        MessageBox::Show("Por favor, selecciona una fila para eliminar."); // Muestra un mensaje si no hay filas seleccionadas
    }
}
