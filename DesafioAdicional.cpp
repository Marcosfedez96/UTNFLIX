#include <iostream>
#include <iomanip> // Se incluye para poder usar setw() y alinear las columnas
#include "Funciones.h"

using namespace std;

// ------------------------------
// Función 1: PROCESAMOS
// ------------------------------
// Esta función recibe "al vuelo" los datos cada vez que se carga UNA nueva reproducción.
// Su trabajo es hacer cruce de datos (buscar de qué género es lo que se reprodujo) y
// sumar en los contadores/acumuladores si corresponde a un "Día Pico".
void ProcesarDiaPico(
                     Contenido _contenidos[],
                     Genero _generos[],
                     Reproduccion &_reproduccion
                     ){

    // Variables locales para la primera búsqueda
    int posicionContenido = -1; // Guardará el índice donde se encuentra el contenido (-1 significa "no encontrado aún")
    int i = 0;                  // Índice para recorrer el vector de contenidos
    bool contEncontrado = false; // Bandera (flag) para detener el ciclo while apenas lo encontremos sin usar "break"

    // 1- Buscamos el contenido para saber su duración y de qué género es.
    // El ciclo se repite MIENTRAS no hayamos llegado al final del vector (CANTCONTENIDOS)
    // Y (&&) MIENTRAS todavía no hayamos encontrado el contenido (!contEncontrado).
    while(i < CANTCONTENIDOS && !contEncontrado) {
        // Comparamos el código del vector con el código que tipeó el usuario en la reproducción
        if(_contenidos[i].codContenido == _reproduccion.codCont) {
            posicionContenido = i;  // ¡Lo encontramos! Guardamos en qué cajón/índice estaba
            contEncontrado = true;  // Cambiamos la bandera a true. Esto hará que el while termine en la próxima vuelta.
        }
        i++; // Pasamos al siguiente cajón si no era este
    }

    // Si la posición cambió (ya no es -1), significa que el contenido existe y podemos seguir
    if(posicionContenido != -1) {
        // Extraemos los datos que nos importan de ese contenido específico usando el índice que encontramos
        int codGenero   = _contenidos[posicionContenido].codGenero;
        int duracion    = _contenidos[posicionContenido].duracion;

        // 2- Ahora necesitamos buscar la "caja" del Género que corresponde a ese código
        int posGenero = -1;
        int j = 0;
        bool genEncontrado = false;

        // Misma lógica de búsqueda secuencial que arriba, pero ahora en el vector de géneros
        while(j < CANTGENEROS && !genEncontrado) {
            if(_generos[j].cod == codGenero) {
                posGenero = j;          // Guardamos la posición del género
                genEncontrado = true;   // Activamos la bandera para salir del while
            }
            j++;
        }

        // Si encontramos el género en el vector, procedemos a verificar los días
        if(posGenero != -1) {
            // 3- Verificamos si el día de la reproducción (1 a 7) coincide con algún día destacado
            bool esDiaPico = false;

            // Un for exacto de 3 vueltas, porque la consigna dice que el vector 'diasDestacados' tiene 3 posiciones
            for(int k = 0; k < 3; k++) {
                // Si el cajón no es 0 (tiene un día configurado) y ese día coincide con el día de la reproducción
                if(_generos[posGenero].diasDestacados[k] != 0 && _generos[posGenero].diasDestacados[k] == _reproduccion.diaSemana) {
                    esDiaPico = true; // Confirmamos que se reprodujo en un día promocionado
                }
            }

            // 4- Si es día pico, actualizamos las estadísticas DIRECTAMENTE adentro del struct Género
            if(esDiaPico) {
                // Incrementamos en 1 el contador de reproducciones en día pico para este género
                _generos[posGenero].cantRepDiaPico++;

                // Acumulamos los minutos, multiplicados por 2 como exige la consigna para el día pico
                _generos[posGenero].minAcumuladosDiaPico += (duracion * 2);
            }
        }
    }
}

// ---------------------------------------------------------------------------
// Función 2: MOSTRAR RESULTADOS
// ---------------------------------------------------------------------------
// Esta función se llama únicamente cuando el usuario elige ver el reporte.
// Solo dibuja en pantalla lo que la función ProcesarDiaPico fue calculando internamente.
void MostrarReporteDiasPico(Genero _generos[]) {
    system("color 0E"); /// Dorado Premium para resaltar que es el desafío adicional xD
    system("cls");      /// Limpia la consola

    Logo(2);
    cout << R"(
        |==========================================================|
        |                   DESAFIO ADICIONAL:                     |
        |             ACTIVIDAD EN DIAS PROMOCIONADOS              |
        |==========================================================|
    )";

    // Variables para calcular el PUNTO MÁXIMO (Búsqueda del mayor)
    int maxMinutos = -1;     // Arranca en -1 porque cualquier acumulación será mayor o igual a 0
    int posMaxGenero = -1;   // Guardará el índice del género que tenga el mayor número

    // Encabezado de tabla. Se usa 'left' para alinear a la izquierda y 'setw' para fijar el ancho de las columnas.
    cout << left << "        " << setw(20) << " Nombre del Genero"
         << setw(15) << "Rep. Pico"
         << setw(20) << "Minutos Acum. (x2)" << endl;
    cout << "        |------------------|--------------|------------------------|" << endl;

    // Recorremos secuencialmente TODOS los géneros para imprimirlos
    for(int i = 0; i < CANTGENEROS; i++) {

        // Validación: Solo mostramos géneros que realmente existen (que no estén vacíos en memoria)
        if(_generos[i].nombre != "") {

            // Imprimimos la fila de la tabla tomando los datos desde el struct
            cout << left << "          " << setw(18) << _generos[i].nombre
                 << setw(15) << _generos[i].cantRepDiaPico
                 << setw(20) << _generos[i].minAcumuladosDiaPico << endl;

            // MIENTRAS imprimimos, hacemos el algoritmo de búsqueda de máximo.
            // Preguntamos: ¿Los minutos de este género que estoy mostrando ahora, son mayores al máximo que tenía guardado?
            if(_generos[i].minAcumuladosDiaPico > maxMinutos) {
                // Si es mayor, ahora este es el nuevo "rey" (nuevo máximo)
                maxMinutos = _generos[i].minAcumuladosDiaPico;
                posMaxGenero = i; // Me guardo quién es el dueño de ese récord
            }
        }
    }

    // Cerramos la tabla
    cout << "        |------------------|--------------|------------------------|" << endl;

    // -----------------------------------------------------------------------
    // Imprimimos al ganador (El género con mayor actividad en día pico)
    // Nos aseguramos que el maxMinutos sea mayor a 0 (porque si nadie reprodujo nada, no hay ganador)
    if(maxMinutos > 0 && posMaxGenero != -1) {
        Logo(2);
        cout << "\n        [!] EL GENERO CON MAYOR ACTIVIDAD EN DIA PICO FUE:" << endl;
        // Usamos el índice posMaxGenero que guardamos antes para mostrar el nombre del ganador
        cout << "        >> " << _generos[posMaxGenero].nombre << " <<" << endl;
        cout << "        Liderando con " << maxMinutos << " minutos acumulados." << endl;
    } else {
        // Mensaje de fallback por si el usuario pide el reporte pero todavía no cargó reproducciones pico
        cout << "\n  => No se registraron reproducciones en dias pico." << endl;
    }

    cout << endl;
    system("pause"); // Pausamos la consola para que el usuario pueda leer el reporte antes de volver al menú
}
