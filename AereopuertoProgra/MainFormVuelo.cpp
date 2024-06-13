#include "pch.h"
#include "MainFormVuelo.h"
#include "Vuelo.h"
#include "VueloCRUD.h"
#include "DetallesVuelo.h"

using namespace AereopuertoProgra;

void MainFormVuelo::InitializePlaceholderText() {
    SetPlaceholder(textBoxNumeroVuelo, "Número Vuelo");
    SetPlaceholder(textBoxCodigoAerolinea, "Código Aerolínea");
    SetPlaceholder(textBoxRutaOrigen, "Ruta Origen");
    SetPlaceholder(textBoxRutaDestino, "Ruta Destino");
}

void MainFormVuelo::SetPlaceholder(System::Windows::Forms::TextBox^ textBox, System::String^ placeholderText) {
    textBox->Text = placeholderText;
    textBox->ForeColor = System::Drawing::Color::Gray;

    textBox->Enter += gcnew System::EventHandler(this, &MainFormVuelo::textBox_Enter);
    textBox->Leave += gcnew System::EventHandler(this, &MainFormVuelo::textBox_Leave);
}

void MainFormVuelo::textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender;
    if (textBox->ForeColor == System::Drawing::Color::Gray) {
        textBox->Text = "";
        textBox->ForeColor = System::Drawing::Color::Black;
    }
}

void MainFormVuelo::textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender;
    if (String::IsNullOrWhiteSpace(textBox->Text)) {
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
        textBox->ForeColor = System::Drawing::Color::Gray;
    }
}

void MainFormVuelo::buttonCreate_Click(System::Object^ sender, System::EventArgs^ e) {
    Vuelo^ vuelo = gcnew Vuelo(
        textBoxNumeroVuelo->Text,
        textBoxCodigoAerolinea->Text,
        textBoxRutaOrigen->Text,
        textBoxRutaDestino->Text
    );

    VueloCRUD::insertarVuelo(vuelo, connectionString);
}

void MainFormVuelo::buttonRead_Click(System::Object^ sender, System::EventArgs^ e) {
    DataTable^ dt = gcnew DataTable();
    VueloCRUD::leerVuelos(dt, connectionString);
    dataGridView1->DataSource = dt;
}

void MainFormVuelo::buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
    Vuelo^ vuelo = gcnew Vuelo(
        textBoxNumeroVuelo->Text,
        textBoxCodigoAerolinea->Text,
        textBoxRutaOrigen->Text,
        textBoxRutaDestino->Text
    );
    VueloCRUD::actualizarVuelo(vuelo, connectionString);
}

void MainFormVuelo::buttonDeleteRow_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridView1->SelectedRows->Count > 0) {
        String^ numeroVuelo = dataGridView1->SelectedRows[0]->Cells["numero_vuelo"]->Value->ToString();
        VueloCRUD::eliminarVuelo(numeroVuelo, connectionString);
        buttonRead_Click(sender, e); // Refresca los datos del DataGridView
    }
    else {
        MessageBox::Show("Por favor, selecciona una fila para eliminar.");
    }
}

void MainFormVuelo::buttonDetalles_Click(System::Object^ sender, System::EventArgs^ e) {
    DetallesVuelo^ detallesVueloForm = gcnew DetallesVuelo();
    detallesVueloForm->ShowDialog();
}
