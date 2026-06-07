#include <iostream>
#include "Funciones.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Spanish");

    int cantContenido = 15;
    Contenido contenidos[cantContenido];
    Reproduccion reproducion;

    MenuPrincipal(contenidos,reproducion);
    return 0;
}

