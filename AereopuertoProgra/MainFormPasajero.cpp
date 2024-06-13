#include "pch.h"
#include "MainFormPasajero.h"
#include "Pasajero.h"
#include "PasajeroCRUD.h"

using namespace AereopuertoProgra;

// Definición del método InitializePlaceholderText
void MainFormPasajero::InitializePlaceholderText() {
    SetPlaceholder(textBoxNumeroPasajero, "Número Pasajero");
    SetPlaceholder(textBoxNombre, "Nombre");
    SetPlaceholder(textBoxApellido, "Apellido");
    SetPlaceholder(textBoxEmail, "Email");
    SetPlaceholder(textBoxTelefono, "Telefono");
}

// Definición del método SetPlaceholder
void MainFormPasajero::SetPlaceholder(System::Windows::Forms::TextBox^ textBox, System::String^ placeholderText) {
    textBox->Text = placeholderText;
    textBox->ForeColor = System::Drawing::Color::Gray;

    textBox->Enter += gcnew System::EventHandler(this, &MainFormPasajero::textBox_Enter);
    textBox->Leave += gcnew System::EventHandler(this, &MainFormPasajero::textBox_Leave);
}

void MainFormPasajero::textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender;
    if (textBox->ForeColor == System::Drawing::Color::Gray) {
        textBox->Text = "";
        textBox->ForeColor = System::Drawing::Color::Black;
    }
}

void MainFormPasajero::textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender;
    if (String::IsNullOrWhiteSpace(textBox->Text)) {
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
        textBox->ForeColor = System::Drawing::Color::Gray;
    }
}

void MainFormPasajero::buttonCreate_Click(System::Object^ sender, System::EventArgs^ e) {
    Pasajero^ pasajero = gcnew Pasajero(
        textBoxNumeroPasajero->Text,
        textBoxNombre->Text,
        textBoxApellido->Text,
        textBoxEmail->Text,
        textBoxTelefono->Text
    );

    PasajeroCRUD::insertarPasajero(pasajero, connectionString);
}

void MainFormPasajero::buttonRead_Click(System::Object^ sender, System::EventArgs^ e) {
    DataTable^ dt = gcnew DataTable();
    PasajeroCRUD::leerPasajeros(dt, connectionString);
    dataGridView1->DataSource = dt;
}

void MainFormPasajero::buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
    Pasajero^ pasajero = gcnew Pasajero(
        textBoxNumeroPasajero->Text,
        textBoxNombre->Text,
        textBoxApellido->Text,
        textBoxEmail->Text,
        textBoxTelefono->Text
    );
    PasajeroCRUD::actualizarPasajero(pasajero, connectionString);
}

void MainFormPasajero::buttonDeleteRow_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridView1->SelectedRows->Count > 0) {
        String^ numeroPasajero = dataGridView1->SelectedRows[0]->Cells["numero_pasajero"]->Value->ToString();
        PasajeroCRUD::eliminarPasajero(numeroPasajero, connectionString);
        buttonRead_Click(sender, e); // Refresca los datos del DataGridView
    }
    else {
        MessageBox::Show("Por favor, selecciona una fila para eliminar.");
    }
}
