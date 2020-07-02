// Practica_Uno.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//



#include <iostream>
#include <iomanip>
#include <string>
//#include "ConsoleApplication2.h"


using namespace std;
#define P 3.14;

#define P 3.14;
int opcion, radio, salir, tamano, Uactual, Nactual, nota, ausencias;
double area, perimetro, gradosf, gradosC, SalarioBruto;
long double Runidad;
string condicion = "";


//************************* Ejercicio 01


void ejercicio01() {
    cout << "  ESTUDIANTE 	                   PROMEDI0 DEL CURSO " << endl
        << "  -------------                   ------------------" << endl
        << setw(5) << 1 << setw(40) << 84.5 << endl
        << setw(5) << 2 << setw(40) << 67.2 << endl
        << setw(5) << 3 << setw(40) << 77.5 << endl
        << setw(5) << 4 << setw(40) << 86.8 << endl
        << setw(5) << 5 << setw(40) << 94.7 << endl;
}


//******************************** Area Ejercicio 02
double ejercicio02A(double r) {
    double area;
    area = r * r * P;
    return area;
}
double ejercicio02P(double r) {
    double peri;
#define P 3.14;
    peri = 2 * r * P;
    return peri;
}

void calculaCirculo() {
    cout << "Escriba el radio de un circulo " << endl;
    cin >> radio;
    if (cin.fail()) {
        cout << "El Area Ingresada no es correcta " << endl;
    }
    else {
        area = ejercicio02A(radio);
        perimetro = ejercicio02P(radio);
        cout << "El Area es: " << area << " Y el perimetro es : " << perimetro << endl;
    }
}


//***************************************** Peso archivo ejercicio 03
string Cambia_Testo_Unidad(int U) {
    string unidad;
    if (U == 1) {
        unidad = "KB";
    }
    if (U == 2) {
        unidad = "MB";
    }
    if (U == 3) {
        unidad = "GB";
    }
    return unidad;
}
long double convertit(int tamano, int Uactual, int Nactual) {
    long double r = 0;
    if (Uactual == Nactual) {
        r = tamano;
    }
    if (Uactual == 1 && Nactual == 2) {
        r = tamano / 1024.00;
    }
    if (Uactual == 1 && Nactual == 3) {
        r = (tamano / 1024.00) / 1024.00;
    }
    if (Uactual == 2 && Nactual == 1) {
        r = tamano * 1024.00;
    }
    if (Uactual == 2 && Nactual == 3) {
        r = tamano / 1024.00;
    }
    if (Uactual == 3 && Nactual == 1) {
        r = tamano * 1024.00 * 1024.00;
    }
    if (Uactual == 3 && Nactual == 2) {
        r = tamano * 1024.00;
    }
    return r;
}

void CalculaPeso() {
    cout << "Escriba el tamano del Archivo" << endl;
    cin >> tamano;
    cout << setw(40) << "Seleccione la unidad en la que se encuentra el archivo" << endl
        << setw(25) << "1: Esta en KB" << endl
        << setw(25) << "2: Esta en MB" << endl
        << setw(25) << "3: Esta en GB" << endl;
    cin >> Uactual;
    cout << setw(45) << "Seleccione a que Unidad de medida lo quiere pasar" << endl
        << setw(25) << "1: Pasar a KB" << endl
        << setw(25) << "2: Pasar a MB" << endl
        << setw(25) << "3: Pasar a GB" << endl;
    cin >> Nactual;
    Runidad = convertit(tamano, Uactual, Nactual);
    Cambia_Testo_Unidad(Uactual);
    Cambia_Testo_Unidad(Nactual);
    cout << setw(35) << "El resultado de convertir " << endl
        << setw(10) << tamano << " " << Cambia_Testo_Unidad(Uactual) << " A " << Cambia_Testo_Unidad(Nactual) << endl
        << setw(10) << "Son : " << fixed << setprecision(6) << Runidad << "  " << Cambia_Testo_Unidad(Nactual) << endl;
}




//**************************** Grados 4


double grados(double gf) {
    double cel;
    cel = 5 / 9.0 * (gf - 32);
    return cel;
}


void claculaGrados() {

    cout << "Escriba el un valor en grados entre 0 212" << endl;
    cin >> gradosf;
    if (cin.fail()) {
        cout << "Cometio un erro al escribir los grados" << endl;
    }
    else {
        if (gradosf > 0 && gradosf <= 212) {
            gradosC = grados(gradosf);
            cout << "fahrenheit                      Celsius   " << endl
                << setw(8) << gradosf << setw(32) << fixed << setprecision(3) << showpos << gradosC << endl;
        }
        else {
            cout << "Los grados deben ser mayor 0 y menor a 212" << endl;
        }
    }
}

