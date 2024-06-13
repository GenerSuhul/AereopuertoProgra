#include "pch.h"
#include "InsertarDatos.h"
#include "MainForm.h"
#include "MainFormPasajero.h"
#include "MainFormVuelo.h"
#include "MainFormReserva.h"
#include "MainFormBoleto.h"
#include "DetallesVuelo.h"

using namespace AereopuertoProgra;

void InsertarDatos::buttonAerolineas_Click(System::Object^ sender, System::EventArgs^ e) {
    MainForm^ formAerolineas = gcnew MainForm();
    formAerolineas->ShowDialog();
}

void InsertarDatos::buttonPasajeros_Click(System::Object^ sender, System::EventArgs^ e) {
    MainFormPasajero^ formPasajeros = gcnew MainFormPasajero();
    formPasajeros->ShowDialog();
}

void InsertarDatos::buttonVuelos_Click(System::Object^ sender, System::EventArgs^ e) {
    MainFormVuelo^ formVuelos = gcnew MainFormVuelo();
    formVuelos->ShowDialog();
}

void InsertarDatos::buttonReservas_Click(System::Object^ sender, System::EventArgs^ e) {
    MainFormReserva^ formReservas = gcnew MainFormReserva();
    formReservas->ShowDialog();
}

void InsertarDatos::buttonBoletos_Click(System::Object^ sender, System::EventArgs^ e) {
    MainFormBoleto^ formBoletos = gcnew MainFormBoleto();
    formBoletos->ShowDialog();
}

void InsertarDatos::buttonDetallesVuelo_Click(System::Object^ sender, System::EventArgs^ e) {
    DetallesVuelo^ formDetallesVuelo = gcnew DetallesVuelo();
    formDetallesVuelo->ShowDialog();
}
