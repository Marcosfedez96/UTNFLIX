#include <iostream>
#include "Funciones.h"

using namespace std;

//EN ESTE ARCHIVO VAMOS A TENER TODO LO RELACIONADO A LOS MENUS INTERACTIVOS

void MenuPrincipal(Genero _generos[],Contenido _contenidos[],Reproduccion _reproduccion, Suscriptor _suscriptores[],Reporte1ContMasRep _reporte1ContMasRep[],int reproduccionesPorPlan[],int totalDeReproducciones)
{

    int opcion;
    do
    {
        system("color 0C");
        system("cls");
        Logo(2);
        cout << R"(
        |========|=================================================|
        | Opcion |              Bienvenido a UTNFLIX               |
        |========|=================================================|
        |    1   | Iniciar                                         |
        |--------|-------------------------------------------------|
        |    2   | Creditos                                        |
        |--------|-------------------------------------------------|
        |    0   | Salir                                           |
        |========|=================================================|
          Opcion: )";
        cin >> opcion;
        system("color 0F");
        system("cls");
        if(opcion >= 1 && opcion <= 3)
        {
            SelecMenuPrincipal(opcion,_generos, _contenidos,_reproduccion, _suscriptores,_reporte1ContMasRep,reproduccionesPorPlan, totalDeReproducciones);
        }

    }
    while(opcion != 0);

}
void SelecMenuPrincipal(int opcion,Genero _generos[], Contenido _contenidos[],Reproduccion _reproduccion, Suscriptor _suscriptores[],Reporte1ContMasRep _reporte1ContMasRep[],int reproduccionesPorPlan[], int totalDeReproducciones)
{

    switch(opcion)
    {
    case 1:
        MenuCargaLotes(_generos,_contenidos, _reproduccion, _suscriptores,_reporte1ContMasRep, reproduccionesPorPlan, totalDeReproducciones);
        break;
    case 2:
        MostrarCreditos();
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
    {
        system("color 0C");         // Color rojo UTNFlix
        system("cls");      // Limpiar pantalla para aplicar el color
        Logo(2);
        cout << R"(
        |========|=================================================|
        | Legajo |                     Creditos                    |
        |========|=================================================|
        |  34851 | Barrionuevo, Gabriel                            |
        |--------|-------------------------------------------------|
        |  24448 | Fernandez, Marcos                               |
        |--------|-------------------------------------------------|
        |  35025 | Tejada, Brian                                   |
        |========|=================================================|


        |========|=================================================|
        |    0   | Atras                                           |
        |========|=================================================|
          Opcion: )";

        cin >> opcion;

        system("color 0F"); // Volver al blanco y negro clásico
        system("cls");      // Limpiar la pantalla para el próximo menú
    }
    while(opcion != 0);

}
///----------------------------------------------------------------------
///----------------------------------------------------------------------
///----------------------------------------------------------------------
void MenuCargaLotes(
    Genero _generos[],
    Contenido _contenidos[],
    Reproduccion _reproduccion,
    Suscriptor _suscriptores[],
    Reporte1ContMasRep _reporte1ContMasRep[],
    int reproduccionesPorPlan[],
    int totalDeReproducciones)
{
    int opcion;
    do
    {
        system("color 0C"); // Color rojo UTNFlix
        system("cls");      // Limpiamos pantalla

        Logo(2);
        cout << R"(
        |========|=================================================|
        | Opcion |           Descripcion                           |
        |========|=================================================|
        |    1   | Cargar lote de generos                          |
        |--------|-------------------------------------------------|
        |    2   | Cargar lote de contenidos                       |
        |--------|-------------------------------------------------|
        |    3   | Cargar lote de suscriptores                     |
        |--------|-------------------------------------------------|
        |    4   | Cargar lote de reproducciones                   |
        |--------|-------------------------------------------------|
        |    5   | Mostrar reportes                                |
        |--------|-------------------------------------------------|
        |    0   | Atras                                           |
        |========|=================================================|
          Opcion: )";
        cin >> opcion;
        system("cls"); // Limpiamos nuevamente al procesar la opción

        if(opcion >= 1 && opcion <= 5)
        {
            SelecMenuCargaLotes(
                opcion,
                _generos,
                _contenidos,
                _reproduccion,
                _suscriptores,
                _reporte1ContMasRep,
                reproduccionesPorPlan,
                totalDeReproducciones
            );
        }

    }
    while(opcion != 0);

}

