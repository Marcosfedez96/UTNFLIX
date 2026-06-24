#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>

using namespace std;

////////////////
///CONSTANTES///
////////////////
const int CANTGENEROS = 8;
const int CANTCONTENIDOS = 15;
const int CANTSUSCRIPTORES= 12;

///////////////////////
///Mensajes de error///
///////////////////////
const string ERROR_CONTENIDOS = "          ERROR: es obligatorio completar el lote de genero. carguelo primero";
const string ERROR_SUSCRIPTORES = "          ERROR: es obligatorio completar los lotes de genero y Contenido. carguelo primero";
const string ERROR_REPRODUCCIONES = "            ERROR: es obligatorio completar los lotes de genero, Contenido y Suscriptores. carguelo primero";
const string ERROR_REPORTES = "            ERROR: Es obligatorio completar los lotes de carga. carguelo primero";

////////////////
///  STRUCT  ///
////////////////
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
struct Reporte4
{
    int codCont;
    string titulo;
    char tipoCont;
    string nombGenero;
    float calProm;
};
struct Genero
{
    int cod;
    string nombre;
     // DATOS del desafio adicional
    int diasDestacados[3]       = {0};  // Ava can valores del 1 al 7, y el 0 no aplica
    int cantRepDiaPico          = 0;    // Contador
    int minAcumuladosDiaPico    = 0;    // Acumulador (la duracion x2)

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
    int canRepSub = 0;
};
struct Reproduccion
{
    int nroRep;
    int codCont;
    int codSuscriptor;
    int diaSemana;
    bool completoLaReproduccion;

};
struct Condiciones
{
    bool seCargoGeneros = false;
    bool seCargoContenidos = false;
    bool seCargoSuscriptores = false;
    bool seCargoReproducciones = false;
};

///////////////////////
///MENU DE SELECCION///
///////////////////////
void MenuPrincipal(
    Condiciones &_condiciones,
    Genero _generos[],
    Contenido _contenidos[],
    Reproduccion _reproducion,
    Suscriptor _suscriptores[],
    Reporte1ContMasRep _reporte1ContMasRep[],
    Reporte4 _sinReproducciones[],
    int reproduccionesPorPlan[],
    int &totalDeReproducciones,
    int matrizGenYDia[][7]       /// Reporte 3
);
void SelecMenuPrincipal(
    Condiciones &_condiciones,
    int opcion,
    Genero _generos[],
    Contenido _contenidos[],
    Reproduccion _reproducion,
    Suscriptor _suscriptores[],
    Reporte1ContMasRep _reporte1ContMasRep[],
    Reporte4 _sinReproducciones[],
    int reproduccionesPorPlan[],
    int &totalDeReproducciones,
    int matrizGenYDia[][7]       /// Reporte 3
);
void MenuCargaLotes(
    Condiciones &_condiciones,
    Genero _generos[],
    Contenido _contenidos[],
    Reproduccion _reproducion,
    Suscriptor _suscriptores[],
    Reporte1ContMasRep _reporte1ContMasRep[],
    Reporte4 _sinReproducciones[],
    int reproduccionesPorPlan[],
    int &totalDeReproducciones,
    int matrizGenYDia[][7]       /// Reporte 3
);
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
    int matrizGenYDia[][7]       /// Reporte 3
);
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
    int matrizGenYDia[][7]       /// Reporte 3
);
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
    int matrizGenYDia[][7]       /// Reporte 3
);

////////////////////
///CARGA DE LOTES///
////////////////////
void CargaLoteGenero(Condiciones &_condiciones,Genero _generos[]);
///---------------------------------------------------------------
void CargaLoteContenido(Condiciones &_condiciones,Genero _genero[],Contenido _contenidos[]);
void CargarCod(Contenido _contenidos[],int x);
void CargarNombre(Contenido _contenidos[],int x);
void CargarTipo(Contenido _contenidos[], int x);
void CargarDuracion(Contenido _contenidos[],int x);
void CargarCalificaionProm(Contenido _contenidos[],int x);
bool CargarGeneros(Genero _generos[],Contenido _contenidos[],int x);
void ReiniciarContenidos(Contenido _contenidos[]);

