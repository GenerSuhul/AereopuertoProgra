#pragma once

namespace AereopuertoProgra {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class InsertarDatos : public System::Windows::Forms::Form {
    public:
        // Constructor de la clase InsertarDatos
        InsertarDatos(void) {
            InitializeComponent();
        }

    protected:
        // Destructor de la clase InsertarDatos
        ~InsertarDatos() {
            if (components) {
                delete components;
            }
        }

    private:
        // Declaración de los componentes de la interfaz gráfica
        System::Windows::Forms::Button^ buttonAerolineas;
        System::Windows::Forms::Button^ buttonPasajeros;
        System::Windows::Forms::Button^ buttonVuelos;
        System::Windows::Forms::Button^ buttonReservas;
        System::Windows::Forms::Button^ buttonBoletos;
        System::Windows::Forms::Button^ buttonDetallesVuelo;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InsertarDatos::typeid));
            this->buttonAerolineas = (gcnew System::Windows::Forms::Button());
            this->buttonPasajeros = (gcnew System::Windows::Forms::Button());
            this->buttonVuelos = (gcnew System::Windows::Forms::Button());
            this->buttonReservas = (gcnew System::Windows::Forms::Button());
            this->buttonBoletos = (gcnew System::Windows::Forms::Button());
            this->buttonDetallesVuelo = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // buttonAerolineas
            // 
            this->buttonAerolineas->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonAerolineas->Location = System::Drawing::Point(246, 177);
            this->buttonAerolineas->Name = L"buttonAerolineas";
            this->buttonAerolineas->Size = System::Drawing::Size(200, 60);
            this->buttonAerolineas->TabIndex = 0;
            this->buttonAerolineas->Text = L"Aerolíneas";
            this->buttonAerolineas->UseVisualStyleBackColor = true;
            this->buttonAerolineas->Click += gcnew System::EventHandler(this, &InsertarDatos::buttonAerolineas_Click);
            // 
            // buttonPasajeros
            // 
            this->buttonPasajeros->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonPasajeros->Location = System::Drawing::Point(246, 257);
            this->buttonPasajeros->Name = L"buttonPasajeros";
            this->buttonPasajeros->Size = System::Drawing::Size(200, 60);
            this->buttonPasajeros->TabIndex = 1;
            this->buttonPasajeros->Text = L"Pasajeros";
            this->buttonPasajeros->UseVisualStyleBackColor = true;
            this->buttonPasajeros->Click += gcnew System::EventHandler(this, &InsertarDatos::buttonPasajeros_Click);
            // 
            // buttonVuelos
            // 
            this->buttonVuelos->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonVuelos->Location = System::Drawing::Point(246, 337);
            this->buttonVuelos->Name = L"buttonVuelos";
            this->buttonVuelos->Size = System::Drawing::Size(200, 60);
            this->buttonVuelos->TabIndex = 2;
            this->buttonVuelos->Text = L"Vuelos";
            this->buttonVuelos->UseVisualStyleBackColor = true;
            this->buttonVuelos->Click += gcnew System::EventHandler(this, &InsertarDatos::buttonVuelos_Click);
            // 
            // buttonReservas
            // 
            this->buttonReservas->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonReservas->Location = System::Drawing::Point(246, 417);
            this->buttonReservas->Name = L"buttonReservas";
            this->buttonReservas->Size = System::Drawing::Size(200, 60);
            this->buttonReservas->TabIndex = 3;
            this->buttonReservas->Text = L"Reservas";
            this->buttonReservas->UseVisualStyleBackColor = true;
            this->buttonReservas->Click += gcnew System::EventHandler(this, &InsertarDatos::buttonReservas_Click);
            // 
            // buttonBoletos
            // 
            this->buttonBoletos->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonBoletos->Location = System::Drawing::Point(246, 497);
            this->buttonBoletos->Name = L"buttonBoletos";
            this->buttonBoletos->Size = System::Drawing::Size(200, 60);
            this->buttonBoletos->TabIndex = 4;
            this->buttonBoletos->Text = L"Boletos";
            this->buttonBoletos->UseVisualStyleBackColor = true;
            this->buttonBoletos->Click += gcnew System::EventHandler(this, &InsertarDatos::buttonBoletos_Click);
            // 
            // buttonDetallesVuelo
            // 
            this->buttonDetallesVuelo->BackColor = System::Drawing::Color::ForestGreen;
            this->buttonDetallesVuelo->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonDetallesVuelo->ForeColor = System::Drawing::SystemColors::Desktop;
            this->buttonDetallesVuelo->Location = System::Drawing::Point(171, 597);
            this->buttonDetallesVuelo->Name = L"buttonDetallesVuelo";
            this->buttonDetallesVuelo->Size = System::Drawing::Size(365, 56);
            this->buttonDetallesVuelo->TabIndex = 5;
            this->buttonDetallesVuelo->Text = L"Ver Detalles de Vuelo";
            this->buttonDetallesVuelo->UseVisualStyleBackColor = false;
            this->buttonDetallesVuelo->Click += gcnew System::EventHandler(this, &InsertarDatos::buttonDetallesVuelo_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::WhiteSmoke;
            this->label1->Location = System::Drawing::Point(193, 31);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(303, 43);
            this->label1->TabIndex = 6;
            this->label1->Text = L"AEROLINEA UMG ";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->ForeColor = System::Drawing::SystemColors::HighlightText;
            this->label2->Location = System::Drawing::Point(258, 147);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(172, 21);
            this->label2->TabIndex = 7;
            this->label2->Text = L"INGRESA TUS DATOS";
            // 
            // InsertarDatos
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Desktop;
            this->ClientSize = System::Drawing::Size(702, 769);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->buttonDetallesVuelo);
            this->Controls->Add(this->buttonBoletos);
            this->Controls->Add(this->buttonReservas);
            this->Controls->Add(this->buttonVuelos);
            this->Controls->Add(this->buttonPasajeros);
            this->Controls->Add(this->buttonAerolineas);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"InsertarDatos";
            this->Text = L"Insertar Datos";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        // Manejadores de eventos para los botones
        void buttonAerolineas_Click(System::Object^ sender, System::EventArgs^ e);
        void buttonPasajeros_Click(System::Object^ sender, System::EventArgs^ e);
        void buttonVuelos_Click(System::Object^ sender, System::EventArgs^ e);
        void buttonReservas_Click(System::Object^ sender, System::EventArgs^ e);
        void buttonBoletos_Click(System::Object^ sender, System::EventArgs^ e);
        void buttonDetallesVuelo_Click(System::Object^ sender, System::EventArgs^ e);
    };
}
