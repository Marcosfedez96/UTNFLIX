#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <string>

using namespace std;
 struct Genero {
    int cod;
    string nombre;
};
 struct Contenido {
    int codContenido;
    string titulo;
    char tipo;
    int duracion;
    float califPromedio;
    int codGenero;
};
struct Suscriptor{
    int cod;
    string nombreYApellido;
    char plan;
    int pantallas;
};
struct Reproduccion{
    int nroRep;
    int codCont;
    int codSuscriptor;
    int diaSemana;
    bool completoLaReproduccion;
};
void MenuPrincipal(Contenido _contenidos[],Reproduccion _reproducion);
void SelecMenuPrincipal(int opcion, Contenido _contenidos[],Reproduccion _reproducion );
void MostrarCreditos();
void CargaLoteGenero();
void CargaLoteContenido(Contenido _contenidos[]);
void CargaLoteSuscriptores();
void CargaLoteReproducciones(Reproduccion _reproduccion,Contenido _contenidos[]);
void MenuCargaLotes(Contenido _contenidos[],Reproduccion _reproducion);
void SelecMenuCargaLotes(int opcion, Contenido _contenidos[],Reproduccion _reproducion);

void MostrarContenidoPrueba(Contenido _contenidos[]);







#endif // FUNCIONES_H_INCLUDED
