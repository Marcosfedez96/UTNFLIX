#include <iostream>
#include "Funciones.h"
#include <stdio.h>
using namespace std;

//EN ESTE ARCHIVO VAMOS A CREAR TODAS LAS FUNCIONES QUE SEAN DE CARGA DE LOTES

void CargaLoteGenero(Condiciones &_condiciones,Genero _generos[])
{
    const int CANTGENEROS = 8;
    bool repetido=false;
    int codigo;

    for(int x=0; x<CANTGENEROS; x++)
    {
        //Se pide el ingreso del Código de Género:
        do
        {
            repetido = false;

            system("color 0d");

            cout << "|===========================================|" << endl;
            cout << "|     Ingrese el Código de Género:          |" << endl;
            cout << "|===========================================|" << endl;
            cin >> codigo;
            system("cls");

            //Se valida que el código ingresado no sea 0 ni mayor o menor a los parametros establecidos.
            while(codigo < 1 || codigo > CANTGENEROS)
            {
                cout << "ERROR. El Código ingresado es incorrecto. Por favor, ingrese otro." << endl;
                cout << "|===========================================|" << endl;
                cout << "|     Ingrese el Código de Género:          |" << endl;
                cout << "|===========================================|" << endl;
                cin >> codigo;
                system("cls");
            }

            for(int y=0; y<x; y++)
            {
                if(_generos[y].cod == codigo)
                {
                    repetido=true;
                    system("color 04");
                    cout << "ERROR. Este código ya fue ingresado. Por favor, ingrese otro." << endl;
                }
            }
        }
        while(repetido);

        _generos[x].cod = codigo;

        //Se pide el ingreso del Nombre del Género:
        cin.ignore();
        cout << "|===========================================|" << endl;
        cout << "|     Ingrese el Nombre del Género:         |" << endl;
        cout << "|===========================================|" << endl;
        getline(cin, _generos[x].nombre);
        system("cls");


        //Se valida que se ingrese un Nombre de Género.
        while(_generos[x].nombre == "")
        {
            system("color 0c");
            cout << "Error. Debe ingresar un Nombre de Género. Intente nuevamente." << endl;
            system("color 0d");
            cout << "|===========================================|" << endl;
            cout << "|     Ingrese el Nombre del Género:         |" << endl;
            cout << "|===========================================|" << endl;
            getline(cin, _generos[x].nombre);
            system("cls");
        }

        // Pedimos los 3 días destacados
        system("color 0B");
        cout << "\n|--- CONFIGURACION DE DIAS DESTACADOS (Desafio) ---|" << endl;
        cout << "| Ingrese hasta 3 dias pico (1=Lun ... 7=Dom)      |" << endl;
        cout << "| Ingrese 0 si el genero no tiene dia promocionado |" << endl;
        cout << "|--------------------------------------------------|" << endl;

        for(int i = 0; i < 3; i++) {
            do {
                cout << "  Dia destacado " << i + 1 << ": ";
                cin >> _generos[x].diasDestacados[i];
                if(_generos[x].diasDestacados[i] < 0 || _generos[x].diasDestacados[i] > 7) {
                    cout << "  Error: Ingrese un dia entre 0 y 7." << endl;
                }
            }
            while(_generos[x].diasDestacados[i] < 0 || _generos[x].diasDestacados[i] > 7);
        }
    }
    system("color 0a");
    cout << "Se cargaron todos los datos correctamente!" << endl;
    _condiciones.seCargoGeneros = true;
    cout << "Nos vemos en el Menú de Carga" << endl;
    cout << endl;
    //system("pause");
}
