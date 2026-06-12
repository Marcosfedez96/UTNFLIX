#include <iostream>
#include "Funciones.h"
#include <stdio.h>
using namespace std;

void CargaLoteSuscriptores(Suscriptor _suscriptores[])
{
    // 1. Ciclo exacto FOR:
    // Usamos for dado que sabemos la cantidad exacta de suscriptores (12 en este caso).
    for(int x=0; x<12; x++)
    {
        bool codSuscriptorRepetido;
        // 2. Ciclo inexacto de validacion para el código.
        // Acá el diclo do-while ejecuta el código al menos una vez, y si el usuario se comete un error, se vuelve a repetir.
        do
        {
            system("color 0B"); // Cambiamos el color de la consola (fondo negro, letras blancas).
            codSuscriptorRepetido=false;
            Logo(3);
            cout << R"(
            |==========================================================|
            |             Ingrese el Código de Suscriptor:             |
            |==========================================================|
              Opcion: )";
            // Guardamos el valor ingresado en la posicion X del arreglo, dentro del campo codSuscriptor
            cin >> _suscriptores[x].codSuscriptor;

            // Si el suscriptor no está entre el número 1 y 12
            if(_suscriptores[x].codSuscriptor < 1 || _suscriptores[x].codSuscriptor > 12)
            {
                cout << "El código de Suscriptor no es válido. Ingrese un número entre el 1 y el 12." << endl;
                system("color 4");  // Letras en rojo para indicar claramente el error
                system("pause");    // Pausamos la pantalla para que el usuario lea el mensaje
            }
            // Recorremos el vector de contenidos para validar la existencia

            for(int i = 0 ; i < x ; i++)
            {
                if(_suscriptores[x].codSuscriptor == _suscriptores[i].codSuscriptor)
                {
                    cout <<"El condigo de suscriptor: " << _suscriptores[x].codSuscriptor<< " ya existe." << endl;
                    codSuscriptorRepetido=true;
                    system("pause");
                }
            }
            system("cls");          // Limpiamos la pantalla
        }

        // Repetimos hasta que la condición sea correcta:
        while(_suscriptores[x].codSuscriptor < 1 || _suscriptores[x].codSuscriptor > 12 || codSuscriptorRepetido==true);

        // ================================================================================
        // Cargamos el nombre y el apellido del suscriptor (No tiene validación do-while)
        // ================================================================================
        Logo(2);
        cout << R"(
        |==========================================================|
        |       Ingrese el nombre y apellido del suscriptor:       |
        |==========================================================|
        Opcion: )";
        cin.ignore();
        getline(cin, _suscriptores[x].nombreYApellido);
        system("cls");

        // ================================================================================
        // Carga y validación del plan (con validacion do-while nuevamente)
        // ================================================================================
        do
        {
            Logo(3);
            cout << R"(
            |==========================================================|
            |         Ingrese el Tipo de Plan:                         |
            |==========================================================|
            |    b   | Básico                                          |
            |--------|-------------------------------------------------|
            |    s   | Estándar                                        |
            |--------|-------------------------------------------------|
            |    p   | Premium                                         |
            |--------|-------------------------------------------------|
              Opcion: )";
            cin >> _suscriptores[x].plan;

            if(_suscriptores[x].plan != 'b' && _suscriptores[x].plan != 's' && _suscriptores[x].plan != 'p' )
            {
                cout << "El plan seleccionado no es válido." << endl;
                system("color 4");
                system("pause");
            }
            system("cls");
        }
        while (_suscriptores[x].plan != 'b' && _suscriptores[x].plan != 's' && _suscriptores[x].plan != 'p' );
        Logo(3);
        do
        {
            cout << R"(

            |==========================================================|
            |   Ingrese la cantidad de pantallas (1 a 4):              |
            |==========================================================|
            Opcion: )";
            cin >> _suscriptores[x].pantallas;

            if(_suscriptores[x].pantallas < 1 || _suscriptores[x].pantallas > 4)
            {
                cout << "La cantidad de pantalla debe ser de 1 a 4." << endl;
                system("color 4");
                system("pause");
            }
            system("cls");
        }
        while(_suscriptores[x].pantallas<1 || _suscriptores[x].pantallas>4);
    }
}
