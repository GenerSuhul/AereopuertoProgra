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
    SetPlaceholder(textBoxCodigo, "Código Aerolínea");
    SetPlaceholder(textBoxNombre, "Nombre Aerolínea");
    SetPlaceholder(textBoxUbicacion, "Ubicación");
}

// Definición del método SetPlaceholder
void MainForm::SetPlaceholder(System::Windows::Forms::TextBox^ textBox, System::String^ placeholderText) {
    textBox->Text = placeholderText;
    textBox->ForeColor = System::Drawing::Color::Gray;

    textBox->Enter += gcnew System::EventHandler(this, &MainForm::textBox_Enter);
    textBox->Leave += gcnew System::EventHandler(this, &MainForm::textBox_Leave);
}

void MainForm::textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender;
    if (textBox->ForeColor == System::Drawing::Color::Gray) {
        textBox->Text = "";
        textBox->ForeColor = System::Drawing::Color::Black;
    }
}

void MainForm::textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender;
    if (String::IsNullOrWhiteSpace(textBox->Text)) {
        if (textBox == textBoxCodigo) {
            textBox->Text = "Código Aerolínea";
        }
        else if (textBox == textBoxNombre) {
            textBox->Text = "Nombre Aerolínea";
        }
        else if (textBox == textBoxUbicacion) {
            textBox->Text = "Ubicación";
        }
        textBox->ForeColor = System::Drawing::Color::Gray;
    }
}

void MainForm::buttonCreate_Click(System::Object^ sender, System::EventArgs^ e) {
    Aerolinea^ aerolinea = gcnew Aerolinea(
        textBoxCodigo->Text,
        textBoxNombre->Text,
        textBoxUbicacion->Text
    );

    AerolineaCRUD::insertarAerolinea(aerolinea, connectionString);
}

void MainForm::buttonRead_Click(System::Object^ sender, System::EventArgs^ e) {
    DataTable^ dt = gcnew DataTable();
    MySqlConnection^ con = gcnew MySqlConnection(connectionString);
    MySqlDataAdapter^ da = gcnew MySqlDataAdapter("SELECT * FROM Aerolineas", con);

    try {
        con->Open();
        da->Fill(dt);
        dataGridView1->DataSource = dt;
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }
    finally {
        con->Close();
    }
}

void MainForm::buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
    Aerolinea^ aerolinea = gcnew Aerolinea(
        textBoxCodigo->Text,
        textBoxNombre->Text,
        textBoxUbicacion->Text
    );
    AerolineaCRUD::actualizarAerolinea(aerolinea, connectionString);
}

void MainForm::buttonDeleteRow_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridView1->SelectedRows->Count > 0) {
        String^ codigo = dataGridView1->SelectedRows[0]->Cells["codigo_aerolinea"]->Value->ToString();
        AerolineaCRUD::eliminarAerolinea(codigo, connectionString);
        buttonRead_Click(sender, e); // Refresca los datos del DataGridView
    }
    else {
        MessageBox::Show("Por favor, selecciona una fila para eliminar.");
    }
}