//*************************************** nota 5 
string condicionEstudiante(int nota, int ausencias) {
    string cond = "";
    if (nota >= 70 && ausencias <= 2) {
        cond = "APROBO";
    }
    else if (nota > 60 && ausencias < 2) {
        cond = "APLAZO";
    }
    else if (nota < 60) {
        cond = "REPROBO";
    }
    else if (ausencias > 2) {
        cond = "REPROBO";
    }

    return cond;
}


void calculaNota() {
    cout << "Escriba la nota del estudiante" << endl;
    cin >> nota;
    cout << "Escriba el numero de ausencias" << endl;
    cin >> ausencias;
    condicion = condicionEstudiante(nota, ausencias);
    cout << "La condicion del estudiante es: " << condicion << endl;
}
//********************************* Salario Ejercicio 6


struct sEmpleado {
    string nombre_e;
    double h_trabajadas = 0;
    double salario_hora = 0;
    double salario_ord = 0;
    double salario_ext = 0;
    double salario_bruto = 0;
};

sEmpleado Empl;

sEmpleado Planilla[4];

sEmpleado Solicita_Info(sEmpleado Empl);
void Imprime_Planilla(sEmpleado Planilla[]);

void Calcula_Salario() {
    for (int i = 0; i < 4; i++)
    {
        Planilla[i] = Solicita_Info(Empl);
    }
    Imprime_Planilla(Planilla);
}


sEmpleado Solicita_Info(sEmpleado Empl) {
    cout << "\nIngrese el nombre: ";
    cin >> Empl.nombre_e;
    cout << "\nIngrese la cantidad de horas trabajadas: ";
    cin >> Empl.h_trabajadas;
    cout << "\nIngrese el Salario por Hora: ";
    cin >> Empl.salario_hora;
    if (Empl.h_trabajadas <= 40)
        Empl.salario_ord = Empl.h_trabajadas * Empl.salario_hora;
    else {
        Empl.salario_ord = 40 * Empl.salario_hora;
        Empl.salario_ext = (Empl.h_trabajadas - 40) * Empl.salario_hora * 1.5;
    }
    Empl.salario_bruto = Empl.salario_ord + Empl.salario_ext;
    return Empl;
}


void Imprime_Planilla(sEmpleado Planilla[]) {
    cout << "\n\n\n\tNombre" << setw(20) << "Horas Trabajadas" << setw(20) << "Salario x Hora" << setw(20) <<
        "Salario Ordinario" << setw(20) << "Salario Extra" << setw(20) << "Salario Bruto";
    for (int i = 0; i < 4; i++)
    {
        cout << "\n\t" << Planilla[i].nombre_e << setw(20) << Planilla[i].h_trabajadas << setw(20) << Planilla[i].salario_hora
            << setw(20) << Planilla[i].salario_ord << setw(20) << Planilla[i].salario_ext << setw(20) << Planilla[i].salario_bruto;
    }
}

//**************************** Numeros Romanos Ejercicio 7
void pasarMayuscula(string& s)
{
    for (int i = 0; i < s.length(); i++)
        s[i] = toupper(s[i]);
}
int CalculaRomanos() {
    int ValoresDecimales[] = { 1000, 500, 100, 50, 10, 5, 1 };
    string PosicionesRomanos = "MDCLXVI"; // Para buscar el indice de la letra y asi encontrar el valor en ValoresDecimales
    string RomanoDelUsuario;
    char Letra;
    int resultado = 0;
    int PosicionLetra = 0;
    int IndiceDeLaLetra = 0;
    int ValorDecimalAnterior = 0;
    bool LetraEsValida = true;

    cout << "Calcular Numero Romano" << endl;
    cout << endl;
    cout <<setw(45)<< "M (1000) D (500) C (100) L (50) X (10) V (5) I (1)" << endl;
    cout << "\n\tEscriba el numero Romano:  \n\t";
    cin >> RomanoDelUsuario;
    pasarMayuscula(RomanoDelUsuario);
    cout << "\n\tEl numero ingresado es: " << RomanoDelUsuario << "\n\n";
    while (LetraEsValida && (PosicionLetra < RomanoDelUsuario.length()))
    {
        Letra = RomanoDelUsuario[PosicionLetra];
        IndiceDeLaLetra = PosicionesRomanos.find(Letra);
        if (IndiceDeLaLetra >= 0)
        {
            resultado += ValoresDecimales[IndiceDeLaLetra];
             if (ValoresDecimales[IndiceDeLaLetra] > ValorDecimalAnterior)
            {
                resultado -= 2 * ValorDecimalAnterior;
            }
            ValorDecimalAnterior = ValoresDecimales[IndiceDeLaLetra];
        }
        else
         {
            LetraEsValida = false;
            resultado = -1;
         }
        PosicionLetra++;
    }
    return resultado;
 }



