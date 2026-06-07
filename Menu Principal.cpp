#include <iostream>
#include "Funciones.h"

using namespace std;

//EN ESTE ARCHIVO VAMOS A TENER TODO LO RELACIONADO A LOS MENUS INTERACTIVOS

void MenuPrincipal(Contenido _contenidos[],Reproduccion _reproducion)
{

    int opcion;
    do
    { system("cls");
        cout << "|========|=================================|" << endl;
        cout << "| Opcion |       Bienvenido a UTNFLIX      |" << endl;
        cout << "|========|=================================|" << endl;
        cout << "|    1   | Iniciar                         |" << endl;
        cout << "|--------|---------------------------------|" << endl;
        cout << "|    2   | Creditos                        |" << endl;
        cout << "|--------|---------------------------------|" << endl;
        cout << "|    0   | Salir                           |" << endl;
        cout << "|========|=================================|" << endl;
        cout << "|========|=================================|" << endl;
        cout << "|========|=================================|" << endl;
        cout << "|--------|---------------------------------|" << endl;
        cout << "|    3   | Mostrar Contenido (prueba)      |" << endl;
        cout << "|========|=================================|" << endl;
        cout << "  Opcion: ";
        cin >> opcion;
        system("cls");
        if(opcion >= 1 && opcion <= 3)
        {
            SelecMenuPrincipal(opcion, _contenidos,_reproducion);
        }

    }
    while(opcion != 0);


}
void SelecMenuPrincipal(int opcion, Contenido _contenidos[],Reproduccion _reproducion)
{

    switch(opcion)
    {
    case 1:
        MenuCargaLotes(_contenidos, _reproducion);
        break;
    case 2:
        MostrarCreditos();
        break;
    case 3:
        MostrarContenidoPrueba(_contenidos);
        break;
    }

}
///----------------------------------------------------------------------
///----------------------------------------------------------------------
///----------------------------------------------------------------------
void MostrarCreditos()
{

    int opcion;
    do
    {   cout << "|========|=================================|" << endl;
        cout << "| Legajo |             Creditos            |" << endl;
        cout << "|========|=================================|" << endl;
        cout << "|  34851 | Barrionuevo, Gabriel            |" << endl;
        cout << "|--------|---------------------------------|" << endl;
        cout << "|  24448 | Fernandez, Marcos               |" << endl;
        cout << "|--------|---------------------------------|" << endl;
        cout << "|  35025 | Tejada, Brian                   |" << endl;
        cout << "|========|=================================|" << endl;
        cout << endl;
        cout << endl;
        cout << "|========|=================================|" << endl;
        cout << "|    0   | Atras                           |" << endl;
        cout << "|========|=================================|" << endl;
        cin >> opcion;
        system("cls");
    }
    while(opcion != 0);

}
///----------------------------------------------------------------------
///----------------------------------------------------------------------
///----------------------------------------------------------------------
void MenuCargaLotes(Contenido _contenidos[], Reproduccion _reproducion)
{
    int opcion;
    do
    { system("cls");
        cout << "|========|=================================|" << endl;
        cout << "| Opcion |           Descripcion           |" << endl;
        cout << "|========|=================================|" << endl;
        cout << "|    1   | Cargar lote de generos          |" << endl;
        cout << "|--------|---------------------------------|" << endl;
        cout << "|    2   | Cargar lote de contenidos       |" << endl;
        cout << "|--------|---------------------------------|" << endl;
        cout << "|    3   | Cargar lote de suscriptores     |" << endl;
        cout << "|--------|---------------------------------|" << endl;
        cout << "|    4   | Cargar lote de reproducciones   |" << endl;
        cout << "|--------|---------------------------------|" << endl;
        cout << "|    5   | Mostrar reportes                |" << endl;
        cout << "|--------|---------------------------------|" << endl;
        cout << "|    0   | Atras                           |" << endl;
        cout << "|========|=================================|" << endl;
        cout << "  Opcion: ";
        cin >> opcion;
        system("cls");
        if(opcion >= 1 && opcion <= 5)
        {
            SelecMenuCargaLotes(opcion,_contenidos, _reproducion);
        }

    }
    while(opcion != 0);

}

void SelecMenuCargaLotes(int opcion, Contenido _contenidos[],Reproduccion _reproducion)
{
    switch(opcion)
    {
    case 1: CargaLoteGenero();
        break;
    case 2:CargaLoteContenido(_contenidos);
        break;
    case 3:CargaLoteSuscriptores();
        break;
    case 4: CargaLoteReproducciones(_reproducion,_contenidos);
        break;
    case 5: //va a llamar a los diferentes reportes
        break;
    case 0:
        MenuPrincipal(_contenidos, _reproducion);
        break;
    }


}


