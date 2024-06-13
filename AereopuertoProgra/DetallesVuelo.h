#pragma once

namespace AereopuertoProgra {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class DetallesVuelo : public System::Windows::Forms::Form {
    public:
        DetallesVuelo(void) {
            InitializeComponent();
            connectionString = "Server = 127.0.0.1; Database = Aereopuerto_Progra; Uid = Gener; Pwd = Gener2004#;";
            LoadData();
        }

    protected:
        ~DetallesVuelo() {
            if (components) {
                delete components;
            }
        }

    private:
        System::Windows::Forms::DataGridView^ dataGridViewVuelos;
        System::Windows::Forms::Button^ buttonVerDetalles;
        System::Windows::Forms::TextBox^ textBoxDetalles;
        System::String^ connectionString; // Cadena de conexión

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->dataGridViewVuelos = (gcnew System::Windows::Forms::DataGridView());
            this->buttonVerDetalles = (gcnew System::Windows::Forms::Button());
            this->textBoxDetalles = (gcnew System::Windows::Forms::TextBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewVuelos))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridViewVuelos
            // 
            this->dataGridViewVuelos->BackgroundColor = System::Drawing::SystemColors::InactiveCaption;
            this->dataGridViewVuelos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridViewVuelos->Location = System::Drawing::Point(16, 15);
            this->dataGridViewVuelos->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->dataGridViewVuelos->Name = L"dataGridViewVuelos";
            this->dataGridViewVuelos->RowHeadersWidth = 51;
            this->dataGridViewVuelos->Size = System::Drawing::Size(718, 492);
            this->dataGridViewVuelos->TabIndex = 0;
            // 
            // buttonVerDetalles
            // 
            this->buttonVerDetalles->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonVerDetalles->Location = System::Drawing::Point(16, 514);
            this->buttonVerDetalles->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->buttonVerDetalles->Name = L"buttonVerDetalles";
            this->buttonVerDetalles->Size = System::Drawing::Size(200, 49);
            this->buttonVerDetalles->TabIndex = 1;
            this->buttonVerDetalles->Text = L"Ver Detalles";
            this->buttonVerDetalles->UseVisualStyleBackColor = true;
            this->buttonVerDetalles->Click += gcnew System::EventHandler(this, &DetallesVuelo::buttonVerDetalles_Click);
            // 
            // textBoxDetalles
            // 
            this->textBoxDetalles->BackColor = System::Drawing::SystemColors::InactiveCaption;
            this->textBoxDetalles->Dock = System::Windows::Forms::DockStyle::Right;
            this->textBoxDetalles->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxDetalles->Location = System::Drawing::Point(755, 0);
            this->textBoxDetalles->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->textBoxDetalles->Multiline = true;
            this->textBoxDetalles->Name = L"textBoxDetalles";
            this->textBoxDetalles->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->textBoxDetalles->Size = System::Drawing::Size(290, 690);
            this->textBoxDetalles->TabIndex = 2;
            this->textBoxDetalles->UseSystemPasswordChar = true;
            // 
            // DetallesVuelo
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Desktop;
            this->ClientSize = System::Drawing::Size(1045, 690);
            this->Controls->Add(this->textBoxDetalles);
            this->Controls->Add(this->buttonVerDetalles);
            this->Controls->Add(this->dataGridViewVuelos);
            this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->Name = L"DetallesVuelo";
            this->Text = L"Detalles de Vuelo";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewVuelos))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        void LoadData();
        void buttonVerDetalles_Click(System::Object^ sender, System::EventArgs^ e);
    };
}
