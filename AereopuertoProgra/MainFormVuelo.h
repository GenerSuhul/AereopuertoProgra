#pragma once

namespace AereopuertoProgra {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class MainFormVuelo : public System::Windows::Forms::Form {
    public:
        MainFormVuelo(void) {
            InitializeComponent();
            InitializePlaceholderText();
            connectionString = "Server = 127.0.0.1; Database = Aereopuerto_Progra; Uid = Gener; Pwd = Gener2004#;";
        }

    protected:
        ~MainFormVuelo() {
            if (components) {
                delete components;
            }
        }

    private:
        System::Windows::Forms::DataGridView^ dataGridView1;
        System::Windows::Forms::Button^ buttonCreate;
        System::Windows::Forms::Button^ buttonRead;
        System::Windows::Forms::Button^ buttonUpdate;
        System::Windows::Forms::Button^ buttonDeleteRow;
        System::Windows::Forms::Button^ buttonDetalles;

        System::String^ connectionString;

        System::Windows::Forms::TextBox^ textBoxNumeroVuelo;
        System::Windows::Forms::TextBox^ textBoxCodigoAerolinea;
        System::Windows::Forms::TextBox^ textBoxRutaOrigen;
        System::Windows::Forms::TextBox^ textBoxRutaDestino;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->buttonCreate = (gcnew System::Windows::Forms::Button());
            this->buttonRead = (gcnew System::Windows::Forms::Button());
            this->buttonUpdate = (gcnew System::Windows::Forms::Button());
            this->buttonDeleteRow = (gcnew System::Windows::Forms::Button());
            this->buttonDetalles = (gcnew System::Windows::Forms::Button());
            this->textBoxNumeroVuelo = (gcnew System::Windows::Forms::TextBox());
            this->textBoxCodigoAerolinea = (gcnew System::Windows::Forms::TextBox());
            this->textBoxRutaOrigen = (gcnew System::Windows::Forms::TextBox());
            this->textBoxRutaDestino = (gcnew System::Windows::Forms::TextBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(16, 15);
            this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->RowHeadersWidth = 51;
            this->dataGridView1->Size = System::Drawing::Size(1013, 369);
            this->dataGridView1->TabIndex = 0;
            // 
            // buttonCreate
            // 
            this->buttonCreate->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonCreate->Location = System::Drawing::Point(16, 441);
            this->buttonCreate->Margin = System::Windows::Forms::Padding(4);
            this->buttonCreate->Name = L"buttonCreate";
            this->buttonCreate->Size = System::Drawing::Size(100, 28);
            this->buttonCreate->TabIndex = 1;
            this->buttonCreate->Text = L"Create";
            this->buttonCreate->UseVisualStyleBackColor = true;
            this->buttonCreate->Click += gcnew System::EventHandler(this, &MainFormVuelo::buttonCreate_Click);
            // 
            // buttonRead
            // 
            this->buttonRead->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonRead->Location = System::Drawing::Point(124, 441);
            this->buttonRead->Margin = System::Windows::Forms::Padding(4);
            this->buttonRead->Name = L"buttonRead";
            this->buttonRead->Size = System::Drawing::Size(100, 28);
            this->buttonRead->TabIndex = 2;
            this->buttonRead->Text = L"Read";
            this->buttonRead->UseVisualStyleBackColor = true;
            this->buttonRead->Click += gcnew System::EventHandler(this, &MainFormVuelo::buttonRead_Click);
            // 
            // buttonUpdate
            // 
            this->buttonUpdate->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonUpdate->Location = System::Drawing::Point(232, 441);
            this->buttonUpdate->Margin = System::Windows::Forms::Padding(4);
            this->buttonUpdate->Name = L"buttonUpdate";
            this->buttonUpdate->Size = System::Drawing::Size(100, 28);
            this->buttonUpdate->TabIndex = 3;
            this->buttonUpdate->Text = L"Update";
            this->buttonUpdate->UseVisualStyleBackColor = true;
            this->buttonUpdate->Click += gcnew System::EventHandler(this, &MainFormVuelo::buttonUpdate_Click);
            // 
            // buttonDeleteRow
            // 
            this->buttonDeleteRow->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonDeleteRow->Location = System::Drawing::Point(340, 441);
            this->buttonDeleteRow->Margin = System::Windows::Forms::Padding(4);
            this->buttonDeleteRow->Name = L"buttonDeleteRow";
            this->buttonDeleteRow->Size = System::Drawing::Size(100, 28);
            this->buttonDeleteRow->TabIndex = 4;
            this->buttonDeleteRow->Text = L"Eliminar fila";
            this->buttonDeleteRow->UseVisualStyleBackColor = true;
            this->buttonDeleteRow->Click += gcnew System::EventHandler(this, &MainFormVuelo::buttonDeleteRow_Click);
            // 
            // buttonDetalles
            // 
            this->buttonDetalles->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonDetalles->Location = System::Drawing::Point(448, 441);
            this->buttonDetalles->Margin = System::Windows::Forms::Padding(4);
            this->buttonDetalles->Name = L"buttonDetalles";
            this->buttonDetalles->Size = System::Drawing::Size(100, 28);
            this->buttonDetalles->TabIndex = 5;
            this->buttonDetalles->Text = L"Detalles";
            this->buttonDetalles->UseVisualStyleBackColor = true;
            this->buttonDetalles->Click += gcnew System::EventHandler(this, &MainFormVuelo::buttonDetalles_Click);
            // 
            // textBoxNumeroVuelo
            // 
            this->textBoxNumeroVuelo->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxNumeroVuelo->ForeColor = System::Drawing::Color::Gray;
            this->textBoxNumeroVuelo->Location = System::Drawing::Point(16, 394);
            this->textBoxNumeroVuelo->Margin = System::Windows::Forms::Padding(4);
            this->textBoxNumeroVuelo->Name = L"textBoxNumeroVuelo";
            this->textBoxNumeroVuelo->Size = System::Drawing::Size(132, 23);
            this->textBoxNumeroVuelo->TabIndex = 5;
            this->textBoxNumeroVuelo->Text = L"Número Vuelo";
            this->textBoxNumeroVuelo->Enter += gcnew System::EventHandler(this, &MainFormVuelo::textBox_Enter);
            this->textBoxNumeroVuelo->Leave += gcnew System::EventHandler(this, &MainFormVuelo::textBox_Leave);
            // 
            // textBoxCodigoAerolinea
            // 
            this->textBoxCodigoAerolinea->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxCodigoAerolinea->ForeColor = System::Drawing::Color::Gray;
            this->textBoxCodigoAerolinea->Location = System::Drawing::Point(157, 394);
            this->textBoxCodigoAerolinea->Margin = System::Windows::Forms::Padding(4);
            this->textBoxCodigoAerolinea->Name = L"textBoxCodigoAerolinea";
            this->textBoxCodigoAerolinea->Size = System::Drawing::Size(132, 23);
            this->textBoxCodigoAerolinea->TabIndex = 6;
            this->textBoxCodigoAerolinea->Text = L"Código Aerolínea";
            this->textBoxCodigoAerolinea->Enter += gcnew System::EventHandler(this, &MainFormVuelo::textBox_Enter);
            this->textBoxCodigoAerolinea->Leave += gcnew System::EventHandler(this, &MainFormVuelo::textBox_Leave);
            // 
            // textBoxRutaOrigen
            // 
            this->textBoxRutaOrigen->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxRutaOrigen->ForeColor = System::Drawing::Color::Gray;
            this->textBoxRutaOrigen->Location = System::Drawing::Point(299, 394);
            this->textBoxRutaOrigen->Margin = System::Windows::Forms::Padding(4);
            this->textBoxRutaOrigen->Name = L"textBoxRutaOrigen";
            this->textBoxRutaOrigen->Size = System::Drawing::Size(132, 23);
            this->textBoxRutaOrigen->TabIndex = 7;
            this->textBoxRutaOrigen->Text = L"Ruta Origen";
            this->textBoxRutaOrigen->Enter += gcnew System::EventHandler(this, &MainFormVuelo::textBox_Enter);
            this->textBoxRutaOrigen->Leave += gcnew System::EventHandler(this, &MainFormVuelo::textBox_Leave);
            // 
            // textBoxRutaDestino
            // 
            this->textBoxRutaDestino->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxRutaDestino->ForeColor = System::Drawing::Color::Gray;
            this->textBoxRutaDestino->Location = System::Drawing::Point(440, 394);
            this->textBoxRutaDestino->Margin = System::Windows::Forms::Padding(4);
            this->textBoxRutaDestino->Name = L"textBoxRutaDestino";
            this->textBoxRutaDestino->Size = System::Drawing::Size(132, 23);
            this->textBoxRutaDestino->TabIndex = 8;
            this->textBoxRutaDestino->Text = L"Ruta Destino";
            this->textBoxRutaDestino->Enter += gcnew System::EventHandler(this, &MainFormVuelo::textBox_Enter);
            this->textBoxRutaDestino->Leave += gcnew System::EventHandler(this, &MainFormVuelo::textBox_Leave);
            // 
            // MainFormVuelo
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Desktop;
            this->ClientSize = System::Drawing::Size(1045, 494);
            this->Controls->Add(this->buttonDetalles);
            this->Controls->Add(this->textBoxRutaDestino);
            this->Controls->Add(this->textBoxRutaOrigen);
            this->Controls->Add(this->textBoxCodigoAerolinea);
            this->Controls->Add(this->textBoxNumeroVuelo);
            this->Controls->Add(this->buttonDeleteRow);
            this->Controls->Add(this->buttonUpdate);
            this->Controls->Add(this->buttonRead);
            this->Controls->Add(this->buttonCreate);
            this->Controls->Add(this->dataGridView1);
            this->Margin = System::Windows::Forms::Padding(4);
            this->Name = L"MainFormVuelo";
            this->Text = L"MainFormVuelo";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        void InitializePlaceholderText();
        void SetPlaceholder(System::Windows::Forms::TextBox^ textBox, System::String^ placeholderText);
        void textBox_Enter(System::Object^ sender, System::EventArgs^ e);
        void textBox_Leave(System::Object^ sender, System::EventArgs^ e);

        void buttonCreate_Click(System::Object^ sender, System::EventArgs^ e);
        void buttonRead_Click(System::Object^ sender, System::EventArgs^ e);
        void buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e);
        void buttonDeleteRow_Click(System::Object^ sender, System::EventArgs^ e);
        void buttonDetalles_Click(System::Object^ sender, System::EventArgs^ e);
    };
}
