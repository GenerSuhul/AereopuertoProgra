#include "pch.h"
#include "InsertarDatos.h"
#include "MainForm.h"
#include "MainFormPasajero.h"
#include "MainFormVuelo.h"
#include "MainFormReserva.h"
#include "MainFormBoleto.h"
#include "DetallesVuelo.h"

using namespace AereopuertoProgra;

// Método para manejar el evento Click del botón Aerolíneas
void InsertarDatos::buttonAerolineas_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm^ formAerolineas = gcnew MainForm(); // Crea una nueva instancia de MainForm
    formAerolineas->ShowDialog(); // Muestra el formulario de Aerolíneas
}

// Método para manejar el evento Click del botón Pasajeros
void InsertarDatos::buttonPasajeros_Click(System::Object^ sender, System::EventArgs^ e) {
    MainFormPasajero^ formPasajeros = gcnew MainFormPasajero(); // Crea una nueva instancia de MainFormPasajero
    formPasajeros->ShowDialog(); // Muestra el formulario de Pasajeros
}

// Método para manejar el evento Click del botón Vuelos
void InsertarDatos::buttonVuelos_Click(System::Object^ sender, System::EventArgs^ e) {
    MainFormVuelo^ formVuelos = gcnew MainFormVuelo(); // Crea una nueva instancia de MainFormVuelo
    formVuelos->ShowDialog(); // Muestra el formulario de Vuelos
}

// Método para manejar el evento Click del botón Reservas
void InsertarDatos::buttonReservas_Click(System::Object^ sender, System::EventArgs^ e) {
    MainFormReserva^ formReservas = gcnew MainFormReserva(); // Crea una nueva instancia de MainFormReserva
    formReservas->ShowDialog(); // Muestra el formulario de Reservas
}

// Método para manejar el evento Click del botón Boletos
void InsertarDatos::buttonBoletos_Click(System::Object^ sender, System::EventArgs^ e) {
    MainFormBoleto^ formBoletos = gcnew MainFormBoleto(); // Crea una nueva instancia de MainFormBoleto
    formBoletos->ShowDialog(); // Muestra el formulario de Boletos
}

// Método para manejar el evento Click del botón Ver Detalles de Vuelo
void InsertarDatos::buttonDetallesVuelo_Click(System::Object^ sender, System::EventArgs^ e) {
    DetallesVuelo^ formDetallesVuelo = gcnew DetallesVuelo(); // Crea una nueva instancia de DetallesVuelo
    formDetallesVuelo->ShowDialog(); // Muestra el formulario de Detalles de Vuelo
}
