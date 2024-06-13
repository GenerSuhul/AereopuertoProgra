#pragma once

namespace AereopuertoProgra {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient; // Para MySQL

    public ref class MainFormReserva : public System::Windows::Forms::Form {
    public:
        MainFormReserva(void) {
            InitializeComponent();
            InitializePlaceholderText(); // Asegúrate de que este método esté definido
            connectionString = "Server = 127.0.0.1; Database = Aereopuerto_Progra; Uid = Gener; Pwd = Gener2004#;";
        }

    protected:
        ~MainFormReserva() {
            if (components) {
                delete components;
            }
        }

    private:
        System::Windows::Forms::DataGridView^ dataGridView1;
        System::Windows::Forms::Button^ buttonCreate;
        System::Windows::Forms::Button^ buttonRead;
        System::Windows::Forms::Button^ buttonUpdate;
        System::Windows::Forms::Button^ buttonDeleteRow; // Botón para eliminar fila

        System::String^ connectionString; // Variable de conexión

        System::Windows::Forms::TextBox^ textBoxNumeroReserva;
        System::Windows::Forms::TextBox^ textBoxRuta;
        System::Windows::Forms::TextBox^ textBoxFecha;
        System::Windows::Forms::TextBox^ textBoxHoraAbordaje;
        System::Windows::Forms::TextBox^ textBoxHoraSalida;
        System::Windows::Forms::TextBox^ textBoxHoraLlegada;
        System::Windows::Forms::TextBox^ textBoxNumeroVuelo;
        System::Windows::Forms::TextBox^ textBoxAsiento;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainFormReserva::typeid));
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->buttonCreate = (gcnew System::Windows::Forms::Button());
            this->buttonRead = (gcnew System::Windows::Forms::Button());
            this->buttonUpdate = (gcnew System::Windows::Forms::Button());
            this->buttonDeleteRow = (gcnew System::Windows::Forms::Button());
            this->textBoxNumeroReserva = (gcnew System::Windows::Forms::TextBox());
            this->textBoxRuta = (gcnew System::Windows::Forms::TextBox());
            this->textBoxFecha = (gcnew System::Windows::Forms::TextBox());
            this->textBoxHoraAbordaje = (gcnew System::Windows::Forms::TextBox());
            this->textBoxHoraSalida = (gcnew System::Windows::Forms::TextBox());
            this->textBoxHoraLlegada = (gcnew System::Windows::Forms::TextBox());
            this->textBoxNumeroVuelo = (gcnew System::Windows::Forms::TextBox());
            this->textBoxAsiento = (gcnew System::Windows::Forms::TextBox());
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
            this->dataGridView1->Size = System::Drawing::Size(1129, 369);
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
            this->buttonCreate->Click += gcnew System::EventHandler(this, &MainFormReserva::buttonCreate_Click);
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
            this->buttonRead->Click += gcnew System::EventHandler(this, &MainFormReserva::buttonRead_Click);
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
            this->buttonUpdate->Click += gcnew System::EventHandler(this, &MainFormReserva::buttonUpdate_Click);
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
            this->buttonDeleteRow->Click += gcnew System::EventHandler(this, &MainFormReserva::buttonDeleteRow_Click);
            // 
            // textBoxNumeroReserva
            // 
            this->textBoxNumeroReserva->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxNumeroReserva->ForeColor = System::Drawing::Color::Gray;
            this->textBoxNumeroReserva->Location = System::Drawing::Point(16, 394);
            this->textBoxNumeroReserva->Margin = System::Windows::Forms::Padding(4);
            this->textBoxNumeroReserva->Name = L"textBoxNumeroReserva";
            this->textBoxNumeroReserva->Size = System::Drawing::Size(132, 23);
            this->textBoxNumeroReserva->TabIndex = 5;
            this->textBoxNumeroReserva->Text = L"Número Reserva";
            this->textBoxNumeroReserva->Enter += gcnew System::EventHandler(this, &MainFormReserva::textBox_Enter);
            this->textBoxNumeroReserva->Leave += gcnew System::EventHandler(this, &MainFormReserva::textBox_Leave);
            // 
            // textBoxRuta
            // 
            this->textBoxRuta->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxRuta->ForeColor = System::Drawing::Color::Gray;
            this->textBoxRuta->Location = System::Drawing::Point(157, 394);
            this->textBoxRuta->Margin = System::Windows::Forms::Padding(4);
            this->textBoxRuta->Name = L"textBoxRuta";
            this->textBoxRuta->Size = System::Drawing::Size(132, 23);
            this->textBoxRuta->TabIndex = 6;
            this->textBoxRuta->Text = L"Ruta";
            this->textBoxRuta->Enter += gcnew System::EventHandler(this, &MainFormReserva::textBox_Enter);
            this->textBoxRuta->Leave += gcnew System::EventHandler(this, &MainFormReserva::textBox_Leave);
            // 
            // textBoxFecha
            // 
            this->textBoxFecha->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxFecha->ForeColor = System::Drawing::Color::Gray;
            this->textBoxFecha->Location = System::Drawing::Point(299, 394);
            this->textBoxFecha->Margin = System::Windows::Forms::Padding(4);
            this->textBoxFecha->Name = L"textBoxFecha";
            this->textBoxFecha->Size = System::Drawing::Size(132, 23);
            this->textBoxFecha->TabIndex = 7;
            this->textBoxFecha->Text = L"Fecha";
            this->textBoxFecha->Enter += gcnew System::EventHandler(this, &MainFormReserva::textBox_Enter);
            this->textBoxFecha->Leave += gcnew System::EventHandler(this, &MainFormReserva::textBox_Leave);
            // 
            // textBoxHoraAbordaje
            // 
            this->textBoxHoraAbordaje->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxHoraAbordaje->ForeColor = System::Drawing::Color::Gray;
            this->textBoxHoraAbordaje->Location = System::Drawing::Point(440, 394);
            this->textBoxHoraAbordaje->Margin = System::Windows::Forms::Padding(4);
            this->textBoxHoraAbordaje->Name = L"textBoxHoraAbordaje";
            this->textBoxHoraAbordaje->Size = System::Drawing::Size(132, 23);
            this->textBoxHoraAbordaje->TabIndex = 8;
            this->textBoxHoraAbordaje->Text = L"Hora Abordaje";
            this->textBoxHoraAbordaje->Enter += gcnew System::EventHandler(this, &MainFormReserva::textBox_Enter);
            this->textBoxHoraAbordaje->Leave += gcnew System::EventHandler(this, &MainFormReserva::textBox_Leave);
            // 
            // textBoxHoraSalida
            // 
            this->textBoxHoraSalida->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxHoraSalida->ForeColor = System::Drawing::Color::Gray;
            this->textBoxHoraSalida->Location = System::Drawing::Point(581, 394);
            this->textBoxHoraSalida->Margin = System::Windows::Forms::Padding(4);
            this->textBoxHoraSalida->Name = L"textBoxHoraSalida";
            this->textBoxHoraSalida->Size = System::Drawing::Size(132, 23);
            this->textBoxHoraSalida->TabIndex = 9;
            this->textBoxHoraSalida->Text = L"Hora Salida";
            this->textBoxHoraSalida->Enter += gcnew System::EventHandler(this, &MainFormReserva::textBox_Enter);
            this->textBoxHoraSalida->Leave += gcnew System::EventHandler(this, &MainFormReserva::textBox_Leave);
            // 
            // textBoxHoraLlegada
            // 
            this->textBoxHoraLlegada->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxHoraLlegada->ForeColor = System::Drawing::Color::Gray;
            this->textBoxHoraLlegada->Location = System::Drawing::Point(722, 394);
            this->textBoxHoraLlegada->Margin = System::Windows::Forms::Padding(4);
            this->textBoxHoraLlegada->Name = L"textBoxHoraLlegada";
            this->textBoxHoraLlegada->Size = System::Drawing::Size(132, 23);
            this->textBoxHoraLlegada->TabIndex = 10;
            this->textBoxHoraLlegada->Text = L"Hora Llegada";
            this->textBoxHoraLlegada->Enter += gcnew System::EventHandler(this, &MainFormReserva::textBox_Enter);
            this->textBoxHoraLlegada->Leave += gcnew System::EventHandler(this, &MainFormReserva::textBox_Leave);
            // 
            // textBoxNumeroVuelo
            // 
            this->textBoxNumeroVuelo->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxNumeroVuelo->ForeColor = System::Drawing::Color::Gray;
            this->textBoxNumeroVuelo->Location = System::Drawing::Point(863, 394);
            this->textBoxNumeroVuelo->Margin = System::Windows::Forms::Padding(4);
            this->textBoxNumeroVuelo->Name = L"textBoxNumeroVuelo";
            this->textBoxNumeroVuelo->Size = System::Drawing::Size(132, 23);
            this->textBoxNumeroVuelo->TabIndex = 11;
            this->textBoxNumeroVuelo->Text = L"Número Vuelo";
            this->textBoxNumeroVuelo->Enter += gcnew System::EventHandler(this, &MainFormReserva::textBox_Enter);
            this->textBoxNumeroVuelo->Leave += gcnew System::EventHandler(this, &MainFormReserva::textBox_Leave);
            // 
            // textBoxAsiento
            // 
            this->textBoxAsiento->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxAsiento->ForeColor = System::Drawing::Color::Gray;
            this->textBoxAsiento->Location = System::Drawing::Point(1004, 394);
            this->textBoxAsiento->Margin = System::Windows::Forms::Padding(4);
            this->textBoxAsiento->Name = L"textBoxAsiento";
            this->textBoxAsiento->Size = System::Drawing::Size(132, 23);
            this->textBoxAsiento->TabIndex = 12;
            this->textBoxAsiento->Text = L"Asiento";
            this->textBoxAsiento->Enter += gcnew System::EventHandler(this, &MainFormReserva::textBox_Enter);
            this->textBoxAsiento->Leave += gcnew System::EventHandler(this, &MainFormReserva::textBox_Leave);
            // 
            // MainFormReserva
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Desktop;
            this->ClientSize = System::Drawing::Size(1161, 494);
            this->Controls->Add(this->textBoxAsiento);
            this->Controls->Add(this->textBoxNumeroVuelo);
            this->Controls->Add(this->textBoxHoraLlegada);
            this->Controls->Add(this->textBoxHoraSalida);
            this->Controls->Add(this->textBoxHoraAbordaje);
            this->Controls->Add(this->textBoxFecha);
            this->Controls->Add(this->textBoxRuta);
            this->Controls->Add(this->textBoxNumeroReserva);
            this->Controls->Add(this->buttonDeleteRow);
            this->Controls->Add(this->buttonUpdate);
            this->Controls->Add(this->buttonRead);
            this->Controls->Add(this->buttonCreate);
            this->Controls->Add(this->dataGridView1);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Margin = System::Windows::Forms::Padding(4);
            this->Name = L"MainFormReserva";
            this->Text = L"RESERVACIONES";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        // Métodos para manejar el foco de los TextBox
        void InitializePlaceholderText(); // Declaración del método
        void SetPlaceholder(System::Windows::Forms::TextBox^ textBox, System::String^ placeholderText); // Declaración del método
        void textBox_Enter(System::Object^ sender, System::EventArgs^ e);
        void textBox_Leave(System::Object^ sender, System::EventArgs^ e);

        // Event handlers for buttons
        void buttonCreate_Click(System::Object^ sender, System::EventArgs^ e);
        void buttonRead_Click(System::Object^ sender, System::EventArgs^ e);
        void buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e);
        void buttonDeleteRow_Click(System::Object^ sender, System::EventArgs^ e); // Declaración del nuevo método
    };
}
