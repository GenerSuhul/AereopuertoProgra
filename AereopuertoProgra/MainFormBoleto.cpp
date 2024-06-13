#include "pch.h"
#include "MainFormBoleto.h"
#include "Boleto.h"
#include "BoletoCRUD.h"

using namespace AereopuertoProgra;

// Definición del método InitializePlaceholderText
void MainFormBoleto::InitializePlaceholderText() {
    SetPlaceholder(textBoxNumeroBoleto, "Número Boleto");
    SetPlaceholder(textBoxNombrePasajero, "Nombre Pasajero");
    SetPlaceholder(textBoxNumeroReserva, "Número Reserva");
}

// Definición del método SetPlaceholder
void MainFormBoleto::SetPlaceholder(System::Windows::Forms::TextBox^ textBox, System::String^ placeholderText) {
    textBox->Text = placeholderText;
    textBox->ForeColor = System::Drawing::Color::Gray;

    textBox->Enter += gcnew System::EventHandler(this, &MainFormBoleto::textBox_Enter);
    textBox->Leave += gcnew System::EventHandler(this, &MainFormBoleto::textBox_Leave);
}

void MainFormBoleto::textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender;
    if (textBox->ForeColor == System::Drawing::Color::Gray) {
        textBox->Text = "";
        textBox->ForeColor = System::Drawing::Color::Black;
    }
}

void MainFormBoleto::textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
    TextBox^ textBox = (TextBox^)sender;
    if (String::IsNullOrWhiteSpace(textBox->Text)) {
        if (textBox == textBoxNumeroBoleto) {
            textBox->Text = "Número Boleto";
        }
        else if (textBox == textBoxNombrePasajero) {
            textBox->Text = "Nombre Pasajero";
        }
        else if (textBox == textBoxNumeroReserva) {
            textBox->Text = "Número Reserva";
        }
        textBox->ForeColor = System::Drawing::Color::Gray;
    }
}

void MainFormBoleto::buttonCreate_Click(System::Object^ sender, System::EventArgs^ e) {
    Boleto^ boleto = gcnew Boleto(
        textBoxNumeroBoleto->Text,
        textBoxNombrePasajero->Text,
        textBoxNumeroReserva->Text
    );

    BoletoCRUD::insertarBoleto(boleto, connectionString);
}

void MainFormBoleto::buttonRead_Click(System::Object^ sender, System::EventArgs^ e) {
    DataTable^ dt = gcnew DataTable();
    BoletoCRUD::leerBoletos(dt, connectionString);
    dataGridView1->DataSource = dt;
}

void MainFormBoleto::buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
    Boleto^ boleto = gcnew Boleto(
        textBoxNumeroBoleto->Text,
        textBoxNombrePasajero->Text,
        textBoxNumeroReserva->Text
    );
    BoletoCRUD::actualizarBoleto(boleto, connectionString);
}

void MainFormBoleto::buttonDeleteRow_Click(System::Object^ sender, System::EventArgs^ e) {
    if (dataGridView1->SelectedRows->Count > 0) {
        String^ numeroBoleto = dataGridView1->SelectedRows[0]->Cells["numero_boleto"]->Value->ToString();
        BoletoCRUD::eliminarBoleto(numeroBoleto, connectionString);
        buttonRead_Click(sender, e); // Refresca los datos del DataGridView
    }
    else {
        MessageBox::Show("Por favor, selecciona una fila para eliminar.");
    }
}
