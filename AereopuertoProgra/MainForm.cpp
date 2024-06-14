#include "pch.h"
#include "MainForm.h"
#include "MainFormPasajero.h"
#include "MainFormVuelo.h"
#include "MainFormReserva.h"
#include "MainFormBoleto.h"
#include "Aerolinea.h"
#include "AerolineaCRUD.h"

using namespace AereopuertoProgra;

// Definición del método InitializePlaceholderText
void MainForm::InitializePlaceholderText() {
    // Inicializa los textos de marcador de posición para los TextBox
    SetPlaceholder(textBoxCodigo, "Código Aerolínea");
    SetPlaceholder(textBoxNombre, "Nombre Aerolínea");
    SetPlaceholder(textBoxUbicacion, "Ubicación");
}

// Definición del método SetPlaceholder
void MainForm::SetPlaceholder(System::Windows::Forms::TextBox^ textBox, System::String^ placeholderText) {
    textBox->Text = placeholderText; // Establece el texto del marcador de posición
    textBox->ForeColor = System::Drawing::Color::Gray; // Establece el color del texto del marcador de posición

    // Asigna los eventos Enter y Leave para manejar el foco en los TextBox
    textBox->Enter += gcnew System::EventHandler(this, &MainForm::textBox_Enter);
    textBox->Leave += gcnew System::EventHandler(this, &MainForm::textBox_Leave);
}

// Maneja el evento Enter para los TextBox
void MainForm::textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender; // Convierte el sender a TextBox
    if (textBox->ForeColor == System::Drawing::Color::Gray) {
        textBox->Text = ""; // Limpia el texto si el color es gris (marcador de posición)
        textBox->ForeColor = System::Drawing::Color::Black; // Cambia el color del texto a negro
    }
}

// Maneja el evento Leave para los TextBox
void MainForm::textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender; // Convierte el sender a TextBox
    if (String::IsNullOrWhiteSpace(textBox->Text)) {
        // Restaura el texto del marcador de posición si el TextBox está vacío
        if (textBox == textBoxCodigo) {
            textBox->Text = "Código Aerolínea";
        }
        else if (textBox == textBoxNombre) {
            textBox->Text = "Nombre Aerolínea";
        }
        else if (textBox == textBoxUbicacion) {
            textBox->Text = "Ubicación";
        }
        textBox->ForeColor = System::Drawing::Color::Gray; // Cambia el color del texto a gris (marcador de posición)
    }
}

// Maneja el evento Click para el botón Create
void MainForm::buttonCreate_Click(System::Object^ sender, System::EventArgs^ e) {
    // Crea un objeto Aerolinea con los valores de los TextBox
    Aerolinea^ aerolinea = gcnew Aerolinea(
        textBoxCodigo->Text,
        textBoxNombre->Text,
        textBoxUbicacion->Text
    );

    // Llama al método insertarAerolinea de AerolineaCRUD para insertar la aerolínea en la base de datos
    AerolineaCRUD::insertarAerolinea(aerolinea, connectionString);
}

// Maneja el evento Click para el botón Read
void MainForm::buttonRead_Click(System::Object^ sender, System::EventArgs^ e) {
    DataTable^ dt = gcnew DataTable(); // Crea un DataTable para almacenar los datos
    MySqlConnection^ con = gcnew MySqlConnection(connectionString); // Crea una conexión a la base de datos
    MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT * FROM Aerolineas", con); // Crea un adaptador de datos para ejecutar la consulta SQL

    try {
        con->Open(); // Abre la conexión a la base de datos
        da->Fill(dt); // Llena el DataTable con los datos de la consulta
        dataGridView1->DataSource = dt; // Establece el DataTable como fuente de datos del DataGridView
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message); // Muestra un mensaje de error si ocurre una excepción
    }
    finally {
        con->Close(); // Cierra la conexión a la base de datos
    }
}

// Maneja el evento Click para el botón Update
void MainForm::buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
    // Crea un objeto Aerolinea con los valores de los TextBox
    Aerolinea^ aerolinea = gcnew Aerolinea(
        textBoxCodigo->Text,
        textBoxNombre->Text,
        textBoxUbicacion->Text
    );
    // Llama al método actualizarAerolinea de AerolineaCRUD para actualizar la aerolínea en la base de datos
    AerolineaCRUD::actualizarAerolinea(aerolinea, connectionString);
}

// Maneja el evento Click para el botón Delete
void MainForm::buttonDeleteRow_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridView1->SelectedRows->Count > 0) {
        // Obtiene el código de la aerolínea de la fila seleccionada
        String^ codigo = dataGridView1->SelectedRows[0]->Cells["codigo_aerolinea"]->Value->ToString();
        // Llama al método eliminarAerolinea de AerolineaCRUD para eliminar la aerolínea de la base de datos
        AerolineaCRUD::eliminarAerolinea(codigo, connectionString);
        buttonRead_Click(sender, e); // Refresca los datos del DataGridView
    }
    else {
        MessageBox::Show("Por favor, selecciona una fila para eliminar."); // Muestra un mensaje si no hay filas seleccionadas
    }
}
