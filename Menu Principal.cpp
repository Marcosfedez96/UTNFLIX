#include <iostream>
#include "Funciones.h"

using namespace std;

//EN ESTE ARCHIVO VAMOS A TENER TODO LO RELACIONADO A LOS MENUS INTERACTIVOS

void MenuPrincipal(
    Condiciones &_condiciones,
    Genero _generos[],
    Contenido _contenidos[],
    Reproduccion _reproduccion,
    Suscriptor _suscriptores[],
    Reporte1ContMasRep _reporte1ContMasRep[],
    Reporte4 _sinReproducciones[],
    int reproduccionesPorPlan[],
    int &totalDeReproducciones,
    int matrizGenYDia[][7]       /// Reporte 3
)
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
            SelecMenuPrincipal(
                _condiciones,
                opcion,
                _generos,
                _contenidos,
                _reproduccion,
                _suscriptores,
                _reporte1ContMasRep,
                _sinReproducciones,
                reproduccionesPorPlan,
                totalDeReproducciones,
                matrizGenYDia       /// Reporte 3
            );
        }

    }
    while(opcion != 0);

}
void SelecMenuPrincipal(
    Condiciones &_condiciones,
    int opcion,
    Genero _generos[],
    Contenido _contenidos[],
    Reproduccion _reproduccion,
    Suscriptor _suscriptores[],
    Reporte1ContMasRep _reporte1ContMasRep[],
    Reporte4 _sinReproducciones[],
    int reproduccionesPorPlan[],
    int &totalDeReproducciones,
    int matrizGenYDia[][7]       /// Reporte 3
)
{
    switch(opcion)
    {
    case 1:
        MenuCargaLotes(
            _condiciones,
            _generos,
            _contenidos,
            _reproduccion,
            _suscriptores,
            _reporte1ContMasRep,
            _sinReproducciones,
            reproduccionesPorPlan,
            totalDeReproducciones,
            matrizGenYDia       /// Reporte 3
        );
        break;
    case 2:
        MostrarCreditos();
        break;
    }

}

///----------------------------------------------------------------------
///----------------------------------------------------------------------
///----------------------------------------------------------------------
void MenuCargaLotes(
    Condiciones &_condiciones,
    Genero _generos[],
    Contenido _contenidos[],
    Reproduccion _reproduccion,
    Suscriptor _suscriptores[],
    Reporte1ContMasRep _reporte1ContMasRep[],
    Reporte4 _sinReproducciones[],
    int reproduccionesPorPlan[],
    int &totalDeReproducciones,
    int matrizGenYDia[][7]
)
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
                _condiciones,
                _generos,
                _contenidos,
                _reproduccion,
                _suscriptores,
                _reporte1ContMasRep,
                _sinReproducciones,
                reproduccionesPorPlan,
                totalDeReproducciones,
                matrizGenYDia       /// Reporte 3
            );
        }

    }
    while(opcion != 0);

}

