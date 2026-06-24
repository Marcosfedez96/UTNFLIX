/*Reporte 4: Contenidos sin reproducciones
Listar todos los contenidos del catálogo que no registraron ninguna reproducción durante la semana.
Incluir:
•      Código del contenido.
•      Título.
•      Tipo y género.
•      Calificación promedio.*/
#include <iostream>
#include "Funciones.h"
#include <stdio.h>

using namespace std;

void CopiaContenido(Reporte4 _sinReproducciones[], Contenido _contenidos[], Genero _generos[])
{
    int indice=0;
    for (int x=0; x<CANTCONTENIDOS; x++)
    {
        if (_contenidos[x].CantReproducciones == 0)
        {
            _sinReproducciones[indice].codCont = _contenidos[x].codContenido;
            _sinReproducciones[indice].titulo = _contenidos[x].titulo;
            _sinReproducciones[indice].tipoCont = _contenidos[x].tipo;
            AsignarGenero(_generos, _contenidos, _sinReproducciones, indice);
            cout << _sinReproducciones[x].nombGenero;
            _sinReproducciones[indice].calProm = _contenidos[x].califPromedio;

            indice++;
        }
    }
    ContenidoSinReproducciones(_sinReproducciones);

}

void ContenidoSinReproducciones(Reporte4 _sinReproducciones[])
{
    for (int x = 0; x<CANTCONTENIDOS; x++)
    {
        if(_sinReproducciones[x].titulo != ""){

        cout << "|==========================================================|"<< endl;
            cout << "|             CONTENIDO SIN REPRODUCCION  "<< endl;
            cout << "|==========================================================|"<< endl;
            cout << "| Opcion                 |         Descripcion             |"<< endl;
            cout << "|========================|=================================|"<< endl;
            cout << "|  Cod. Contenido        | " << _sinReproducciones[x].codCont << endl;
            cout << "|------------------------|---------------------------------|"<< endl;
            cout << "|  Titulo                | "<<_sinReproducciones[x].titulo << endl;
            cout << "|------------------------|---------------------------------|"<< endl;
            cout << "|  Tipo                  | "<<_sinReproducciones[x].tipoCont << endl;
            cout << "|------------------------|---------------------------------|"<< endl;
            cout << "|  Genero                | "<<_sinReproducciones[x].nombGenero << endl;
            cout << "|------------------------|---------------------------------|"<< endl;
            cout << "|  Calificacion Promedio | "<<_sinReproducciones[x].calProm << endl;
            cout << "|------------------------|---------------------------------|"<< endl;
            cout << endl;
            cout << endl;
        }
    }
    system ("pause");
}

void AsignarGenero(Genero _generos[],Contenido _contenidos[],Reporte4 _sinReproducciones[],int posCodCont)
{
    for(int i = 0 ; i < CANTGENEROS ; i++)
    {
        if(_contenidos[posCodCont].codGenero == _generos[i].cod)
        {
            _sinReproducciones[posCodCont].nombGenero = _generos[i].nombre;

        }
    }
}