//**************************** Dados Ejercicio 8

void CalculaDados() {
    int sumaDados = 0;
    cout << "Cual es el resultado de la suma de los dos dados" << endl;
    cin >> sumaDados;
    switch (sumaDados)
    {
    case 2:
        cout << "1 + 1" << endl;
        break;
    case 3:
        cout << "2 + 1 y 1 + 2" << endl;
        break;
    case 4:
        cout << "3 + 1 , 2 + 2 y 1 + 3" << endl;
        break;
    case 5:
        cout << "4 + 1 , 3 + 2 , 2 + 3 y 1 + 4" << endl;
    break;
    case 6:
        cout << "5 + 1 , 4 + 2 , 3 + 3 , 2 + 4 y 1 + 5" << endl;
        break;
    case 7:
        cout << "6 + 1 , 5 + 2 , 4 + 3 , 3 + 4 , 2 + 5 y 1 + 6" << endl;
        break;
    case 8:
        cout << "6 + 2 , 5 + 3 , 4 + 4 , 3 + 5 y 2 + 6" << endl;
        break;
    case 9:
        cout << "6 + 3 , 5 + 4 , 4 + 5 y 3 + 6" << endl;
        break;
    case 10:
        cout << "6 + 4 , 5 + 5 y 4 + 6" << endl;
        break;
    case 11:
        cout << "6 + 5 y 5 + 6" << endl;
        break;
    case 12:
        cout << "6 + 6" << endl;
        break;
    default:
        cout << "Esa combinacion no es posible" << endl;
        break;
    }
}

//**************************** Gráfico ejercicio 9

void Grafico() {
    int num, posit, negat;
    posit = 0;
    negat = 0;
    cout << "Ingrese varios valores, termine con 0" << endl;
    cin >> num;
    while (num != 0)
    {
        if (num > 0)
            posit++;
        else
            negat++;
        cin >> num;
    }

    cout << "\n\tPositivos: ";
    for (int i = 0; i < posit; i++)
        cout << "*";

    cout << "\n\tNegativos: ";
    for (int i = 0; i < negat; i++)
        cout << "*";
}



//********************************

int main()
{   
    int resultadoRomano = 0;
    cout << setw(35) << "Menu de ejercicios" << endl
        << setw(40) << "1: Ejercicio 01 - Tabla         " << endl
        << setw(40) << "2: Ejercicio 02 - Perimetro Area" << endl
        << setw(40) << "3: Ejercicio 03 - Conversion    " << endl
        << setw(40) << "4: Ejercicio 04 - Grados        " << endl
        << setw(40) << "5: Ejercicio 05 - Promedio      " << endl
        << setw(40) << "6: Ejercicio 06 - Salario       " << endl
        << setw(40) << "7: Ejercicio 07 - Romanos       " << endl
        << setw(40) << "8: Ejercicio 08 - Dados         " << endl
        << setw(40) << "9: Ejercicio 09 - Grafico       " << endl
        << setw(40) << "10:        Salir                " << endl;
    cin >> opcion;
    if (opcion == 1) {
        ejercicio01();
    }
    else if (opcion == 2) {
        calculaCirculo();
    }
    else if (opcion == 3) {
        CalculaPeso();
    }
    else if (opcion == 4) {
        claculaGrados();
    }
    else if (opcion == 5) {
        calculaNota();
    }
    else if (opcion == 6) {
        Calcula_Salario();
    }
    else if (opcion == 7) {
        resultadoRomano = CalculaRomanos();
        if (resultadoRomano == -1) {
            cout<<setw(40) << "El numero ingresado es incorrecto" << endl;
        }
        else {
            cout << setw(40) << "El resultado es :" << resultadoRomano << endl;
         }
    }
    else if (opcion == 8) {
        CalculaDados();
    }
    else if (opcion == 9) {
        Grafico();
    }
    else if (opcion > 10) {
        cout << "El numero no es valido" << endl;
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
