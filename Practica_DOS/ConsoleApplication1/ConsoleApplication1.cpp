// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <array>

using namespace std;
void principal();

void pasarMayuscula(string& t) {
    int i;
    for (i = 0; i < t.length(); i++)
        t[i] = toupper(t[i]);
}


void AdivinaNumero() {
    int nuemeraAzar = 0, numero = 0, veces = 0;
    srand(time(NULL));
    char jugar = 'S', gano = 'N', tecla;
    principal();
    cout << setw(40)<<"Se va a generar un numero del 1 a 1000 " << endl << endl
        << setw(40) << " Deber intentar adivinar el numero" << endl;

    do
    {
        nuemeraAzar = rand() % 1000;
        veces = 0;
        gano = 'N';
        do
        {
            cout << setw(40) << "Escriba un numero para ver si adivina " << endl;
            cin >> numero;
            veces++;
            if (nuemeraAzar == numero) {
                principal();
                cout << setw(40) << "Excelente adivinaste el numero" << endl;
                gano = 'S';
            }
            else if (nuemeraAzar > numero) {
                principal();
                cout << setw(40) << "Demasiado bajo  - Intenta de nuevo" << endl; 
            }
            else {
                principal();
                cout << setw(40) << "Demasiado Alto  - Intenta de nuevo" << endl;     
            }
        } while (toupper(gano) == 'N');
        cout << "Solo lo intentastes  " << veces << " veces" << endl;
        cout << "Desea jugar de nuevo  S/N " << endl;
        cin >> jugar;
    } while (toupper(jugar) == 'S');
}

//**************************  Ejercicio 10 varia funciones

string son_anagramas(string p1, string p2) {
    string an;
    int i;
    array<string, 12> arreglo1;
    array<string, 12> arreglo2;
    for (i = 0; i < p1.length(); i++) {
        arreglo1[i] = { p1[i] };
    }
    for (i = 0; i < p2.length(); i++) {
        arreglo2[i] = { p2[i] };
    }
    sort(arreglo1.begin(), arreglo1.end());
    sort(arreglo2.begin(), arreglo2.end());
    if (arreglo1 == arreglo2) {
        an = " son anagramas ";
    }
    else {
        an = " no  son anagramas ";
    }

    return an;
}

void anagramas() {
    string p1 = "", p2 = "", anagramas = "";
    int i;
    principal();
    cout << " Conocer si son anagramas  - Tienen las mismas letras  " << endl;
    cout << "Escriba la palabra 1 " << endl;
    cin >> p1;
    pasarMayuscula(p1);
    cout << "Escriba la palabra 2 " << endl;
    cin >> p2;
    pasarMayuscula(p2);
    cout << setw(35) << "Las palabras: \"" << p1 << "\" y  \"" << p2 << "\""<<son_anagramas(p1, p2) << endl;
}

//**************************************************

int es_panvocalica(string p) {
    int estan = 0;
    //estan = " no es panvocalica";
    if (toupper(p.find("A")) != string::npos) {
        if (toupper(p.find("E")) != string::npos) {
            if (toupper(p.find("I")) != string::npos) {
                if (toupper(p.find("O")) != string::npos) {
                    if (toupper(p.find("U")) != string::npos) {
                        estan = 1;
                    }
                }
            }
        }
    }
    return estan;
}

void panvocalicas() {
    string panvocalicas = "";
    cout << setw(35) << "Precione una tecla" << endl;
    system("pause");
    principal();
    cout << "Escriba una palabra para ver si es panvocalicas - Tiene las 5 vocales " << endl;
    cin >> panvocalicas;
    pasarMayuscula(panvocalicas);
    if (es_panvocalica(panvocalicas) == 1) {
        cout << setw(35) << "La palabra: \"" << panvocalicas << "\" Es panvocalicas " << endl;
    }
    else {
        cout << setw(35) << "La palabra: \"" << panvocalicas << "\" No es panvocalicas " << endl;
    }
}

//******************************************************

string tiene_letras_en_orden(string palabra) {
    int i;
    string orden = " las letras estan en Orden alfabetico ";
    for (i = 0; i < palabra.length() - 1; i++) {
        if (palabra[i] > palabra[i + 1]) {
            orden = " las letras no estan en Orden ";
        }
    }
    return orden;
}

void letras() {
    cout << setw(35) << "Precione una tecla" << endl;
    system("pause");
    principal();
    string palabra = "";
    cout << "Escriba una palabra para ver si esta en orden " << endl;
    cin >> palabra;
    pasarMayuscula(palabra);
    cout << setw(20) << "En la palabra: \"" << palabra <<"\""<< tiene_letras_en_orden(palabra) << endl;
}

//************************************************

int cuenta_panvocalicas(string oracion) {
    int cantidad = 0,i,j,tamano=0;
    string palabra,texto;
    oracion += " ";
    tamano = oracion.length();
    for (i = 0; i < tamano; i++) {
        texto = oracion[i];
        if (texto != " ") {
            palabra += oracion[i];
        }else{
            if (es_panvocalica(palabra) == 1) {
                cantidad++;
                palabra = "";
            }
        }
    }  
    return cantidad;
}

void  oracionpanvocalicas() {
    cout << setw(35) << "Precione una tecla" << endl;
    system("pause");
    principal();
    string oracion = "";
    cout << "Escriba una oracion para conocer cuantas palabra panvocalicas tiene  " << endl;
    cin.clear();
    cin.ignore(250, '\n');
    getline(cin, oracion);
    pasarMayuscula(oracion);
    cout <<"La oracion \""<< oracion << "\" tienes " <<cuenta_panvocalicas(oracion)<< " palabra panvocalicas"<<endl;
}
//***************************************************************
string tiene_letras_dos_veces(string p) {
      string repetidas,p2,texto;
      int i,j,posición,tamano;
      repetidas = " si tiene letras repetidad";
      tamano = p.length();
      
      for (i = 0; i < p.length(); i++) {
          p2 = "";
          posición = i;
          texto = p[i];
          for (j = 0; j < p.length(); j++) {
              if (posición != j) {
                  p2 += p[j];
                  }
          }
         if (toupper(p2.find(texto)) == string::npos) {
             repetidas = " no tiene letras repetidas";
          }
      }
         return repetidas;
}


void dosveces() {
    cout << setw(35) << "Precione una tecla" << endl;
    system("pause");
    principal();
    string palabra = "";
    cout << "Escriba una palabra para ver si tiene dos letras repetidas " << endl;
    cin >> palabra;
    cout << setw(20) << "En la palabra: " << palabra << tiene_letras_dos_veces(palabra) << endl;
}

//**************************************************************

void principal() {
    system("cls");
    cout << "           ****************************************************" << endl;
    cout << "           *                                                  *" << endl;
    cout << "           *             Menu Prqactica 02                    *" << endl;
    cout << "           *      5:  Ejercicio 05 - Adivina Numero           *" << endl;
    cout << "           *      10: Ejercicio 10 - Varios                   *" << endl;
    cout << "           *      11:        Salir                            *" << endl;
    cout << "           *                                                  *" << endl;
    cout << "           ***************************************************" << endl;
    cout << endl;

}

//**************************************************************
int main()
{ 
    int opcion = 0;
     
    principal();
    cin >> opcion;
    if (opcion == 5) {
        AdivinaNumero();
    }
    else if (opcion == 10) {
        anagramas();
        panvocalicas();
        oracionpanvocalicas();
        letras();
        dosveces();
    }
        system("pause");
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
