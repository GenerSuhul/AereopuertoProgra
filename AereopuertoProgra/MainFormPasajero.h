#pragma once

namespace AereopuertoProgra {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient; // Para MySQL

    // Definición de la clase MainFormPasajero que hereda de System::Windows::Forms::Form
    public ref class MainFormPasajero : public System::Windows::Forms::Form {
    public:
        // Constructor de la clase MainFormPasajero
        MainFormPasajero(void) {
            InitializeComponent(); // Inicializa los componentes del formulario
            InitializePlaceholderText(); // Inicializa el texto de marcador de posición en los TextBox
            connectionString = "Server = 127.0.0.1; Database = Aereopuerto_Progra; Uid = Gener; Pwd = Gener2004#;"; // Cadena de conexión a la base de datos
        }

    protected:
        // Destructor de la clase MainFormPasajero
        ~MainFormPasajero() {
            if (components) {
                delete components; // Libera los recursos de los componentes
            }
        }

    private:
        // Declaración de los controles del formulario
        System::Windows::Forms::DataGridView^ dataGridView1; // Control DataGridView para mostrar datos
        System::Windows::Forms::Button^ buttonCreate; // Botón para crear registros
        System::Windows::Forms::Button^ buttonRead; // Botón para leer registros
        System::Windows::Forms::Button^ buttonUpdate; // Botón para actualizar registros
        System::Windows::Forms::Button^ buttonDeleteRow; // Botón para eliminar una fila

        System::String^ connectionString; // Cadena de conexión a la base de datos

        System::Windows::Forms::TextBox^ textBoxNumeroPasajero; // TextBox para el número del pasajero
        System::Windows::Forms::TextBox^ textBoxNombre; // TextBox para el nombre del pasajero
        System::Windows::Forms::TextBox^ textBoxApellido; // TextBox para el apellido del pasajero
        System::Windows::Forms::TextBox^ textBoxEmail; // TextBox para el email del pasajero
        System::Windows::Forms::TextBox^ textBoxTelefono; // TextBox para el teléfono del pasajero

        System::ComponentModel::Container^ components; // Contenedor de componentes

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainFormPasajero::typeid));
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->buttonCreate = (gcnew System::Windows::Forms::Button());
            this->buttonRead = (gcnew System::Windows::Forms::Button());
            this->buttonUpdate = (gcnew System::Windows::Forms::Button());
            this->buttonDeleteRow = (gcnew System::Windows::Forms::Button());
            this->textBoxNumeroPasajero = (gcnew System::Windows::Forms::TextBox());
            this->textBoxNombre = (gcnew System::Windows::Forms::TextBox());
            this->textBoxApellido = (gcnew System::Windows::Forms::TextBox());
            this->textBoxEmail = (gcnew System::Windows::Forms::TextBox());
            this->textBoxTelefono = (gcnew System::Windows::Forms::TextBox());
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
            this->buttonCreate->Click += gcnew System::EventHandler(this, &MainFormPasajero::buttonCreate_Click);
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
            this->buttonRead->Click += gcnew System::EventHandler(this, &MainFormPasajero::buttonRead_Click);
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
            this->buttonUpdate->Click += gcnew System::EventHandler(this, &MainFormPasajero::buttonUpdate_Click);
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
            this->buttonDeleteRow->Click += gcnew System::EventHandler(this, &MainFormPasajero::buttonDeleteRow_Click);
            // 
            // textBoxNumeroPasajero
            // 
            this->textBoxNumeroPasajero->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxNumeroPasajero->ForeColor = System::Drawing::Color::Gray;
            this->textBoxNumeroPasajero->Location = System::Drawing::Point(16, 394);
            this->textBoxNumeroPasajero->Margin = System::Windows::Forms::Padding(4);
            this->textBoxNumeroPasajero->Name = L"textBoxNumeroPasajero";
            this->textBoxNumeroPasajero->Size = System::Drawing::Size(132, 23);
            this->textBoxNumeroPasajero->TabIndex = 5;
            this->textBoxNumeroPasajero->Text = L"Número Pasajero";
            this->textBoxNumeroPasajero->Enter += gcnew System::EventHandler(this, &MainFormPasajero::textBox_Enter);
            this->textBoxNumeroPasajero->Leave += gcnew System::EventHandler(this, &MainFormPasajero::textBox_Leave);
            // 
            // textBoxNombre
            // 
            this->textBoxNombre->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxNombre->ForeColor = System::Drawing::Color::Gray;
            this->textBoxNombre->Location = System::Drawing::Point(157, 394);
            this->textBoxNombre->Margin = System::Windows::Forms::Padding(4);
            this->textBoxNombre->Name = L"textBoxNombre";
            this->textBoxNombre->Size = System::Drawing::Size(132, 23);
            this->textBoxNombre->TabIndex = 6;
            this->textBoxNombre->Text = L"Nombre";
            this->textBoxNombre->Enter += gcnew System::EventHandler(this, &MainFormPasajero::textBox_Enter);
            this->textBoxNombre->Leave += gcnew System::EventHandler(this, &MainFormPasajero::textBox_Leave);
            // 
            // textBoxApellido
            // 
            this->textBoxApellido->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxApellido->ForeColor = System::Drawing::Color::Gray;
            this->textBoxApellido->Location = System::Drawing::Point(299, 394);
            this->textBoxApellido->Margin = System::Windows::Forms::Padding(4);
            this->textBoxApellido->Name = L"textBoxApellido";
            this->textBoxApellido->Size = System::Drawing::Size(132, 23);
            this->textBoxApellido->TabIndex = 7;
            this->textBoxApellido->Text = L"Apellido";
            this->textBoxApellido->Enter += gcnew System::EventHandler(this, &MainFormPasajero::textBox_Enter);
            this->textBoxApellido->Leave += gcnew System::EventHandler(this, &MainFormPasajero::textBox_Leave);
            // 
            // textBoxEmail
            // 
            this->textBoxEmail->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxEmail->ForeColor = System::Drawing::Color::Gray;
            this->textBoxEmail->Location = System::Drawing::Point(440, 394);
            this->textBoxEmail->Margin = System::Windows::Forms::Padding(4);
            this->textBoxEmail->Name = L"textBoxEmail";
            this->textBoxEmail->Size = System::Drawing::Size(132, 23);
            this->textBoxEmail->TabIndex = 8;
            this->textBoxEmail->Text = L"Email";
            this->textBoxEmail->Enter += gcnew System::EventHandler(this, &MainFormPasajero::textBox_Enter);
            this->textBoxEmail->Leave += gcnew System::EventHandler(this, &MainFormPasajero::textBox_Leave);
            // 
            // textBoxTelefono
            // 
            this->textBoxTelefono->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxTelefono->ForeColor = System::Drawing::Color::Gray;
            this->textBoxTelefono->Location = System::Drawing::Point(581, 394);
            this->textBoxTelefono->Margin = System::Windows::Forms::Padding(4);
            this->textBoxTelefono->Name = L"textBoxTelefono";
            this->textBoxTelefono->Size = System::Drawing::Size(132, 23);
            this->textBoxTelefono->TabIndex = 9;
            this->textBoxTelefono->Text = L"Telefono";
            this->textBoxTelefono->Enter += gcnew System::EventHandler(this, &MainFormPasajero::textBox_Enter);
            this->textBoxTelefono->Leave += gcnew System::EventHandler(this, &MainFormPasajero::textBox_Leave);
            // 
            // MainFormPasajero
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Desktop;
            this->ClientSize = System::Drawing::Size(1045, 494);
            this->Controls->Add(this->textBoxTelefono);
            this->Controls->Add(this->textBoxEmail);
            this->Controls->Add(this->textBoxApellido);
            this->Controls->Add(this->textBoxNombre);
            this->Controls->Add(this->textBoxNumeroPasajero);
            this->Controls->Add(this->buttonDeleteRow);
            this->Controls->Add(this->buttonUpdate);
            this->Controls->Add(this->buttonRead);
            this->Controls->Add(this->buttonCreate);
            this->Controls->Add(this->dataGridView1);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Margin = System::Windows::Forms::Padding(4);
            this->Name = L"MainFormPasajero";
            this->Text = L"INSERTAR PASAJERO";
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
