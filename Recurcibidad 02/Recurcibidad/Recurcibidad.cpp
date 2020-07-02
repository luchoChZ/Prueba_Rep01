// Recurcibidad.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>

using namespace std;

//     Pregunta # 1
//     Programar un algoritmo recursivo que permita hacer la división por restas 
//     sucesivas.Dicho método consiste en restar del número mayor el menor, 
//     si sigue siendo mayor se resta otra vez y así hasta que sea menor que el 
//      menor inicial.Se debe llevar la cuenta de cuántas resta se hacen y 
//     ese número de restas posibles será el cociente.
//     Ejemplo 1324 dividido entre 312
//     1324 - 312 = 1012 contamos una vez y seguimos porque 1012 >= 312
//     1012 - 312 = 700 contamos 2 veces y continuamos porque 700 >= 312
//    700 - 312 = 388 contamos 3 veces y continuamos porque 388 >= 312
//    388 - 312 = 76 contamos 4 veces y paramos porque 76 < 312
//    Luego la división es 4 y el resto 76.
double NumeroRestas(int &mayor, int menor) {
    double resultado;
    if (mayor < menor) {
        resultado = 0;
    }
    else {
        mayor = mayor-menor;
        resultado = NumeroRestas(mayor , menor) + 1;
    }
    return resultado;
}

void pregunta_1() {
    int num1, num2, resultado;
    cout << "Escriba el numero mayor" << endl;
    cin >> num1;
    cout << "Escriba el numero menor" << endl;
    cin >> num2;
    if (num2 >= num1) {
        cout << "El numero 1 debe ser mayor que el numero 2" << endl;
        system("pause");
    }
    else {
        resultado = NumeroRestas(num1, num2);
        cout << " Restas posibles es " << resultado << endl;
        cout << "  Lo que sobra es: " << num1 << endl;
    }        
}


//***********     Pregunta 02
//Programar un algoritmo recursivo que permita invertir un número.Ejemplo: 
//Entrada: 123 Salida : 321
string invertirnumero(int num) {
    string resultado;
    if (num < 10)
        resultado = to_string(num);
    else {
        resultado = to_string((num % 10)) +    invertirnumero(num / 10);
    }
    return resultado;
}

void pregunta_2() {
    int numero;
    cout << "Escriba un numero" << endl;
    cin >> numero;
    cout << " Resultado " << invertirnumero(numero) << endl;
}

//***********     Pregunta 03
//    Programar un algoritmo recursivo que permita sumar los dígitos de un número.
//    Ejemplo: Entrada: 123 Resultado : 6

int sumadigitos(int n) {
    int resultado;
    if (n < 10) {
        resultado = n;
    }
    else {
        resultado = (n % 10) + (sumadigitos(n / 10));
    }
    return resultado;
}

void pregunta_3() {
    int numero;
    cout << "numero" << endl;
    cin >> numero;
    cout << " Resultado " << sumadigitos(numero) << endl;
}

//***********     Pregunta 04
//   Programar un algoritmo recursivo que calcule el Máximo 
//   común divisor de dos números

int MaximoComuDivisor(int a, int b, int i,int resultado) {
     if ((a < i) or (b < i)){ 
        return resultado;
    }
    else {
        if ((a % i == 0) && (b % i == 0)) {
            resultado = i;
        }
        return MaximoComuDivisor(a, b, i + 1, resultado);
    }
}

void pregunta_4() {
    int n1, n2, r,resultado=1, cont=1;
    cout << "Escriba el numero uno" << endl;
    cin >> n1;
    cout << "Escriba el numero dos" << endl;
    cin >> n2;
    r = MaximoComuDivisor(n1, n2, cont, resultado);
    cout <<endl<< "maximo comun divisor " << r << endl;;

}

//***********     Pregunta 05
//   	Programar un algoritmo recursivo 
//     que permita multiplicar los elementos de un vector.

int multiplicar(int a[], int tamanio, int resultado) {
    if (tamanio == -1) {
          return resultado;
    }
    else {
        return a[tamanio] * multiplicar(a, tamanio - 1, resultado);
    }
}
void pregunta_5() {
    int a[5] = { 2,2,4,3,4 }, resultado=1;
    cout << " Vector Multiplicado " << multiplicar(a, 4, resultado) << endl;
}


