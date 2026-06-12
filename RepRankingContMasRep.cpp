/*Reporte 1: Ranking de contenidos más reproducidos
Emitir un listado de todos los contenidos ordenado de mayor a menor por cantidad de
reproducciones. El informe debe incluir:
•      Código del contenido.
•      Título del contenido.
•      Tipo (Película, Serie o Documental).
•      Nombre del género.
•      Cantidad de reproducciones totales.
•      Porcentaje de reproducciones completadas sobre el total de reproducciones del contenido. */
#include <iostream>
#include "Funciones.h"

using namespace std;


void RankingContMasRep (
    Genero _generos[],
    Contenido _contenidos[],
    Reproduccion _reproduccion,
    Reporte1ContMasRep _reporte1ContMasRep[],
    int posCodCont
)
{

    _reporte1ContMasRep[posCodCont].codCont = _contenidos[posCodCont].codContenido;
    _reporte1ContMasRep[posCodCont].titulo = _contenidos[posCodCont].titulo;

    for(int i = 0 ; i < 8 ; i++)
    {
        if(_contenidos[posCodCont].codGenero == _generos[i].cod)
        {
            _reporte1ContMasRep[posCodCont].genero = _generos[i].nombre;

        }
    }


    switch(_contenidos[posCodCont].tipo)
    {
    case 'p':
    case 'P':
        _reporte1ContMasRep[posCodCont].tipo = "Película";
        break;
    case 's':
    case 'S':
        _reporte1ContMasRep[posCodCont].tipo = "Serie";
        break;
    case 'd':
    case 'D':
        _reporte1ContMasRep[posCodCont].tipo = "Documental";
        break;
    }


    _reporte1ContMasRep[posCodCont].candRepTotales= _contenidos[posCodCont].CantReproducciones;


    _reporte1ContMasRep[posCodCont].totalComLaRep = _contenidos[posCodCont].totalComLaRep;




}
void OrdenarReporte(Reporte1ContMasRep _reporte1ContMasRep[])
{

    Reporte1ContMasRep reporteAux;
    for(int x = 0; x < 15 ; x++)
    {  _reporte1ContMasRep[x].porcRepComp = (float)_reporte1ContMasRep[x].totalComLaRep / _reporte1ContMasRep[x].candRepTotales * 100.0;
    }
        for(int x = 0; x < 15 ; x++)
    {

        for(int i = 0; i < 14 ; i++)
        {

            if(_reporte1ContMasRep[i].candRepTotales <  _reporte1ContMasRep[i + 1].candRepTotales && x != i)
            {
                reporteAux.codCont = _reporte1ContMasRep[i].codCont;
                reporteAux.titulo = _reporte1ContMasRep[i].titulo;
                reporteAux.tipo = _reporte1ContMasRep[i].tipo;
                reporteAux.genero = _reporte1ContMasRep[i].genero;
                reporteAux.candRepTotales = _reporte1ContMasRep[i].candRepTotales;
                reporteAux.porcRepComp = _reporte1ContMasRep[i].porcRepComp;

                _reporte1ContMasRep[i].codCont = _reporte1ContMasRep[i +1].codCont;
                _reporte1ContMasRep[i].titulo = _reporte1ContMasRep[i + 1].titulo;
                _reporte1ContMasRep[i].tipo = _reporte1ContMasRep[i + 1].tipo;
                _reporte1ContMasRep[i].genero = _reporte1ContMasRep[i + 1].genero;
                _reporte1ContMasRep[i].candRepTotales = _reporte1ContMasRep[i + 1].candRepTotales;
                _reporte1ContMasRep[i].porcRepComp = _reporte1ContMasRep[i + 1].porcRepComp;

                _reporte1ContMasRep[i + 1].codCont = reporteAux.codCont;
                _reporte1ContMasRep[i + 1].titulo = reporteAux.titulo;
                _reporte1ContMasRep[i + 1].tipo = reporteAux.tipo;
                _reporte1ContMasRep[i + 1].genero = reporteAux.genero;
                _reporte1ContMasRep[i + 1].candRepTotales = reporteAux.candRepTotales;
                _reporte1ContMasRep[i + 1].porcRepComp = reporteAux.porcRepComp;

            }
        }

    }

    MostrarReporteContenidoMasReproduciodo(_reporte1ContMasRep);
}
void MostrarReporteContenidoMasReproduciodo(Reporte1ContMasRep _reporte1ContMasRep[])
{
    int i= 1;
    for(int x = 0; x < 15 ; x++)
    {
        if(_reporte1ContMasRep[x].titulo != "")
        {



            cout << "|========================|=================================|"<< endl;
            cout << "|             RANKING N° "<<  i << endl;
            cout << "|========================|=================================|"<< endl;
            cout << "| Opcion                 |         Descripcion             |"<< endl;
            cout << "|========================|=================================|"<< endl;
            cout << "|  Cod. Contenido        | " << _reporte1ContMasRep[x].codCont << endl;
            cout << "|------------------------|---------------------------------|"<< endl;
            cout << "|  Titulo                | "<<_reporte1ContMasRep[x].titulo << endl;
            cout << "|------------------------|---------------------------------|"<< endl;
            cout << "|  Tipo                  | "<<_reporte1ContMasRep[x].tipo << endl;
            cout << "|------------------------|---------------------------------|"<< endl;
            cout << "|  Genero                | "<<_reporte1ContMasRep[x].genero << endl;
            cout << "|------------------------|---------------------------------|"<< endl;
            cout << "|  Cant Reproducciones   | "<<_reporte1ContMasRep[x].candRepTotales << endl;
            cout << "|------------------------|---------------------------------|"<< endl;
            cout << "|  % Reproduccion        | "<< _reporte1ContMasRep[x].porcRepComp<< " % "<< endl;
            cout << "|==========================================================| "<< endl;
            cout << endl;
            cout << endl;

            i++;
        }

    }
    i = 0;
    system("pause");
}
