#pragma once

namespace AereopuertoProgra {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient; // Para MySQL

    // Definición de la clase MainFormBoleto que hereda de System::Windows::Forms::Form
    public ref class MainFormBoleto : public System::Windows::Forms::Form {
    public:
        // Constructor de la clase MainFormBoleto
        MainFormBoleto(void) {
            InitializeComponent(); // Inicializa los componentes del formulario
            InitializePlaceholderText(); // Inicializa el texto de marcador de posición en los TextBox
            connectionString = "Server = 127.0.0.1; Database = Aereopuerto_Progra; Uid = Gener; Pwd = Gener2004#;"; // Cadena de conexión a la base de datos
        }

    protected:
        // Destructor de la clase MainFormBoleto
        ~MainFormBoleto() {
            if (components) {
                delete components; // Libera los recursos de los componentes
            }
        }

    private:
        // Declaración de los controles del formulario
        System::Windows::Forms::DataGridView^ dataGridView1; // Control DataGridView para mostrar datos

        // Botón para eliminar fila
        System::String^ connectionString; // Cadena de conexión a la base de datos

        System::Windows::Forms::TextBox^ textBoxNumeroBoleto; // TextBox para el número de boleto
        System::Windows::Forms::TextBox^ textBoxNombrePasajero; // TextBox para el nombre del pasajero
        System::Windows::Forms::TextBox^ textBoxNumeroReserva; // TextBox para el número de reserva

        System::ComponentModel::Container^ components; // Contenedor de componentes

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            System::Windows::Forms::Button^ buttonCreate; // Botón para crear registros
            System::Windows::Forms::Button^ buttonRead; // Botón para leer registros
            System::Windows::Forms::Button^ buttonUpdate; // Botón para actualizar registros
            System::Windows::Forms::Button^ buttonDeleteRow; // Botón para eliminar una fila
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainFormBoleto::typeid));
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->textBoxNumeroBoleto = (gcnew System::Windows::Forms::TextBox());
            this->textBoxNombrePasajero = (gcnew System::Windows::Forms::TextBox());
            this->textBoxNumeroReserva = (gcnew System::Windows::Forms::TextBox());
            buttonCreate = (gcnew System::Windows::Forms::Button());
            buttonRead = (gcnew System::Windows::Forms::Button());
            buttonUpdate = (gcnew System::Windows::Forms::Button());
            buttonDeleteRow = (gcnew System::Windows::Forms::Button());
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
            buttonCreate->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            buttonCreate->Location = System::Drawing::Point(16, 441);
            buttonCreate->Margin = System::Windows::Forms::Padding(4);
            buttonCreate->Name = L"buttonCreate";
            buttonCreate->Size = System::Drawing::Size(100, 28);
            buttonCreate->TabIndex = 1;
            buttonCreate->Text = L"Create";
            buttonCreate->UseVisualStyleBackColor = true;
            buttonCreate->Click += gcnew System::EventHandler(this, &MainFormBoleto::buttonCreate_Click);
            // 
            // buttonRead
            // 
            buttonRead->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            buttonRead->Location = System::Drawing::Point(124, 441);
            buttonRead->Margin = System::Windows::Forms::Padding(4);
            buttonRead->Name = L"buttonRead";
            buttonRead->Size = System::Drawing::Size(100, 28);
            buttonRead->TabIndex = 2;
            buttonRead->Text = L"Read";
            buttonRead->UseVisualStyleBackColor = true;
            buttonRead->Click += gcnew System::EventHandler(this, &MainFormBoleto::buttonRead_Click);
            // 
            // buttonUpdate
            // 
            buttonUpdate->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            buttonUpdate->Location = System::Drawing::Point(232, 441);
            buttonUpdate->Margin = System::Windows::Forms::Padding(4);
            buttonUpdate->Name = L"buttonUpdate";
            buttonUpdate->Size = System::Drawing::Size(100, 28);
            buttonUpdate->TabIndex = 3;
            buttonUpdate->Text = L"Update";
            buttonUpdate->UseVisualStyleBackColor = true;
            buttonUpdate->Click += gcnew System::EventHandler(this, &MainFormBoleto::buttonUpdate_Click);
            // 
            // buttonDeleteRow
            // 
            buttonDeleteRow->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            buttonDeleteRow->Location = System::Drawing::Point(340, 441);
            buttonDeleteRow->Margin = System::Windows::Forms::Padding(4);
            buttonDeleteRow->Name = L"buttonDeleteRow";
            buttonDeleteRow->Size = System::Drawing::Size(100, 28);
            buttonDeleteRow->TabIndex = 4;
            buttonDeleteRow->Text = L"Eliminar fila";
            buttonDeleteRow->UseVisualStyleBackColor = true;
            buttonDeleteRow->Click += gcnew System::EventHandler(this, &MainFormBoleto::buttonDeleteRow_Click);
            // 
            // textBoxNumeroBoleto
            // 
            this->textBoxNumeroBoleto->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxNumeroBoleto->ForeColor = System::Drawing::Color::Gray;
            this->textBoxNumeroBoleto->Location = System::Drawing::Point(16, 394);
            this->textBoxNumeroBoleto->Margin = System::Windows::Forms::Padding(4);
            this->textBoxNumeroBoleto->Name = L"textBoxNumeroBoleto";
            this->textBoxNumeroBoleto->Size = System::Drawing::Size(132, 23);
            this->textBoxNumeroBoleto->TabIndex = 5;
            this->textBoxNumeroBoleto->Text = L"Número Boleto";
            this->textBoxNumeroBoleto->Enter += gcnew System::EventHandler(this, &MainFormBoleto::textBox_Enter);
            this->textBoxNumeroBoleto->Leave += gcnew System::EventHandler(this, &MainFormBoleto::textBox_Leave);
            // 
            // textBoxNombrePasajero
            // 
            this->textBoxNombrePasajero->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxNombrePasajero->ForeColor = System::Drawing::Color::Gray;
            this->textBoxNombrePasajero->Location = System::Drawing::Point(157, 394);
            this->textBoxNombrePasajero->Margin = System::Windows::Forms::Padding(4);
            this->textBoxNombrePasajero->Name = L"textBoxNombrePasajero";
            this->textBoxNombrePasajero->Size = System::Drawing::Size(132, 23);
            this->textBoxNombrePasajero->TabIndex = 6;
            this->textBoxNombrePasajero->Text = L"Nombre Pasajero";
            this->textBoxNombrePasajero->Enter += gcnew System::EventHandler(this, &MainFormBoleto::textBox_Enter);
            this->textBoxNombrePasajero->Leave += gcnew System::EventHandler(this, &MainFormBoleto::textBox_Leave);
            // 
            // textBoxNumeroReserva
            // 
            this->textBoxNumeroReserva->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxNumeroReserva->ForeColor = System::Drawing::Color::Gray;
            this->textBoxNumeroReserva->Location = System::Drawing::Point(299, 394);
            this->textBoxNumeroReserva->Margin = System::Windows::Forms::Padding(4);
            this->textBoxNumeroReserva->Name = L"textBoxNumeroReserva";
            this->textBoxNumeroReserva->Size = System::Drawing::Size(132, 23);
            this->textBoxNumeroReserva->TabIndex = 7;
            this->textBoxNumeroReserva->Text = L"Número Reserva";
            this->textBoxNumeroReserva->Enter += gcnew System::EventHandler(this, &MainFormBoleto::textBox_Enter);
            this->textBoxNumeroReserva->Leave += gcnew System::EventHandler(this, &MainFormBoleto::textBox_Leave);
            // 
            // MainFormBoleto
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Desktop;
            this->ClientSize = System::Drawing::Size(1045, 494);
            this->Controls->Add(this->textBoxNumeroReserva);
            this->Controls->Add(this->textBoxNombrePasajero);
            this->Controls->Add(this->textBoxNumeroBoleto);
            this->Controls->Add(buttonDeleteRow);
            this->Controls->Add(buttonUpdate);
            this->Controls->Add(buttonRead);
            this->Controls->Add(buttonCreate);
            this->Controls->Add(this->dataGridView1);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Margin = System::Windows::Forms::Padding(4);
            this->Name = L"MainFormBoleto";
            this->Text = L"BOLETOS";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        // Métodos para manejar el foco de los TextBox
        void InitializePlaceholderText(); // Declaración del método para inicializar los textos de marcador de posición
        void SetPlaceholder(System::Windows::Forms::TextBox^ textBox, System::String^ placeholderText); // Declaración del método para establecer los textos de marcador de posición
        void textBox_Enter(System::Object^ sender, System::EventArgs^ e); // Evento para manejar la entrada de foco en los TextBox
        void textBox_Leave(System::Object^ sender, System::EventArgs^ e); // Evento para manejar la salida de foco en los TextBox

        // Event handlers for buttons
        void buttonCreate_Click(System::Object^ sender, System::EventArgs^ e); // Evento para manejar el clic del botón Create
        void buttonRead_Click(System::Object^ sender, System::EventArgs^ e); // Evento para manejar el clic del botón Read
        void buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e); // Evento para manejar el clic del botón Update
        void buttonDeleteRow_Click(System::Object^ sender, System::EventArgs^ e); // Evento para manejar el clic del botón Eliminar fila
    };
}