//***********     Pregunta 06
//	Programar un algoritmo recursivo que permita obtener el número menor de un vector.
int buscamenor(int a[], int tamanio,int menor) {
    //caso base
    if (tamanio == 0) {
        if (menor < a[0])
            return menor;
        else
            return a[0];
    }
    else {
        if (menor > a[tamanio]) {
            menor = a[tamanio];
        }
        return buscamenor(a, tamanio-1, menor);
    }
}

void pregunta_6() {
    int a[5] = { 3,5,2,8,9 }, menor;
    menor = a[4];
    cout << " Menor " << buscamenor(a, 4, menor) << endl;
}

//***********     Pregunta 07
//Realice una función recursiva que realice una búsqueda binaria 
//en un arreglo previamente ordenado
int buequedaBinaria(int a[], int bajo, int alto, int buscado) {
    int central;
    if (alto < bajo){
            return -1;
    }     
   else {
        central = (bajo + alto) / 2;
        if (a[central]==buscado) {
            return a[central];
        }
        else if (a[central] < buscado)
            return buequedaBinaria(a, central+1, alto, buscado);
        else
            return buequedaBinaria(a, bajo, central -1, buscado); 
    }
}

void pregunta_7() {
    int a[10] = { 1,2,3,4,5,6,7,10,15,17 },buscado, bajo=0,alto=9;
    cout << "Escriba el valor a buscar" << endl;
    cin >> buscado;
    cout << " Resultado " << buequedaBinaria(a, bajo ,alto, buscado) << endl;
}

//***********     Pregunta 08
//	La función potencia(b, n), realiza n iteraciones para poder obtener el valor
//  de b^ n.Sin embargo, es posible optimizarla teniendo en cuenta que :
//              b ^ n = b ^ (n / 2) × b ^ (n / 2) si n es par.
//              b ^ n = b ^ (n−1) / 2 × b ^ (n−1) / 2 × b si n es impar.
//Para esta función, tomaremos n = 0 como el caso base, en el que
//devolveremos 1; y el caso recursivo tendrá dos partes, correspondientes a los 
//dos posibles grupos de valores de n.

int potencia(int base, int exp) {
    int resultado;
    if (exp <= 0) {
        return 1;
    }
    else
    {
        if (exp % 2 == 0) {
            resultado = potencia(base, exp / 2);
            return resultado * resultado;
        }
        else {
            resultado = potencia(base, (exp - 1)/2);
            return resultado * resultado * base;
        }
    }
}

void pregunta_8() {
    int base, exp,resultado;
    cout << " Escriba la base " << endl;
    cin >> base;
    cout << " Escriba el exponente " << endl;
    cin >> exp;
    cout << "  resultado " << potencia(base, exp)<<endl;
}


//***********     Pregunta 09
//Escribir una función que simule el siguiente experimento : Se tiene una rata en una jaula
//con 3 caminos, entre los cuales elige al azar(cada uno tiene la misma probabilidad), si elige
//el 1 luego de 3 minutos vuelve a la jaula, si elige el 2 luego de 5 minutos vuelve a la jaula,
//en el caso de elegir el 3 luego de 7 minutos sale de la jaula.La rata no aprende, siempre 
//elige entre los 3 caminos con la misma probabilidad, pero quiere su libertad, por lo que 
//recorrerá los caminos hasta salir de la jaula.La función debe devolver el tiempo que tarda 
//la rata en salir de la jaula.
// VERSION UNO
int Calcula_salida(int t) {
    int camino;
    camino = 1 + rand() % 3;
    if (camino == 3) {
        t = t+7;
        return t;
    }
    else if (camino == 2) {
        t = t + 5;
        Calcula_salida(t);
    }
    else {
        t = t + 3;
        Calcula_salida(t);
    }
}
// VERSION DOS
int Calcula_salida() {
    int camino;
    camino = 1 + rand() % 3;
    if (camino == 3)
        return 7;
    else if (camino == 2) {
        return Calcula_salida()+5;
    }
    else {
        return Calcula_salida() + 3;
    }
}
void pregunta_9() {
    int t = 0;
    cout << "La rata requiere " << Calcula_salida(t) << "  munutos para salir" << endl;
    cout << "version 2" << endl;
    cout << "La rata requiere " << Calcula_salida() << "  munutos para salir" << endl;
}

