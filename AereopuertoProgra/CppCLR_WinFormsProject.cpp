#include "pch.h"
#include "InsertarDatos.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Cambia "CppCLRWinFormsProject" por el nombre de tu proyecto/nombre de espacio
    AereopuertoProgra::InsertarDatos form;
    Application::Run(% form);
    return 0;
}
