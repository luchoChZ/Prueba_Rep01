// ProyectoDomino.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iomanip>
#include "inicio.h"
#include "mostrar.h"
#include "jugada.h"

//********** Firmas
void inicio(string jugadores[]);
void crearFichas(fichas ficha, fichas fichasDomino[]);
void repartiFichas(fichas fichasDomino[], fichas fichasj1[]);
void mostrarFichasJugador(fichas fichasJ[], string jugadores[],int num);
void hacerjugada(fichas fj1[], fichas fj2[], fichas fj3[], fichas fj4[], string jugadores[], char& gano, int& numJugador);
void pantallaGanador(string jugadores[], int numJugador);



//************* Modulo Principal del programa Domino
int main()
{
    string jugadores[4];
    fichas ficha, fichasDomino[28], fichasj1[7], fichasj2[7], fichasj3[7], fichasj4[7];
    int cualficha = 0, numJugador=0;
    char gano = 'N', jugarmas='S';

    while (jugarmas == 'S')
    {
        //fichasDomino[1]= fichasj1[1];
        inicio(jugadores);
        crearFichas(ficha, fichasDomino);
        repartiFichas(fichasDomino, fichasj1);
        repartiFichas(fichasDomino, fichasj2);
        repartiFichas(fichasDomino, fichasj3);
        repartiFichas(fichasDomino, fichasj4);
        system("cls");
        mostrarFichasJugador(fichasj1, jugadores, 0);
        mostrarFichasJugador(fichasj2, jugadores, 1);
        mostrarFichasJugador(fichasj3, jugadores, 2);
        mostrarFichasJugador(fichasj4, jugadores, 3);
        hacerjugada(fichasj1, fichasj2, fichasj3, fichasj4, jugadores, gano, numJugador);
        if (gano == 'S') {
            pantallaGanador(jugadores, numJugador - 1);
        }
        cout << endl << setw(40) << "Jugar de nuevo" << endl;
        cin >> jugarmas;
    }
    //system("pause");
}


void repartiFichas(fichas fichasDomino[], fichas fichasJ[]) {
    int numero = 0, cont=0;
    while (cont < 7)
    {
        numero = rand() % 28;
        if (fichasDomino[numero].marca == 0) {
            fichasJ[cont] = fichasDomino[numero];
            fichasDomino[numero].marca = -1;
            cont++;
        }
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