///-----------------------------------------------------------------
void CargaLoteSuscriptores(Condiciones &_condiciones,Suscriptor _suscriptores[]);
///-----------------------------------------------------------------
void CargaLoteReproducciones(
    Condiciones &_condiciones,
    Genero _generos[],
    Reproduccion _reproduccion,
    Contenido _contenidos[],
    Suscriptor _suscriptores[],
    Reporte1ContMasRep _reporte1ContMasRep[],
    int reproduccionesPorPlan[],
    int &totalDeReproducciones,
    int matrizGenYDia[][7]       /// Reporte 3
);
///------------------------------------------------------------------

////////////////////
///   REPORTE 1  ///
////////////////////
void RegistrarRankingContMasRep (Genero _generos[],Contenido _contenidos[],Reproduccion _reproducciones,Reporte1ContMasRep _reporte1ContMasRep[],int posCodCont );
void OrdenarReporte(Reporte1ContMasRep _reporte1ContMasRep[]);
void MostrarReporteContenidoMasReproduciodo(Reporte1ContMasRep _reporte1ContMasRep[]);
void AsignarTipo(Contenido _contenidos[],Reporte1ContMasRep _reporte1ContMasRep[],int posCodCont);
void AsignarGenero(Genero _generos[],Contenido _contenidos[],Reporte1ContMasRep _reporte1ContMasRep[],int posCodCont);
void RegistrarTodosLosContenidos(Genero _generos[],Contenido _contenidos[],Reporte1ContMasRep _reporte1ContMasRep[]);

////////////////////
///   REPORTE 2  ///
////////////////////
void ProcesarReproduccionPorPlan(char plan, int reproduccionPorPlan[], int &totalDeReproducciones);
void MostrarReportePlanDeSuscripcion(int reproduccionesPorPlan[], int &totalDeReproducciones);

////////////////////
///   REPORTE 3  ///
////////////////////
void ProcesarReporteGenYDia(
    Contenido _contenidos[],
    Genero _generos[],
    Reproduccion _reproduccion,
    int matrizGenYDia[][7]
);
void MostrarReporteGeneroYDia(
    int matrizGenYDia[][7],
    Genero _generos[]
);

////////////////////
///   REPORTE 4  ///
////////////////////
void CopiaContenido(Reporte4 _sinReproducciones[], Contenido _contenidos[], Genero _generos[]);
void ContenidoSinReproducciones(Reporte4 _sinReproducciones[]);
void AsignarGenero(Genero _generos[],Contenido _contenidos[],Reporte4 _sinReproducciones[], int x);

////////////////////
///   REPORTE 5  ///
////////////////////
void TopFiveSub(Suscriptor _suscriptores[]);
void SorteoAccesoAnticipado(Suscriptor _suscriptores[], int _ganadores[]);
void AsignarVector(Suscriptor _suscriptoresTop[],Suscriptor _suscriptores[]);
void OrdenarVector (Suscriptor _suscriptoresTop[]);
void MostrarTopFive(Suscriptor _suscriptoresTop[]);
void MostrarGanadores(Suscriptor _suscriptoresTop[], int _ganadores[]);


////////////////
/// RANDOMS  ///
////////////////
void MostrarCreditos();
void Logo(int numTABULACIONES);

////////////////////////////
/// EJERCICIO ADICIONAL  ///
////////////////////////////
void ProcesarDiaPico(
    Contenido _contenidos[],
    Genero _generos[],
    Reproduccion &_reproduccion
    );
void MostrarReporteDiasPico(Genero _generos[]);




#endif // FUNCIONES_H_INCLUDED
