#include <iostream>
#include "Funciones.h"
#include <stdio.h>
using namespace std;

void CargaLoteContenido(Genero _generos[], Contenido _contenidos[])
{
    for(int x = 0 ; x < 15 ; x++)
    {

        CargarCod(_contenidos,x);
        CargarNombre(_contenidos,x);
        CargarTipo(_contenidos,x);
        CargarDuracion(_contenidos,x);
        CargarCalificaionProm(_contenidos,x);
        CargarGeneros(_generos,_contenidos,x);
    }
}
void CargarCod(Contenido _contenidos[], int x)
{


    bool contenidoExiste;
    int opcion;
    int indiceEncontrado;
    do
    {
        contenidoExiste = false;
        cin.ignore();
        system("color 0E");
        Logo(3);
        cout << R"(
            |==========================================================|
            |             Ingrese el Código de Contenido:              |
            |==========================================================|
             Opcion: )";

        cin >> opcion;
        if(opcion <= 99 || opcion >=1000)
        {
            cout << "el Codigo de Contenido Tiene que ser de 3 dígitos" << endl;
            system("color 4");
            system("pause");
        }

        for(int i = 0; i < 15 ; i++)
        {
            if(opcion == _contenidos[i].codContenido)
            {
                contenidoExiste=true;
                indiceEncontrado = i;
            }
        }

        if(contenidoExiste == true)
        {
            cout << "            |==========================================================|" << endl;
            cout << "            | El codigo ingresado ya existia. y pertenece a: " << _contenidos[indiceEncontrado].titulo << endl;
            cout << "            |==========================================================|" << endl;
            system("pause");
        }
        else
        {
            _contenidos[x].codContenido = opcion;
        }

        system("cls");
    }
    while ( (opcion <= 99 || opcion >=1000) || contenidoExiste);


}
void CargarNombre(Contenido _contenidos[], int x)
{
    Logo(2);
    cout << R"(
        |==========================================================|
        |             Ingrese el Nombre del contenido:             |
        |==========================================================|
        Opcion: )";
    cin.ignore();
    getline(cin, _contenidos[x].titulo);
    system("cls");


}

void CargarTipo(Contenido _contenidos[], int x)
{
    do
    {
        Logo(3);
        cout << R"(
            |==========================================================|
            |              Ingrese el Tipo de Contenido:               |
            |==========================================================|
            |    p   | Pelicula                                        |
            |--------|-------------------------------------------------|
            |    s   | Serie                                           |
            |--------|-------------------------------------------------|
            |    d   | Documental                                      |
            |--------|-------------------------------------------------|
              Opcion: )";
        cin >> _contenidos[x].tipo;

        if(_contenidos[x].tipo != 'p' && _contenidos[x].tipo != 's' && _contenidos[x].tipo != 'd' &&
                _contenidos[x].tipo != 'P' && _contenidos[x].tipo != 'S' && _contenidos[x].tipo != 'D' )
        {
            cout << "La opcion seleccionada es invalida." << endl;
            system("color 4");
            system("pause");
        }
        system("cls");
    }
    while(_contenidos[x].tipo != 'p' && _contenidos[x].tipo != 's' && _contenidos[x].tipo != 'd' &&
            _contenidos[x].tipo != 'P' && _contenidos[x].tipo != 'S' && _contenidos[x].tipo != 'D' );


}

void CargarDuracion(Contenido _contenidos[],int x)
{
    Logo(2);
    cout << R"(
        |==========================================================|
        |              Ingrese la Duración (minutos):              |
        |==========================================================|
        Opcion: )";
    cin >> _contenidos[x].duracion;
    system("cls");

}

void CargarCalificaionProm(Contenido _contenidos[],int x)
{
    do
    {
        Logo(3);
        cout << R"(
            |==========================================================|
            |             Ingrese la Calificación promedio:            |
            |==========================================================|
            |            Calificaciones desde el 1.0 al 5.0            |
            |==========================================================|
            Opcion: )";
        cin >> _contenidos[x].califPromedio;

        if(_contenidos[x].califPromedio < 1.0 || _contenidos[x].califPromedio > 5.0)
        {
            cout << "La calificacion promedio es del 1.0 a 5.0" << endl;
            system("color 4");
            system("pause");
        }
        system("cls");
    }
    while(_contenidos[x].califPromedio < 1.0 || _contenidos[x].califPromedio > 5.0);

}

void CargarGeneros(Genero _generos[],Contenido _contenidos[],int x)
{

    bool generoExiste;
    Genero generosDisponibles[8];
    Genero generosDisponiblesAux;
    int contGenerosCargados=0;
    for(int i=0 ; i < 8 ; i++)
    {
        if(_generos[i].nombre != "")
        {
            generosDisponibles[contGenerosCargados].cod = _generos[i].cod;
            generosDisponibles[contGenerosCargados].nombre = _generos[i].nombre;
            contGenerosCargados++;
        }
    }
    for(int i = 0; i < 8 ; i++)
    {
        for(int z = 0 ; z < 8 ; z ++)
        {
            if(_generos[i].cod <  _generos[z].cod)
            {
                generosDisponiblesAux.cod = _generos[i].cod;
                generosDisponiblesAux.nombre = _generos[i].nombre;

                _generos[i].cod = _generos[z].cod ;
                _generos[i].nombre = _generos[z].nombre;

                _generos[z].cod =generosDisponiblesAux.cod ;
                _generos[z].nombre = generosDisponiblesAux.nombre;
            }


        }
    }
    do
    {
        generoExiste = false;
        Logo(3);
        cout << R"(
            |==========================================================|
            |                Ingrese el Código de Género:              |
            |==========================================================|)"<<endl;
        for( int i = 0; i < 8; i++)
        {
            if(generosDisponibles[i].nombre != "")
            {
                cout <<"            |   "<< _generos[i].cod << "   | " << _generos[i].nombre  << endl;
                cout <<"            |----------------------------------------------------------|" << endl;
            }

        }



        int opcion;
        cin.ignore();
        cin >> opcion;
        if(opcion < 1 || opcion > 8)
        {
            cout << "El codigo de genero es del 1 al 8.";
            system("color 4");
            system("pause");
        }
        for( int i = 0 ; i < 8 ; i++ )
        {

            if(_generos[i].cod == opcion)
            {
                _contenidos[x].codGenero = opcion;
                generoExiste=true;
            }
        }

        if(!generoExiste)
        {
            cout << "el genero ingresado no existe. ingrese otro:" << endl;
            system("pause");
        }
        system("cls");
    }
    while((_contenidos[x].codGenero < 1 || _contenidos[x].codGenero > 8) && !generoExiste );
}