void SelecMenuCargaLotes(
    int opcion,
    Genero _generos[],
    Contenido _contenidos[],
    Reproduccion _reproduccion,
    Suscriptor _suscriptores[],
    Reporte1ContMasRep _reporte1ContMasRep[],
    int reproduccionesPorPlan[],
    int totalDeReproducciones
)
{
    switch(opcion)
    {
    case 1:
        CargaLoteGenero(_generos);
        break;
    case 2:
        CargaLoteContenido(_generos,_contenidos);
        break;
    case 3:
        CargaLoteSuscriptores(_suscriptores);
        break;
    case 4:
        CargaLoteReproducciones(_generos,_reproduccion,_contenidos, _suscriptores,_reporte1ContMasRep, reproduccionesPorPlan, totalDeReproducciones);
        break;
    case 5:
        MenuReportes(
            _generos,
            _contenidos,
            _reproduccion,
            _suscriptores,
            _reporte1ContMasRep,
            reproduccionesPorPlan,
            totalDeReproducciones);
        break;
    case 0:
        MenuPrincipal(_generos,_contenidos, _reproduccion, _suscriptores,_reporte1ContMasRep,reproduccionesPorPlan, totalDeReproducciones);
        break;
    }


}

void MenuReportes(
    Genero _generos[],
    Contenido _contenidos[],
    Reproduccion _reproduccion,
    Suscriptor _suscriptores[],
    Reporte1ContMasRep _reporte1ContMasRep[],
    int reproduccionesPorPlan[],
    int totalDeReproducciones)
{
    int opcion;
    do
    {
        system("color 0C"); // Color rojo UTNFlix
        system("cls");      // Limpiamos pantalla

        Logo(2);
        cout << R"(
        |========|=================================================|
        | Opcion |           Descripcion                           |
        |========|=================================================|
        |    1   |Ranking de contenidos más reproducidos           |
        |--------|-------------------------------------------------|
        |    2   |Actividad por plan de suscripción                |
        |--------|-------------------------------------------------|
        |    3   |Reproducciones por género y día de la semana     |
        |--------|-------------------------------------------------|
        |    4   |Contenidos sin reproducciones                    |
        |--------|-------------------------------------------------|
        |    5   |Top 5 suscriptores + sorteo de acceso anticipado |
        |--------|-------------------------------------------------|
        |    0   | Volver al menú principal                        |
        |========|=================================================|
          Opcion: )";
        cin >> opcion;
        system("cls"); // Limpiamos nuevamente al procesar la opción

        if(opcion >= 1 && opcion <= 5)
        {
            SelecMenuReportes(
                opcion,
                _generos,
                _contenidos,
                _reproduccion,
                _suscriptores,
                _reporte1ContMasRep,
                reproduccionesPorPlan,
                totalDeReproducciones
            );
        }

    }
    while(opcion != 0);

}

void SelecMenuReportes(
    int opcion,
    Genero _generos[],
    Contenido _contenidos[],
    Reproduccion _reproduccion,
    Suscriptor _suscriptores[],
    Reporte1ContMasRep _reporte1ContMasRep[],
    int reproduccionesPorPlan[],
    int totalDeReproducciones
)
{
    switch(opcion)
    {
    case 1:
        RegistrarTodosLosContenidos(_generos,_contenidos,_reporte1ContMasRep);
        break;
    case 2:
        MostrarReportePlanDeSuscripcion(reproduccionesPorPlan, totalDeReproducciones);
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 0:
        MenuCargaLotes(_generos,_contenidos, _reproduccion, _suscriptores,_reporte1ContMasRep,reproduccionesPorPlan, totalDeReproducciones);
        break;
    }


}

void Logo(int numTABULACIONES)
{
    switch(numTABULACIONES)
    {
    case 2:
        cout << R"(
        |==========================================================|
        |                                                          |
        |            | | | |_   _| \ | |  ___| (_)                 |
        |            | | | | | | |  \| | |_  | |_ _  __            |
        |            | | | | | | | |\  |  _| | | \ \/ /            |
        |            | |_| | | | | | \ | |   | | |>  <             |
        |             \___/  |_| |_| \_\_|   |_|_/_/\_\            |
        |                                                          |
        |==========================================================|
        )";
        break;
    case 3:
        cout << R"(
            |==========================================================|
            |                                                          |
            |            | | | |_   _| \ | |  ___| (_)                 |
            |            | | | | | | |  \| | |_  | |_ _  __            |
            |            | | | | | | | |\  |  _| | | \ \/ /            |
            |            | |_| | | | | | \ | |   | | |>  <             |
            |             \___/  |_| |_| \_\_|   |_|_/_/\_\            |
            |                                                          |
            |==========================================================|
            )";
        break;
    case 4:
        cout << R"(
                |==========================================================|
                |                                                          |
                |            | | | |_   _| \ | |  ___| (_)                 |
                |            | | | | | | |  \| | |_  | |_ _  __            |
                |            | | | | | | | |\  |  _| | | \ \/ /            |
                |            | |_| | | | | | \ | |   | | |>  <             |
                |             \___/  |_| |_| \_\_|   |_|_/_/\_\            |
                |                                                          |
                |==========================================================|
                )";
        break;

    }

}

