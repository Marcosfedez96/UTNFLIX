#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <string>

using namespace std;

struct Reporte1ContMasRep
{
    int codCont;
    string titulo;
    string tipo;
    string genero;
    int candRepTotales;
    float porcRepComp = 0;
    int totalComLaRep = 0;
};
struct Genero
{
    int cod;
    string nombre;
};
struct Contenido
{
    int codContenido;
    string titulo;
    char tipo;
    int duracion;
    float califPromedio;
    int CantReproducciones = 0;
    int codGenero;
    int totalComLaRep = 0;
};
struct Suscriptor
{
    int codSuscriptor;
    string nombreYApellido;
    char plan;
    int pantallas;
};
struct Reproduccion
{
    int nroRep;
    int codCont;
    int codSuscriptor;
    int diaSemana;
    bool completoLaReproduccion;

};

void MenuPrincipal(Genero _generos[],Contenido _contenidos[],Reproduccion _reproducion, Suscriptor _suscriptores[],Reporte1ContMasRep _reporte1ContMasRep[],int reproduccionesPorPlan[],int totalDeReproducciones);
void SelecMenuPrincipal(int opcion,Genero _generos[], Contenido _contenidos[],Reproduccion _reproducion, Suscriptor _suscriptores[],Reporte1ContMasRep _reporte1ContMasRep[],int reproduccionesPorPlan[],int totalDeReproducciones );
void MenuCargaLotes(Genero _generos[],Contenido _contenidos[],Reproduccion _reproducion,Suscriptor _suscriptores[],Reporte1ContMasRep _reporte1ContMasRep[], int reproduccionesPorPlan[], int totalDeReproducciones);
void SelecMenuCargaLotes(int opcion, Genero _generos[],Contenido _contenidos[],Reproduccion _reproduccion, Suscriptor _suscriptores[],Reporte1ContMasRep _reporte1ContMasRep[],int reproduccionesPorPlan[],int totalDeReproducciones);
void MenuReportes(Genero _generos[], Contenido _contenidos[], Reproduccion _reproduccion,Suscriptor _suscriptores[], Reporte1ContMasRep _reporte1ContMasRep[], int reproduccionesPorPlan[], int totalDeReproducciones);
void SelecMenuReportes(int opcion,Genero _generos[],Contenido _contenidos[],Reproduccion _reproduccion,Suscriptor _suscriptores[],Reporte1ContMasRep _reporte1ContMasRep[],int reproduccionesPorPlan[],int totalDeReproducciones);


void CargaLoteReproducciones(Genero _generos[],Reproduccion _reproduccion,Contenido _contenidos[], Suscriptor _suscriptores[],Reporte1ContMasRep _reporte1ContMasRep[],int reproduccionesPorPlan[],int totalDeReproducciones);
void CargaLoteGenero(Genero _generos[]);



void CargaLoteContenido(Genero _genero[],Contenido _contenidos[]);
void CargarCod(Contenido _contenidos[],int x);
void CargarNombre(Contenido _contenidos[],int x);
void CargarTipo(Contenido _contenidos[], int x);
void CargarDuracion(Contenido _contenidos[],int x);
void CargarCalificaionProm(Contenido _contenidos[],int x);
void CargarGeneros(Genero _generos[],Contenido _contenidos[],int x);



void CargaLoteSuscriptores(Suscriptor _suscriptores[]);


void MostrarCreditos();

/// Reporte 1 ////
void RegistrarRankingContMasRep (Genero _generos[],Contenido _contenidos[],Reproduccion _reproducciones,Reporte1ContMasRep _reporte1ContMasRep[],int posCodCont );
void OrdenarReporte(Reporte1ContMasRep _reporte1ContMasRep[]);
void MostrarReporteContenidoMasReproduciodo(Reporte1ContMasRep _reporte1ContMasRep[]);
void AsignarTipo(Contenido _contenidos[],Reporte1ContMasRep _reporte1ContMasRep[],int posCodCont);
void AsignarGenero(Genero _generos[],Contenido _contenidos[],Reporte1ContMasRep _reporte1ContMasRep[],int posCodCont);

void RegistrarTodosLosContenidos(Genero _generos[],Contenido _contenidos[],Reporte1ContMasRep _reporte1ContMasRep[]);


//void SelecMenuCargaLotes(int opcion, Contenido _contenidos[],Reproduccion _reproducion, Suscriptor _suscriptores[]);
/// Reporte 2 ///
void ProcesarReproduccionPorPlan(char plan, int reproduccionPorPlan[], int &totalDeReproducciones);
void MostrarReportePlanDeSuscripcion(int reproduccionesPorPlan[], int &totalDeReproducciones);

//void MostrarContenidoPrueba(Contenido _contenidos[]);


void Logo(int numTABULACIONES);






#endif // FUNCIONES_H_INCLUDED
