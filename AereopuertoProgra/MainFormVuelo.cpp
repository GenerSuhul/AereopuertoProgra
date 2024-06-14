#include "pch.h"
#include "MainFormVuelo.h"
#include "Vuelo.h"
#include "VueloCRUD.h"
#include "DetallesVuelo.h"

using namespace AereopuertoProgra;

// Método para inicializar el texto de marcador de posición en los TextBox
void MainFormVuelo::InitializePlaceholderText() {
    SetPlaceholder(textBoxNumeroVuelo, "Número Vuelo");
    SetPlaceholder(textBoxCodigoAerolinea, "Código Aerolínea");
    SetPlaceholder(textBoxRutaOrigen, "Ruta Origen");
    SetPlaceholder(textBoxRutaDestino, "Ruta Destino");
}

// Método para establecer el marcador de posición en un TextBox
void MainFormVuelo::SetPlaceholder(System::Windows::Forms::TextBox^ textBox, System::String^ placeholderText) {
    textBox->Text = placeholderText; // Establece el texto del marcador de posición
    textBox->ForeColor = System::Drawing::Color::Gray; // Cambia el color del texto a gris

    // Asigna eventos Enter y Leave para manejar el foco en los TextBox
    textBox->Enter += gcnew System::EventHandler(this, &MainFormVuelo::textBox_Enter);
    textBox->Leave += gcnew System::EventHandler(this, &MainFormVuelo::textBox_Leave);
}

// Evento para manejar cuando un TextBox gana el foco
void MainFormVuelo::textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender;
    if (textBox->ForeColor == System::Drawing::Color::Gray) {
        textBox->Text = ""; // Limpia el texto si es el marcador de posición
        textBox->ForeColor = System::Drawing::Color::Black; // Cambia el color del texto a negro
    }
}

// Evento para manejar cuando un TextBox pierde el foco
void MainFormVuelo::textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender;
    if (String::IsNullOrWhiteSpace(textBox->Text)) {
        // Restaura el texto del marcador de posición si el TextBox está vacío
        if (textBox == textBoxNumeroVuelo) {
            textBox->Text = "Número Vuelo";
        }
        else if (textBox == textBoxCodigoAerolinea) {
            textBox->Text = "Código Aerolínea";
        }
        else if (textBox == textBoxRutaOrigen) {
            textBox->Text = "Ruta Origen";
        }
        else if (textBox == textBoxRutaDestino) {
            textBox->Text = "Ruta Destino";
        }
        textBox->ForeColor = System::Drawing::Color::Gray; // Cambia el color del texto a gris
    }
}

// Evento para manejar el clic en el botón Create
void MainFormVuelo::buttonCreate_Click(System::Object^ sender, System::EventArgs^ e) {
    // Crea un objeto Vuelo con los valores de los TextBox
    Vuelo^ vuelo = gcnew Vuelo(
        textBoxNumeroVuelo->Text,
        textBoxCodigoAerolinea->Text,
        textBoxRutaOrigen->Text,
        textBoxRutaDestino->Text
    );

    // Llama al método insertarVuelo de VueloCRUD para insertar el vuelo en la base de datos
    VueloCRUD::insertarVuelo(vuelo, connectionString);
}

// Evento para manejar el clic en el botón Read
void MainFormVuelo::buttonRead_Click(System::Object^ sender, System::EventArgs^ e) {
    DataTable^ dt = gcnew DataTable(); // Crea un DataTable para almacenar los datos
    VueloCRUD::leerVuelos(dt, connectionString); // Llena el DataTable con los datos de los vuelos
    dataGridView1->DataSource = dt; // Establece el DataTable como fuente de datos del DataGridView
}

// Evento para manejar el clic en el botón Update
void MainFormVuelo::buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
    // Crea un objeto Vuelo con los valores de los TextBox
    Vuelo^ vuelo = gcnew Vuelo(
        textBoxNumeroVuelo->Text,
        textBoxCodigoAerolinea->Text,
        textBoxRutaOrigen->Text,
        textBoxRutaDestino->Text
    );

    // Llama al método actualizarVuelo de VueloCRUD para actualizar el vuelo en la base de datos
    VueloCRUD::actualizarVuelo(vuelo, connectionString);
}

// Evento para manejar el clic en el botón Delete
void MainFormVuelo::buttonDeleteRow_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridView1->SelectedRows->Count > 0) {
        // Obtiene el número de vuelo de la fila seleccionada
        String^ numeroVuelo = dataGridView1->SelectedRows[0]->Cells["numero_vuelo"]->Value->ToString();
        // Llama al método eliminarVuelo de VueloCRUD para eliminar el vuelo de la base de datos
        VueloCRUD::eliminarVuelo(numeroVuelo, connectionString);
        buttonRead_Click(sender, e); // Refresca los datos del DataGridView
    }
    else {
        MessageBox::Show("Por favor, selecciona una fila para eliminar."); // Muestra un mensaje si no hay filas seleccionadas
    }
}

// Evento para manejar el clic en el botón Detalles
void MainFormVuelo::buttonDetalles_Click(System::Object^ sender, System::EventArgs^ e) {
    DetallesVuelo^ detallesVueloForm = gcnew DetallesVuelo(); // Crea una instancia del formulario DetallesVuelo
    detallesVueloForm->ShowDialog(); // Muestra el formulario DetallesVuelo como un cuadro de diálogo modal
}
