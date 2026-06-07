#include <iostream>
#include "Funciones.h"
#include <stdio.h>
using namespace std;

//EN ESTE ARCHIVO VAMOS A CREAR TODAS LAS FUNCIONES QUE SEAN DE CARGA DE LOTES


void CargaLoteGenero()
{

}

void CargaLoteSuscriptores()
{

}

void CargaLoteContenido(Contenido _contenidos[])
{
    for(int x = 0 ; x < 15 ; x++)
    {
        do
        {
            cin.ignore();
            system("color 07");
            cout << "|==========================================|" << endl;
            cout << "|     Ingrese el Código de Contenido:      |" << endl;
            cout << "|==========================================|" << endl;
            cin >> _contenidos[x].codContenido;
            if(_contenidos[x].codContenido <= 99 || _contenidos[x].codContenido >=1000)
            {
                cout << "el Codigo de Contenido Tiene que ser de 3 dígitos" << endl;
                system("color 4");
                system("pause");
            }
            system("cls");
        }
        while ( _contenidos[x].codContenido <= 99 || _contenidos[x].codContenido >=1000);

        cout << "|==========================================|" << endl;
        cout << "|     Ingrese el Nombre del contenido:     |" << endl;
        cout << "|==========================================|" << endl;
        cin.ignore();
        getline(cin, _contenidos[x].titulo);
        system("cls");

        do
        {
            system("color 07");
            cout << "|==========================================|" << endl;
            cout << "|      Ingrese el Tipo de Contenido:       |" << endl;
            cout << "|==========================================|" << endl;
            cout << "| Opcion |           Descripcion           |" << endl;
            cout << "|========|=================================|" << endl;
            cout << "|    p   | Peliculas                       |" << endl;
            cout << "|--------|---------------------------------|" << endl;
            cout << "|    s   | Serie                           |" << endl;
            cout << "|--------|---------------------------------|" << endl;
            cout << "|    d   | Documental                      |" << endl;
            cout << "|------------------------------------------|" << endl;
            cin >> _contenidos[x].tipo;

            if(_contenidos[x].tipo != 'p' && _contenidos[x].tipo != 's' && _contenidos[x].tipo != 'd' )
            {
                cout << "La opcion seleccionada es invalida." << endl;
                system("color 4");
                system("pause");
            }
            system("cls");
        }
        while(_contenidos[x].tipo != 'p' && _contenidos[x].tipo != 's' && _contenidos[x].tipo != 'd' );

        cout << "|==========================================|" << endl;
        cout << "|      Ingrese la Duración (minutos):      |" << endl;
        cout << "|==========================================|" << endl;
        cin >> _contenidos[x].duracion;
        system("cls");

        do
        {
            system("color 07");
            cout << "|==========================================|" << endl;
            cout << "|     Ingrese la Calificación promedio:    |" << endl;
            cout << "|==========================================|" << endl;
            cout << "|    Calificaciones desde el 1.0 al 5.0    |" << endl;
            cout << "|==========================================|" << endl;
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

        do
        {
            system("color 07");
            cout << "|==========================================|" << endl;
            cout << "|        Ingrese el Código de Género:      |" << endl;
            cout << "|==========================================|" << endl;
            cout << "| Opcion |           Descripcion           |" << endl;
            cout << "|========|=================================|" << endl;
            cout << "|    1   | Acción                          |" << endl;
            cout << "|--------|---------------------------------|" << endl;
            cout << "|    2   | Drama                           |" << endl;
            cout << "|--------|---------------------------------|" << endl;
            cout << "|    3   | Comedia                         |" << endl;
            cout << "|--------|---------------------------------|" << endl;
            cout << "|    4   | Terror                          |" << endl;
            cout << "|--------|---------------------------------|" << endl;
            cout << "|    5   | Documental                      |" << endl;
            cout << "|--------|---------------------------------|" << endl;
            cout << "|    6   | Animación                       |" << endl;
            cout << "|--------|---------------------------------|" << endl;
            cout << "|    7   | Ciencia Ficción                 |" << endl;
            cout << "|--------|---------------------------------|" << endl;
            cout << "|    8   | Romance                         |" << endl;
            cout << "|------------------------------------------|" << endl;
            cin.ignore();
            cin >> _contenidos[x].codGenero;
            if(_contenidos[x].codGenero < 1 || _contenidos[x].codGenero > 8)
            {
                cout << "El codigo de genero es de 1 al 8.";
                system("color 4");
                system("pause");
            }

            system("cls");
        }
        while(_contenidos[x].codGenero < 1 || _contenidos[x].codGenero > 8);

    }


}

void MostrarContenidoPrueba(Contenido _contenidos[])
{

    for(int x = 0; x < 15; x++)
    {
        system("color 02");
        cout << "|================================================|" << endl;
        cout << "|        Contenido N° : "<< x + 1  << endl;
        cout << "|================================================|" << endl;
        cout << "| que es?      |           Contenido             |" << endl;
        cout << "|==============|=================================|" << endl;
        cout << "|cod. Contenido| "<<_contenidos[x].codContenido << endl;
        cout << "|--------------|---------------------------------|" << endl;
        cout << "|titulo        |"<<_contenidos[x].titulo  << endl;
        cout << "|--------------|---------------------------------|" << endl;
        cout << "|cod. Genero   | "<<_contenidos[x].codGenero  << endl;
        cout << "|--------------|---------------------------------|" << endl;
        cout << "|duracion      | "<<_contenidos[x].duracion << endl;
        cout << "|--------------|---------------------------------|" << endl;
        cout << "|tipo          | "<<_contenidos[x].tipo  << endl;
        cout << "|--------------|---------------------------------|" << endl;
        cout << "|calif. Prom.  | "<<_contenidos[x].califPromedio << endl;
        cout << "|------------------------------------------------|" << endl;
        system("pause");
        system("color 07");

    }

}


void CargaLoteReproducciones(Reproduccion _reproducion, Contenido _contenidos[])
{

    do
    {
        cout << "|==========================================|" << endl;
        cout << "|      Ingrese el Nro. de Reproducción     |" << endl;
        cout << "|==========================================|" << endl;
        cin >> _reproducion.nroRep;

        if(_reproducion.nroRep != 0)
        {

            bool conExiste = false;
            do
            {
                cout << "|==========================================|" << endl;
                cout << "|      Ingrese el Código de Contenido      |" << endl;
                cout << "|==========================================|" << endl;

                cin>>_reproducion.codCont;
                for(int x = 0 ; x < 15 ; x++)
                {
                    if(_contenidos[x].codContenido == _reproducion.codCont)
                    {
                        conExiste=true;
                        cout <<"El condigo de contenido: " << _contenidos[x].codContenido << " fue encontrado" << endl;
                    }
                }
                if(!conExiste)
                {
                    cout << "El condigo de contenido: " << _reproducion.codCont << " no existe." << endl;
                }
            }
            while(!conExiste);



            cout << "|==========================================|" << endl;
            cout << "|     Ingrese el Código de Suscriptor      |" << endl;
            cout << "|==========================================|" << endl;
            cin>>_reproducion.codSuscriptor;

            cout << "|==========================================|" << endl;
            cout << "|       Ingrese el Dia de la semana        |" << endl;
            cout << "|==========================================|" << endl;
            cin >> _reproducion.diaSemana;

            cout << "|==========================================|" << endl;
            cout << "|        ¿Completó la reproducción?        |" << endl;
            cout << "|==========================================|" << endl;
            cin >> _reproducion.completoLaReproduccion;



            ///DESDE ACA LLAMA A TODOS LOS REPORTES.
        }


    }
    while(_reproducion.nroRep != 0);




}
