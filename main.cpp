#include <iostream>
#include "Funciones.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));


    setlocale(LC_ALL, "Spanish");

    Condiciones condiciones;

    ///Generos///
    Genero generos[CANTGENEROS];

    ///contenidos///
    Contenido contenidos[CANTCONTENIDOS];

    ///Suscriptores///

    Suscriptor suscriptores[CANTSUSCRIPTORES];

    ///Reproducciones///
    Reproduccion reproducion;

    ///Reporte 1///
    Reporte1ContMasRep reporte1ContMasRep[CANTCONTENIDOS];

    /// Reporte 2 ///
    int reproduccionesPorPlan[3]= {0}; // 0=Básico, 1=Estandar, 2=Premium
    int totalDeReproducciones=0;

    /// Reporte 3 ///
    // Generamos la matriz para el tercer reporte.
    // Filas: Generos, columnas: dias de la semana. Inicializamos todo en cero.
    int matrizGenYDia[CANTGENEROS][7] = {0};

    /// Reporte 4 ///
    Reporte4 sinReproducciones[CANTCONTENIDOS] = {0};

    MenuPrincipal(
        condiciones,
        generos,
        contenidos,
        reproducion,
        suscriptores,
        reporte1ContMasRep,
        sinReproducciones,
        reproduccionesPorPlan,
        totalDeReproducciones,
        matrizGenYDia
    );
    return 0;
}

