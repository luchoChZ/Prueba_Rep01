#pragma once

#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

//************  Mostrar todas las fichas del dominó
struct fichas {
    int ladoA = 0;
    int ladoB = 0;
    int marca = 0;
};

//*******************  Ventana inicio

void inicio(string jugadores[]) {
    system("cls");
    srand(time(NULL));
    int i = 0;
    cout << "\t\t\t*******************************" << endl;
    cout << "\t\t\t*           Domino            *" << endl;
    cout << "\t\t\t*******************************" << endl;
    cout <<endl<<"\t\t\tSe permiten cuatro jugadores" << endl << endl;
    for (i = 0; i < 4; i++) {
        cout <<endl<<"\t\t\tEscriba el nombre del jugador " << i + 1 << endl<< "\t";
        cout << "\t\t\t";
        cin >> jugadores[i];
    }
}

//************  Crear Fichas de dominó
void crearFichas(fichas ficha, fichas fichasDomino[]) {
    int i, j, contador = 0;
    for (i = 6; i >= 0; i--) {
        for (j = i; j >= 0; j--) {
            ficha.ladoA = i;
            ficha.ladoB = j;
            ficha.marca = 0;
            fichasDomino[contador] = ficha;
            contador++;
        }
    }
}