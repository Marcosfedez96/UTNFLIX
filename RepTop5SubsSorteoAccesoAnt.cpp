/*Reporte 5: Top 5 suscriptores + sorteo de acceso anticipado
UTNFlix desea premiar a sus suscriptores más activos de la semana. La funcionalidad debe:
•      Calcular el top 5 de suscriptores con mayor cantidad de reproducciones realizadas en la
semana.
•      Mostrar el listado del top 5 con: código de suscriptor, nombre completo, plan y cantidad de
reproducciones.
•      Elegir aleatoriamente 2 suscriptores del top 5 y otorgarles acceso anticipado a estrenos de
la próxima semana.
•      Mostrar los 2 ganadores con su nombre y cantidad de reproducciones. */
#include <iostream>
#include "Funciones.h"
#include <ctime>
#include <cstdlib>

using namespace std;


void TopFiveSub(Suscriptor _suscriptores[])
{
    system("color 03");

    int ganadores[2];

    Suscriptor suscriptoresTop[CANTSUSCRIPTORES];

    AsignarVector(suscriptoresTop, _suscriptores);

    OrdenarVector (suscriptoresTop);

    MostrarTopFive(suscriptoresTop);

    SorteoAccesoAnticipado(suscriptoresTop, ganadores);

    MostrarGanadores(suscriptoresTop, ganadores);
}

void AsignarVector(Suscriptor _suscriptoresTop[],Suscriptor _suscriptores[])
{
    for(int x= 0; x < CANTSUSCRIPTORES; x++)
    {
        _suscriptoresTop[x].canRepSub = _suscriptores[x].canRepSub;
        _suscriptoresTop[x].codSuscriptor = _suscriptores[x].codSuscriptor;
        _suscriptoresTop[x].nombreYApellido = _suscriptores[x].nombreYApellido;
        _suscriptoresTop[x].pantallas = _suscriptores[x].pantallas;
        _suscriptoresTop[x].plan = _suscriptores[x].plan;
    }

}
void OrdenarVector (Suscriptor _suscriptoresTop[])
{

    Suscriptor suscriptorAUX;
    for(int x = 0 ; x < CANTSUSCRIPTORES; x++)
    {
        for(int i = 0 ; i < CANTSUSCRIPTORES - 1 ; i++)
        {
            if(_suscriptoresTop[i].canRepSub < _suscriptoresTop[i+1].canRepSub)
            {
                suscriptorAUX.canRepSub = _suscriptoresTop[i].canRepSub;
                suscriptorAUX.codSuscriptor = _suscriptoresTop[i].codSuscriptor;
                suscriptorAUX.nombreYApellido = _suscriptoresTop[i].nombreYApellido;
                suscriptorAUX.pantallas = _suscriptoresTop[i].pantallas;
                suscriptorAUX.plan = _suscriptoresTop[i].plan;

                _suscriptoresTop[i].canRepSub = _suscriptoresTop[i + 1].canRepSub;
                _suscriptoresTop[i].codSuscriptor = _suscriptoresTop[i + 1].codSuscriptor;
                _suscriptoresTop[i].nombreYApellido = _suscriptoresTop[i + 1].nombreYApellido;
                _suscriptoresTop[i].pantallas = _suscriptoresTop[i + 1].pantallas;
                _suscriptoresTop[i].plan = _suscriptoresTop[i + 1].plan;

                _suscriptoresTop[i + 1].canRepSub = suscriptorAUX.canRepSub;
                _suscriptoresTop[i + 1].codSuscriptor = suscriptorAUX.codSuscriptor;
                _suscriptoresTop[i + 1].nombreYApellido = suscriptorAUX.nombreYApellido;
                _suscriptoresTop[i + 1].pantallas = suscriptorAUX.pantallas;
                _suscriptoresTop[i + 1].plan = suscriptorAUX.plan;
            }

        }
    }
}
void MostrarTopFive(Suscriptor suscriptoresTop[])
{


    int i = 1;
    for(int x=0; x < 5; x++)
    {

        cout << "|==========================================================|"<< endl;
        cout << "|        Suscriptores mas Activos Top N° "<<  i << endl;
        cout << "|==========================================================|"<< endl;
        cout << "|  Cod. Suscriptor       | " << suscriptoresTop[x].codSuscriptor << endl;
        cout << "|------------------------|---------------------------------|"<< endl;
        cout << "|  Apellido y Nombre     | " << suscriptoresTop[x].nombreYApellido << endl;
        cout << "|------------------------|---------------------------------|"<< endl;
        cout << "|  Plan                  | " << suscriptoresTop[x].plan << endl;
        cout << "|------------------------|---------------------------------|"<< endl;
        cout << "|  Cant. Reproducciones  | " << suscriptoresTop[x].canRepSub << endl;
        cout << "|==========================================================| "<< endl;
        cout << endl;

        i++;

    }


}

void SorteoAccesoAnticipado(Suscriptor suscriptoresTop[], int _ganadores[])
{

    _ganadores[0] = rand() % 5;
    _ganadores[1] = rand() % 5;

    bool seRepitioGanador = false;
    if(_ganadores[1] == _ganadores[0])
    {
        seRepitioGanador = true;
    }

    while(seRepitioGanador)
    {
        _ganadores[1] = rand() % 5;
        if(_ganadores[1] != _ganadores[0])
        {
            seRepitioGanador = false;
        }
    }

}
void MostrarGanadores(Suscriptor suscriptoresTop[], int _ganadores[])
{

    cout << "####################################################################################################################" << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
    cout << "####################################################################################################################" << endl;
    int cantGanadores = 2;
    int i = 1;
    for(int x = 0 ; x < cantGanadores ; x ++)
    {

        cout << "|==========================================================|"<< endl;
        cout << "|        Ganador del Sorteo N° "<<  i << endl;
        cout << "|==========================================================|"<< endl;
        cout << "|  Apellido y Nombre     | " << suscriptoresTop[_ganadores[x]].nombreYApellido << endl;
        cout << "|------------------------|---------------------------------|"<< endl;
        cout << "|  Cant. Reproducciones  | " << suscriptoresTop[_ganadores[x]].canRepSub << endl;
        cout << "|==========================================================| "<< endl;

        i++;
    }

    system("Pause");

}
