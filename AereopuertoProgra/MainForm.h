#pragma once

namespace AereopuertoProgra {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient; // Para MySQL

    public ref class MainForm : public System::Windows::Forms::Form {
    public:
        MainForm(void) {
            InitializeComponent(); // Inicializa los componentes del formulario
            InitializePlaceholderText(); // Inicializa el texto de marcador de posición en los TextBox
            connectionString = "Server = 127.0.0.1; Database = Aereopuerto_Progra; Uid = Gener; Pwd = Gener2004#;"; // Cadena de conexión a la base de datos
        }

    protected:
        ~MainForm() {
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

        System::Windows::Forms::TextBox^ textBoxCodigo; // TextBox para el código de la aerolínea
        System::Windows::Forms::TextBox^ textBoxNombre; // TextBox para el nombre de la aerolínea
        System::Windows::Forms::TextBox^ textBoxUbicacion; // TextBox para la ubicación de la aerolínea

        System::ComponentModel::Container^ components; // Contenedor de componentes

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->buttonCreate = (gcnew System::Windows::Forms::Button());
            this->buttonRead = (gcnew System::Windows::Forms::Button());
            this->buttonUpdate = (gcnew System::Windows::Forms::Button());
            this->buttonDeleteRow = (gcnew System::Windows::Forms::Button());
            this->textBoxCodigo = (gcnew System::Windows::Forms::TextBox());
            this->textBoxNombre = (gcnew System::Windows::Forms::TextBox());
            this->textBoxUbicacion = (gcnew System::Windows::Forms::TextBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(16, 16);
            this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->RowHeadersWidth = 51;
            this->dataGridView1->Size = System::Drawing::Size(1013, 392);
            this->dataGridView1->TabIndex = 0;
            // 
            // buttonCreate
            // 
            this->buttonCreate->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonCreate->Location = System::Drawing::Point(16, 469);
            this->buttonCreate->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->buttonCreate->Name = L"buttonCreate";
            this->buttonCreate->Size = System::Drawing::Size(100, 30);
            this->buttonCreate->TabIndex = 1;
            this->buttonCreate->Text = L"Create";
            this->buttonCreate->UseVisualStyleBackColor = true;
            this->buttonCreate->Click += gcnew System::EventHandler(this, &MainForm::buttonCreate_Click);
            // 
            // buttonRead
            // 
            this->buttonRead->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonRead->Location = System::Drawing::Point(124, 469);
            this->buttonRead->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->buttonRead->Name = L"buttonRead";
            this->buttonRead->Size = System::Drawing::Size(100, 30);
            this->buttonRead->TabIndex = 2;
            this->buttonRead->Text = L"Read";
            this->buttonRead->UseVisualStyleBackColor = true;
            this->buttonRead->Click += gcnew System::EventHandler(this, &MainForm::buttonRead_Click);
            // 
            // buttonUpdate
            // 
            this->buttonUpdate->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonUpdate->Location = System::Drawing::Point(232, 469);
            this->buttonUpdate->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->buttonUpdate->Name = L"buttonUpdate";
            this->buttonUpdate->Size = System::Drawing::Size(100, 30);
            this->buttonUpdate->TabIndex = 3;
            this->buttonUpdate->Text = L"Update";
            this->buttonUpdate->UseVisualStyleBackColor = true;
            this->buttonUpdate->Click += gcnew System::EventHandler(this, &MainForm::buttonUpdate_Click);
            // 
            // buttonDeleteRow
            // 
            this->buttonDeleteRow->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonDeleteRow->Location = System::Drawing::Point(340, 469);
            this->buttonDeleteRow->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->buttonDeleteRow->Name = L"buttonDeleteRow";
            this->buttonDeleteRow->Size = System::Drawing::Size(100, 30);
            this->buttonDeleteRow->TabIndex = 4;
            this->buttonDeleteRow->Text = L"Eliminar fila";
            this->buttonDeleteRow->UseVisualStyleBackColor = true;
            this->buttonDeleteRow->Click += gcnew System::EventHandler(this, &MainForm::buttonDeleteRow_Click);
            // 
            // textBoxCodigo
            // 
            this->textBoxCodigo->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxCodigo->ForeColor = System::Drawing::Color::Gray;
            this->textBoxCodigo->Location = System::Drawing::Point(16, 419);
            this->textBoxCodigo->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->textBoxCodigo->Name = L"textBoxCodigo";
            this->textBoxCodigo->Size = System::Drawing::Size(132, 23);
            this->textBoxCodigo->TabIndex = 5;
            this->textBoxCodigo->Text = L"Código Aerolínea";
            this->textBoxCodigo->Enter += gcnew System::EventHandler(this, &MainForm::textBox_Enter);
            this->textBoxCodigo->Leave += gcnew System::EventHandler(this, &MainForm::textBox_Leave);
            // 
            // textBoxNombre
            // 
            this->textBoxNombre->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxNombre->ForeColor = System::Drawing::Color::Gray;
            this->textBoxNombre->Location = System::Drawing::Point(157, 419);
            this->textBoxNombre->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->textBoxNombre->Name = L"textBoxNombre";
            this->textBoxNombre->Size = System::Drawing::Size(132, 23);
            this->textBoxNombre->TabIndex = 6;
            this->textBoxNombre->Text = L"Nombre Aerolínea";
            this->textBoxNombre->Enter += gcnew System::EventHandler(this, &MainForm::textBox_Enter);
            this->textBoxNombre->Leave += gcnew System::EventHandler(this, &MainForm::textBox_Leave);
            // 
            // textBoxUbicacion
            // 
            this->textBoxUbicacion->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBoxUbicacion->ForeColor = System::Drawing::Color::Gray;
            this->textBoxUbicacion->Location = System::Drawing::Point(299, 419);
            this->textBoxUbicacion->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->textBoxUbicacion->Name = L"textBoxUbicacion";
            this->textBoxUbicacion->Size = System::Drawing::Size(132, 23);
            this->textBoxUbicacion->TabIndex = 7;
            this->textBoxUbicacion->Text = L"Ubicación";
            this->textBoxUbicacion->Enter += gcnew System::EventHandler(this, &MainForm::textBox_Enter);
            this->textBoxUbicacion->Leave += gcnew System::EventHandler(this, &MainForm::textBox_Leave);
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Desktop;
            this->ClientSize = System::Drawing::Size(1045, 525);
            this->Controls->Add(this->textBoxUbicacion);
            this->Controls->Add(this->textBoxNombre);
            this->Controls->Add(this->textBoxCodigo);
            this->Controls->Add(this->buttonDeleteRow);
            this->Controls->Add(this->buttonUpdate);
            this->Controls->Add(this->buttonRead);
            this->Controls->Add(this->buttonCreate);
            this->Controls->Add(this->dataGridView1);
            this->Font = (gcnew System::Drawing::Font(L"Century Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->Name = L"MainForm";
            this->Text = L"INSERTAR AEROLINEA";
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
