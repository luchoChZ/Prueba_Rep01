// Buscaminas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <array>
#include <time.h>
#include <iomanip>

using namespace std;
const int F = 10;
const int C = 10;
//formas
void llenarConCero(int m[][C]);
void llenarMostrar(int mMostrar[][C]);
void Crear_Minas(int m[][C], int mn[][C], int cant_minas, int mmostrar[][C]);
void Mostrar_minas(int m[][C]);
int Cant_minas_colocadas(int matrizNumeros[][C]);
void jugar(int mN[][C], int minas, int jugadas, int m[][C], int mmostrar[][C]);
void colocarjugada(int mMinas[][C], int mNunm[][C], int mmostrar[][C], int f, int c, char &g, char &p, int minas);
void partearriba(int mina, int jugada);
//******************************************

int encabezado() {
    system("cls");
    int nivel;
    cout << endl;
    cout << "*         Juego de Buscaminas                *" << endl;
    cout << "_________________________________________ " << endl;
    cout << endl;
    cout << "* Debes encontrar las minas sin explotar  *" << endl;
    cout << "_________________________________________ " << endl;
    cout << "*      Selecciona el nivel de juego       *" << endl;
    cout << endl;
    cout << "*     1:   Practica                       *" << endl;
    cout << "*     2:   Principiante                   *" << endl;
    cout << "*     3:   Intermedio                     *" << endl;
    cout << "*     4:   Avanzado                       *" << endl;
    cout << "*     5:   Experto                        *" << endl;
    cout << "Escriba un numero de 1 0 5 "<<endl;
    cin>>nivel;
    return nivel;
}

//******************************************
int actualizacant_minas(int nivel) {
    if (nivel == 1)
        nivel = 8;
    else if (nivel == 2)
        nivel = 15;
    else if (nivel == 3)
        nivel = 25;
    else if (nivel == 4)
        nivel = 30;
    else if (nivel == 5)
        nivel = 35;
    return nivel;
}


//******************************************


int main() {
    int cant_minas, minas_colocadas=0;
    int vidas = 0;
    int intentos = 0;
    int matriz[F][C];
    int matrizNumeros[F][C];
    int matrizMostrar[F][C];
    srand(time(NULL));
    cant_minas=encabezado();
    if (cant_minas > 0 && cant_minas < 6) {
        llenarConCero(matriz);
        llenarConCero(matrizNumeros);
        llenarMostrar(matrizMostrar);
        cant_minas = actualizacant_minas(cant_minas);
        Crear_Minas(matriz, matrizNumeros, cant_minas, matrizMostrar);
        minas_colocadas= Cant_minas_colocadas(matriz);
        jugar(matrizNumeros, minas_colocadas, intentos,matriz, matrizMostrar);
        
    }
    else {
        cout << "Numero incorrecto" << endl;
    }
    return 0;
}

//******************************************
void llenarConCero(int m[][C])
{
    int i = 0, j = 0;
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            m[i][j] = 0;
        }
    }
}


void llenarMostrar(int mMostrar[][C])
{
    int i = 0, j = 0;
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            mMostrar[i][j] = -1;
        }
    }
}
//******************************************
void posicionesdeMinas(int p[], int cant) {
    int i, salio=0,posicionArreglo;
    for (i = 0; i <= 63; i++) {
        p[i] = i + 1;
    }
    i = 0;
   if( cant > 15)
       cant++;
    while (cant>0)
    {
        salio = (rand() % 63)+1;
        if (salio == p[salio-1]) {
            p[salio - 1] = 0;
        }else {
            cant++;
        }
        cant--;
    }
}

void Crear_Minas(int m[][C], int mn[][C], int cant_minas, int mmostrar[][C])
{
    int recor_ver_minas = 1;
    int vectordeminas[64];
    posicionesdeMinas(vectordeminas, cant_minas);
    //Agrega las minas
    for (int i = 1; i < C-1; i++) {
          for (int j = 1; j < C-1; j++) {
              if(vectordeminas[recor_ver_minas]==0)
                m[i][j] = -1;
                recor_ver_minas++;
          }
    }
    // suma las minas
    for (int i = 1; i < C - 1; i++) {
        for (int j = 1; j < C - 1; j++) {
            if (m[i][j] == 0) 
                mn[i][j]=abs(m[i][j+1]) + abs(m[i][j -1]) + abs(m[i+1][j])+ abs(m[i-1][j])+ abs(m[i + 1][j-1]) + abs(m[i + 1][j+1])+ abs(m[i - 1][j+1])+ abs(m[i - 1][j-1]);
         }
    }
    // suma las minas
    for (int i = 1; i < C - 1; i++) {
        for (int j = 1; j < C - 1; j++) {
            if (m[i][j] == -1)
                mn[i][j] = m[i][j];
        }
    }
}
//******************************************
int Cant_minas_colocadas(int m[][C]) {
    int minas = 0;
    for (int i = 1; i < C - 1; i++) {
        for (int j = 1; j < C - 1; j++) {
            if (m[i][j] == -1)
                minas++;
        }
    }
    return minas;
}

