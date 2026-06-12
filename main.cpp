#include <iostream>
#include "Funciones.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Spanish");
    ///Generos///
    const int CANTGENEROS = 8;
    Genero generos[CANTGENEROS];

    ///contenidos///
    const int cantContenido = 15;
    Contenido contenidos[cantContenido];

    ///Suscriptores///
    const int cantSuscriptores = 12;
    Suscriptor suscriptores[cantSuscriptores];

    ///Reproducciones///
    Reproduccion reproducion;

    ///Reporte 1///
    Reporte1ContMasRep reporte1ContMasRep[cantContenido];

    /// Reporte 2 ///
    int reproduccionesPorPlan[3]={0}; // 0=Básico, 1=Estandar, 2=Premium
    int totalDeReproducciones=0;


    MenuPrincipal(generos,contenidos,reproducion,suscriptores,reporte1ContMasRep,reproduccionesPorPlan ,totalDeReproducciones);
    return 0;
}