void SelecMenuCargaLotes(
    int opcion,
    Condiciones &_condiciones,
    Genero _generos[],
    Contenido _contenidos[],
    Reproduccion _reproduccion,
    Suscriptor _suscriptores[],
    Reporte1ContMasRep _reporte1ContMasRep[],
    Reporte4 _sinReproducciones[],
    int reproduccionesPorPlan[],
    int &totalDeReproducciones,
    int matrizGenYDia[][7]
)
{
    switch(opcion)
    {
    case 1:
        CargaLoteGenero(_condiciones,_generos);
        break;
    case 2:
        if(_condiciones.seCargoGeneros)
        {
            CargaLoteContenido(_condiciones,_generos,_contenidos);

        }
        else
        {
            cout << endl << endl << ERROR_CONTENIDOS << endl << endl ;
            system("Pause");
        }
        break;
    case 3:
        if(_condiciones.seCargoContenidos)
        {
            CargaLoteSuscriptores(_condiciones,_suscriptores);

        }
        else
        {
            cout << endl << endl << ERROR_SUSCRIPTORES << endl << endl ;
            system("Pause");

        }
        break;
    case 4:
        if(_condiciones.seCargoSuscriptores)
        {
            CargaLoteReproducciones(
                _condiciones,
                _generos,
                _reproduccion,
                _contenidos,
                _suscriptores,
                _reporte1ContMasRep,
                reproduccionesPorPlan,
                totalDeReproducciones,
                matrizGenYDia
            );
        }
        else
        {
            cout << endl << endl << ERROR_REPRODUCCIONES << endl << endl ;
            system("Pause");
        }

        break;
    case 5:
        if(_condiciones.seCargoReproducciones)
        {
            MenuReportes(
                _condiciones,
                _generos,
                _contenidos,
                _reproduccion,
                _suscriptores,
                _reporte1ContMasRep,
                _sinReproducciones,
                reproduccionesPorPlan,
                totalDeReproducciones,
                matrizGenYDia
            );
        }
        else
        {
            cout << endl << endl << ERROR_REPORTES << endl << endl ;
            system("Pause");
        }
        break;
    case 0:
        MenuPrincipal(
            _condiciones,
            _generos,
            _contenidos,
            _reproduccion,
            _suscriptores,
            _reporte1ContMasRep,
            _sinReproducciones,
            reproduccionesPorPlan,
            totalDeReproducciones,
            matrizGenYDia
        );
        break;
    }


}

void MenuReportes(
    Condiciones &_condiciones,

    Genero _generos[],
    Contenido _contenidos[],
    Reproduccion _reproduccion,
    Suscriptor _suscriptores[],
    Reporte1ContMasRep _reporte1ContMasRep[],
    Reporte4 _sinReproducciones[],
    int reproduccionesPorPlan[],
    int &totalDeReproducciones,
    int matrizGenYDia[][7]
)
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
        |    6   |Generos con dias destacados                      |
        |--------|-------------------------------------------------|
        |    0   | Volver al menú principal                        |
        |========|=================================================|
          Opcion: )";

        cin >> opcion;
        system("cls"); // Limpiamos nuevamente al procesar la opción

        if(opcion >= 1 && opcion <= 6)
        {
            SelecMenuReportes(
                opcion,                               _condiciones,

                _generos,
                _contenidos,
                _reproduccion,
                _suscriptores,
                _reporte1ContMasRep,
                _sinReproducciones,
                reproduccionesPorPlan,
                totalDeReproducciones,
                matrizGenYDia
            );
        }

    }
    while(opcion != 0);

}

void SelecMenuReportes(
    int opcion,
    Condiciones &_condiciones,
    Genero _generos[],
    Contenido _contenidos[],
    Reproduccion _reproduccion,
    Suscriptor _suscriptores[],
    Reporte1ContMasRep _reporte1ContMasRep[],
    Reporte4 _sinReproducciones[],
    int reproduccionesPorPlan[],
    int &totalDeReproducciones,
    int matrizGenYDia[][7]
)
{
    switch(opcion)
    {
    case 1:
        RegistrarTodosLosContenidos(
            _generos,
            _contenidos,
            _reporte1ContMasRep
        );
        break;
    case 2:
        MostrarReportePlanDeSuscripcion(reproduccionesPorPlan, totalDeReproducciones);
        break;
    case 3:
        MostrarReporteGeneroYDia(matrizGenYDia, _generos);       /// Reporte 3
        break;
    case 4:
        CopiaContenido(_sinReproducciones, _contenidos, _generos);
        break;
    case 5:
        TopFiveSub(_suscriptores);
        break;
    case 6:
        MostrarReporteDiasPico(_generos);
        break;
    case 0:
        MenuCargaLotes(
            _condiciones,
            _generos,
            _contenidos,
            _reproduccion,
            _suscriptores,
            _reporte1ContMasRep,
            _sinReproducciones,
            reproduccionesPorPlan,
            totalDeReproducciones,
            matrizGenYDia);
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
        |  24498 | Fernandez, Marcos                               |
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
