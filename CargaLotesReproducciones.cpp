#include <iostream>
#include "Funciones.h"
#include <stdio.h>
using namespace std;


void CargaLoteReproducciones(
    Genero _generos[],
    Reproduccion   _reproduccion,
    Contenido      _contenidos[],
    Suscriptor     _suscriptores[],
    Reporte1ContMasRep _reporte1ContMasRep[],
    int            reproduccionesPorPlan[],
    int            totalDeReproducciones
)
{
    // Ciclo principal para cargar el lote.
    // Se repite mientras el usuario no ingrese 0 (la condición de salida).

    int posCodCont;
    do
    {
        system("Color 0A");
        Logo(2);
        cout << R"(
        |==========================================================|
        |              Ingrese el Nro. de Reproducción             |
        |==========================================================|
        Opcion: )";
        cin >> _reproduccion.nroRep;
        system("cls");

        // Validamos que el nro de reproducción sea distinto de 0 para procesar
        if(_reproduccion.nroRep != 0)
        {
            bool suscriptorExiste = false;  // Flag para controlar que exista el suscriptor
            bool conExiste = false;         // Flag para controlar que exista el contenido

            // Ciclo de validación: El programa no saldrá de aquí hasta que
            // el usuario ingrese un código de contenido válido (que exista en el vector)
            do
            {
                Logo(4);
                cout << R"(
                |==========================================================|
                |              Ingrese el Código de Contenido              |
                |==========================================================|
                Opcion: )";
                cin>>_reproduccion.codCont;
                // Recorremos el vector de contenidos para validar la existencia
                for(int x = 0 ; x < 15 ; x++)
                {
                    if(_contenidos[x].codContenido == _reproduccion.codCont)
                    {   posCodCont=x;
                        _contenidos[x].CantReproducciones++;
                        conExiste=true; // Encontramos el contenido
                        cout <<"El condigo de contenido: " << _contenidos[x].codContenido << " fue encontrado" << endl;
                    }
                }
                if(!conExiste)
                {
                    cout << "El condigo de contenido: " << _reproduccion.codCont << " no existe." << endl;
                    system("pause");
                }
                system("cls");
            }
            while(!conExiste); // Mientras no exista, volvemos a pedirlo (ciclo inexacto)

            // Pedimos el resto de los datos
            do
            {
                Logo(4);
                cout << R"(
                |==========================================================|
                |              Ingrese el Código de Suscriptor             |
                |==========================================================|
                Opcion: )";
                cin>>_reproduccion.codSuscriptor;
                // REPORTE 2
                int posicionSuscriptor;
                // Recorremos el vector de suscriptores validar la existencia
                for(int x=0 ; x<12 ; x++)
                {
                    if(_suscriptores[x].codSuscriptor == _reproduccion.codSuscriptor)
                    {
                        suscriptorExiste=true; // Encontramos el contenido
                        // REPORTE 2
                        posicionSuscriptor=x;
                        ProcesarReproduccionPorPlan(_suscriptores[x].plan,reproduccionesPorPlan,totalDeReproducciones);
                    }
                }
                if(suscriptorExiste)
                {
                    cout <<"El condigo de suscriptor: " << _reproduccion.codSuscriptor << " fue encontrado" << endl;
                    /// Reporte 2 ///
                    char plan = _suscriptores[posicionSuscriptor].plan;
                    ProcesarReproduccionPorPlan(plan, reproduccionesPorPlan, totalDeReproducciones);

                    /// Reporte 2 ///
                }
                else
                {
                    cout << "El condigo de contenido: " << _reproduccion.codSuscriptor << " no existe." << endl;
                    system("pause");
                }
                system("cls");
            }
            while(!suscriptorExiste); // Mientras no exista, volvemos a pedirlo (ciclo inexacto)

            do
            {
                Logo (4);
                cout << R"(
                |==========================================================|
                |             Ingrese el Dia de la semana (1-7)            |
                |==========================================================|
                Opcion: )";
                cin >> _reproduccion.diaSemana;

                if(_reproduccion.diaSemana>=1 && _reproduccion.diaSemana<=7)
                {
                    cout << "El dia ingresado es correcto." << endl;
                }
                else
                {
                    cout << "El dia ingresado no es correcto. Ingrese un numero del 1 al 7." << endl;
                }
                system("cls");
            }
            while(_reproduccion.diaSemana<1 || _reproduccion.diaSemana>7);

            do
            {
                Logo(4);
                cout << R"(
                |==========================================================|
                |          ¿Completó la reproducción? (0=No, 1=Si)         |
                |==========================================================|
                Opcion: )";
                cin >> _reproduccion.completoLaReproduccion;

                if(_reproduccion.completoLaReproduccion == 0 || _reproduccion.completoLaReproduccion == 1)
                {
                    cout << "Se cargo la reproduccion." << endl;
                }
                else
                {
                    cout << "El valor ingresado es incorrecto. Ingrese un numero (0-1)" << endl;
                }

                if(_reproduccion.completoLaReproduccion){
                _contenidos[posCodCont].totalComLaRep++;
                }
                //system("pause");
                system("cls");

            }
            while(_reproduccion.completoLaReproduccion != 0 && _reproduccion.completoLaReproduccion != 1);



            /// |=========================================|
            /// |  DESDE ACA LLAMAR A TODOS LOS REPORTES  |
            /// |=========================================|

            RegistrarRankingContMasRep (_generos,_contenidos,_reproduccion,_reporte1ContMasRep,posCodCont);
        }
    }
    while(_reproduccion.nroRep != 0); // Si ingresó 0, cortamos el lote




}


