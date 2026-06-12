/*
Reporte 2: Actividad por plan de suscripción
Emitir un listado con el total de reproducciones agrupado por plan de suscripción. Incluir:
•   Nombre del plan (Básico, Estándar, Premium).
•   Cantidad total de reproducciones realizadas por suscriptores de ese plan.
•   Porcentaje que representa sobre el total de reproducciones de la semana.
*/
#include <iostream>
#include "Funciones.h"

using namespace std;
void ProcesarReproduccionPorPlan(char plan,int reproduccionesPorPlan[],int &totalDeReproducciones){
    if(plan == 'B' || plan == 'b'){ reproduccionesPorPlan[0]++; }
    if(plan == 'E' || plan == 'e'){ reproduccionesPorPlan[1]++; }
    if(plan == 'P' || plan == 'p'){ reproduccionesPorPlan[2]++; }
    totalDeReproducciones++;
}

void MostrarReportePlanDeSuscripcion(int reproduccionesPorPlan[], int &totalDeReproducciones){
    system("cls");
    /// Agregar color nuevo
    cout << R"(
    |========|=============================================|
    |                                                      |
    |          | | | |_   _| \ | |  ___| (_)               |
    |          | | | | | | |  \| | |_  | |_ _  __          |
    |          | | | | | | | |\  |  _| | | \ \/ /          |
    |          | |_| | | | | | \ | |   | | |>  <           |
    |           \___/  |_| |_| \_\_|   |_|_/_/\_\          |
    |                                                      |
    |========|=============================================|
    |     REPORTE 2: Actividad por plan de suscripcion     |
    |========|=============================================|
    Opcion: )";
    if(totalDeReproducciones>0){
        /// Procesamos las cantidades
        float porcentajePlanBasico      = (float)reproduccionesPorPlan[0]*100/totalDeReproducciones;
        float porcentajePlanEstandar    = (float)reproduccionesPorPlan[1]*100/totalDeReproducciones;
        float porcentajePlanPremium     = (float)reproduccionesPorPlan[2]*100/totalDeReproducciones;

        cout << "Plan Basico: "     << reproduccionesPorPlan[0] << " reproducciones (" << porcentajePlanBasico      << "%)." << endl;
        cout << "Plan Estandar: "   << reproduccionesPorPlan[1] << " reproducciones (" << porcentajePlanEstandar    << "%)." << endl;
        cout << "Plan Premium: "    << reproduccionesPorPlan[2] << " reproducciones (" << porcentajePlanPremium     << "%)." << endl;
    }
    else{
        cout << "Aun no se han cargado las reproducciones en el sistema!" << endl;
    }
    system("pause");
}






