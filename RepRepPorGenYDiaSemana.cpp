/*Reporte 3: Reproducciones por género y día de la semana
Emitir la cantidad total de reproducciones de cada género discriminadas por día de la semana (lunes
a domingo). El formato debe ser de tabla, mostrando géneros en filas y días en columnas (o
viceversa, a elección del grupo).*/
#include <iostream>
#include "Funciones.h"

using namespace std;
// ---------------------------------------------------------------------------
// Función 1: PROCESAMIENTO
// ---------------------------------------------------------------------------
/// const int CANTGENEROS = 8;  /// PRUEBA DECLARAR EN FUNCIONES.H

void ProcesarReporteGenYDia(
                            Contenido _contenidos[],
                            Genero _generos[],
                            Reproduccion _reproduccion,
                            int matrizGenYDia[][7]
                            ){
    int posFilaGenero = -1;
    int codGeneroDelContenido = -1; // Numero por defecto y sin coincidencias

    // 1. Buscamos el contenido que se reprodujo para saber cuál es su código de género
    int i = 0;
    bool contenidoEncontrado = false;

    // Guardamos el codigo del genero del contenido.
    // El ciclo gira mientras no me pase de los 15 contenidos Y no lo haya encontrado aún
    while (!contenidoEncontrado && i < CANTCONTENIDOS) {
        if (_contenidos[i].codContenido == _reproduccion.codCont) {
            codGeneroDelContenido = _contenidos[i].codGenero;
            contenidoEncontrado = true; // Bandera en true
        }
        i++;
    }

    // 2. Buscamos su posición (osea la fila) en el vector de géneros
    int j = 0;
    bool generoEncontrado = false;

    // Solo buscamos el genero si la busqueda anterior tuvo éxito
    if (codGeneroDelContenido != -1) {
        // El ciclo gira mientras no me pase de los 8 géneros Y no lo haya encontrado
        while (j <= CANTGENEROS && !generoEncontrado) {
            if (_generos[j].cod == codGeneroDelContenido) {
                posFilaGenero = j;
                generoEncontrado = true; // Bandera en true
            }
            j++;
        }
    }

    // 3. Cruzamos datos en la matriz e incrementamos el casillero
    if (posFilaGenero != -1 && _reproduccion.diaSemana >= 1 && _reproduccion.diaSemana <= 7) {
        matrizGenYDia[posFilaGenero][_reproduccion.diaSemana - 1]++;
    }
}


// ---------------------------------------------------------------------------
// Función 2: MOSTRAR RESULTADO (Alineado a mano y estructurando)
// ---------------------------------------------------------------------------
void MostrarReporteGeneroYDia(
                           int matrizGenYDia[][7],
                           Genero _generos[]
                           ){
    system("color 0D");
    system("cls");

    cout << R"(
    |========|==================================================|
    |                                                           |
    |            | | | |_   _| \ | |  ___| (_)                  |
    |            | | | | | | |  \| | |_  | |_ _  __             |
    |            | | | | | | | |\  |  _| | | \ \/ /             |
    |            | |_| | | | | | \ | |   | | |>  <              |
    |             \___/  |_| |_| \_\_|   |_|_/_/\_\             |
    |                                                           |
    |===========================================================|
    |  REPORTE 3: REPRODUCCIONES POR GENERO Y DIA DE LA SEMANA  |
    |===========================================================|
    | Genero          | Lun | Mar | Mie | Jue | Vie | Sab | Dom |
    |-----------------|-----|-----|-----|-----|-----|-----|-----|
    )";

    // Recorremos las filas (Géneros)
    for (int i = 0; i < CANTGENEROS; i++) {
        // Verificamos que el género tenga un nombre válido (que no sea una fila vacía)
        if (_generos[i].nombre != "") {
            cout << "| " << _generos[i].nombre;

            // Calculamos cuántos espacios faltan para llegar a los 15 caracteres de ancho
            int espaciosFaltantes = 15 - _generos[i].nombre.length();
            if (espaciosFaltantes < 0) espaciosFaltantes = 0; // Por las dudas xD

            // Dibujamos los espacios faltantes a mano
            for(int k = 0; k < espaciosFaltantes; k++) {
                cout << " ";
            }
            cout <<  " |";

            // Recorremos las columnas (Días de la semana)
            for (int j = 0; j < 7; j++) {
                int cantidad = matrizGenYDia[i][j];

                // Alineamos los números a la derecha usando ifs (ancho de 3)
                if (cantidad < 10) {
                    cout << "  " << cantidad << "  |"; // 2 espacios + un digiot
                } else if (cantidad < 100) {
                    cout << " " << cantidad << " |";  // 1 espacio + dos digitos
                } else {
                    cout << cantidad << " |";         // Sin espacios (3 dígitos)
                }
            }
            cout << endl;
            cout <<  "    ";

        }
    }

    cout << "|===========================================================|" << endl;

    int opc;
    do {
        cout << "\n Ingrese 0 para volver atras: ";
        cin >> opc;
    } while (opc != 0);
}