//***********     Pregunta 10
// Escribir una función recursiva que reciba como parámetros dos strings a y b, 
//y devuelva una lista con las posiciones en donde se encuentra b dentro de a.Ejemplo:
//     >> > posiciones_de("Un tete a tete con Tete", "te")
//    [3, 5, 10, 12, 21]

string buscarpalabra(string frase, string palabra, int posicion) {
    if (posicion < palabra.length()) {
        return "";
    }
    else {
        if (frase.substr(posicion, palabra.length()) == palabra) {
            return buscarpalabra(frase, palabra, posicion-1) + to_string(posicion) + " ";
        }
        else {
            return buscarpalabra(frase, palabra, posicion-1);
        }
    }
}
void pregunta_10() {
    string frase = "Un tete a tete con Tete", palabra = "te";
    cout << buscarpalabra(frase, palabra, frase.length() - 1) << endl;
}


//***********     Pregunta 11
//   Escribir una función que calcule recursivamente el 
//   n - ésimo número triangular(el número 1 + 2 + 3 + ... + n).

int triangular(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n + triangular(n - 1);
    }
}
void pregunta_11() {
    int num;
    cout<< " Escriba unnumero para ver su tringular "<<endl;
    cin >> num;
    cout << "Triangular de "<<num<< " es "<< triangular(num) << endl;
}

//***********     Pregunta 12
//  La representación binaria de un número natural N, se obtiene con los restos que resultan 
//  de dividir sucesivamente N por 2, hasta que el dividendo se hace 0. Dichos restos se 
//  utilizan en el orden inverso al que fueron calculados para armar el correspondiente 
//  número binario.Por ejemplo : 28
//      dividendo	divisor	cociente	resto
//      28	           2	   14	    0
//      14	           2	   7	    0
//      7	           2	   3	    1
//      3	           2	   1	    1
//      1	           2	   0	    1
//      0
//Por lo que 28 en binario es 11100. Dado un número natural N, 
//escriba un planteo recursivo para expresarlo en sistema binario.

string decimalBinario(int n) {
    if (n == 0) {
        return to_string(n);
    }
    else {
        return decimalBinario(n / 2)  + to_string(n % 2);
    }
}

void pregunta_12() {
    int numero;
    cout << "Escriba un numero" << endl;
    cin >> numero;
    cout << " Resultado es  " << decimalBinario(numero)<<endl;
}


//*******************************************************************************
//*******************************************************************************
int main()
{
    int pregunta = 0;
    srand(time(NULL));
    while (pregunta < 13)
    {
        system("cls");
        cout << endl <<"      Practica de Recursividad" << endl << endl;
        cout << endl <<"      Escriba numero de pregunta" << endl << endl;
        cout <<"              1   - Restas Sucesivas" << endl;
        cout <<"              2   - Invertir Numero" << endl;
        cout <<"              3   - Sumar digitos de num" << endl;
        cout <<"              4   - Maximo Comun divisor" << endl;
        cout <<"              5   - Multiplicar vector" << endl;
        cout <<"              6   - Nun Menor de un vector" << endl;
        cout <<"              7   - Busqueda Binaria" << endl;
        cout <<"              8   - Base y exponente" << endl;
        cout <<"              9   - Tiempo para salir una rata"<< endl;
        cout <<"              10  - Lista con las posiciones" << endl;
        cout <<"              11  - Numero triangular " << endl;
        cout <<"              12  - Numero a Binario " << endl;
        cout <<"              13   Para salir" << endl;
        cin >> pregunta;
        switch (pregunta)
        {
        case 1:
            pregunta_1();
            break;
        case 2:
            pregunta_2();
            break;
        case 3:
            pregunta_3();
            break;
        case 4:
            pregunta_4();
            break;
        case 5:
            pregunta_5();
        break;       
        case 6:
            pregunta_6();
            break;
        case 7:
            pregunta_7();
        break;   
        case 8:
            pregunta_8();
            break;
        case 9:
            pregunta_9();
            break;
        case 10:
            pregunta_10();
            break;
        case 11:
            pregunta_11();
            break;
        case 12:
            pregunta_12();
            break;
        default:
            break;
        }
        system("pause");
    }

}


//Programar un algoritmo recursivo que permita obtener el número menor de un vector





// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