//******************************************
void MostrarP(int m[][C])
{
    int i = 0, j = 0;
    cout << "          Columna  Columna  Columna  Columna  Columna  Columna  Columna  Columna " << endl;
    cout << "             1         2        3        4        5        6       7        8 " << endl;

    for (int i = 1; i < C - 1; i++) {
        for (int j = 1; j < C - 1; j++) {
            if (j == 1)
                cout << " Fila " << i << "-";
            if (m[i][j] == -1)
                cout << "      " << "m" << "  ";
            else
               cout << "      " << m[i][j] << "  ";
            if (j == 8)
                cout << endl;
        }
        cout << endl;
    }
}
//******************************************


//******************************************
void Mostrar_minas(int m[][C])
{
    int i = 0, j = 0;
    cout << "          Columna  Columna  Columna  Columna  Columna  Columna  Columna  Columna " << endl;
    cout << "             1         2        3        4        5        6       7        8 " << endl;
    for (int i = 1; i < C-1; i++) {
        for (int j = 1; j < C-1; j++) {
            if (j == 1)
                cout << " Fila " << i << "-";
                if (m[i][j] > 0) 
                    cout << "      " << m[i][j] << "  ";
                else  
                    if (m[i][j] == 0)
                        cout << "      " << " " << "  ";
                    else
                        if (m[i][j] == -2)
                            cout << "      " << "-" << "  ";
                        else
                        cout << "      " << "X" << "  ";
                if (j == 8)
                    cout<< endl;
        }
        cout << endl;
    }
}

//******************************************
void jugar(int mNunm[][C], int minas, int jugadas, int mMinas[][C], int mmostrar[][C]) {
    system("cls");
    int f = 0, c = 0,marca=1;
    char jugarda = 'N', gano = 'N', perdio = 'N';
    while ((gano == 'N') && (perdio == 'N'))
    {     
        partearriba(minas, jugadas);
        Mostrar_minas(mmostrar);
        cout << endl;
        cout << "  Fila ";
        cin >> f;
        cout << " Columna ";
        cin >> c;
        cout << " marcar ";
        cin >> marca;
        if ((f > 0) && (f <= 8) && (c > 0) && (c <= 8)) {
            jugadas++;
            if (marca == 1)
                colocarjugada(mMinas, mNunm, mmostrar, f, c, gano, perdio, minas);
            else
                mmostrar[f][c] = -2;
            system("cls");
        }
        else {
            cout << " Fila o columna incorrecta" << endl;
            cout << " preciones una tecla" << endl;
            system("pause");
            jugar(mNunm, minas, jugadas, mMinas, mmostrar);
        }
    }
    if (perdio == 'S') {
        system("cls");
        partearriba(minas, jugadas);
        MostrarP(mMinas);
        cout << setw(40) << " GAME OVER" << endl;
        cout << endl << endl;
        cout << setw(40) << "Desea Jugar de nuevo  S/N" << endl;
        cin >> jugarda;
        if (toupper(jugarda) == 'S') {
            main();
        }
    }
    if (gano == 'S') {
        system("cls");
        cout << setw(40) << " FELICIDADES USTED GANO" << endl;
        cout << endl << endl;
        cout << setw(40) << "Desea Jugar de nuevo  S/N" << endl;
        cin >> jugarda;
        if (toupper(jugarda) == 'S') {
            main();
        }
    }


}
//******************************************

void colocarjugada(int mMinas[][C], int mNunm[][C], int mmostrar[][C], int f, int c, char &g, char &p, int minas) {
    int i = 0, j = 0,jugadasCorrectas=0;
    if (mMinas[f][c] == -1)
        p = 'S';
    if (mMinas[f][c] >= 0) 
        mmostrar[f][c] = mNunm[f][c];
    if(mMinas[f][c + 1]>=0)
         mmostrar[f][c+1] = mNunm[f][c+1];
    if (mMinas[f][c - 1] >= 0)
         mmostrar[f][c-1] = mNunm[f][c-1];
    if (mMinas[f + 1][c] >= 0)
         mmostrar[f+1][c] = mNunm[f+1][c];
    if (mMinas[f - 1][c] >= 0)
         mmostrar[f-1][c] = mNunm[f-1][c];
    if (mMinas[f + 1][c - 1] >= 0)
         mmostrar[f+1][c-1] = mNunm[f+1][c-1];
    if (mMinas[f + 1][c + 1] >= 0)
        mmostrar[f+1][c+1] = mNunm[f+1][c+1];
    if (mMinas[f - 1][c + 1] >= 0)
        mmostrar[f-1][c+1] = mNunm[f-1][c+1];
    if (mMinas[f - 1][c - 1] >= 0)
        mmostrar[f-1][c-1] = mNunm[f-1][c-1];
  
    for (int i = 1; i < C - 1; i++) {
        for (int j = 1; j < C - 1; j++) {
            if (mmostrar[i][j] >= 0) {
                jugadasCorrectas++;
                if (jugadasCorrectas >= 64- minas)
                    g = 'S';
            }
       }
    }
}

void partearriba(int mina, int jugada) {
    cout << endl;
    cout << "*         Juego Buscaminas                  *" << endl;
    cout << "_________________________________________   " << endl;
    cout << endl;
    cout << "  Debes debes encontrar " << mina << " minas *" << endl;
    cout << endl;
    cout << "  Numero de intentos " << jugada << endl;

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
