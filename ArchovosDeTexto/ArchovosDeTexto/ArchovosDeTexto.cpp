// ArchovosDeTexto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <fstream>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

const char *filename = "Prueba.txt";


// crear un archivo en disco cuyo nombre es dado por filename
int crearArchivo(char *filename)
{
	string data = "Esto es un ejemplo";
	ofstream fichero(filename); // crear o re-escribir archivo								
	if (!fichero.fail()) {//verifica si se creo
						 // escribir datos al archivo
		for (int i = 0; i < data.length(); i++){
			fichero.put(data[i]); //el metodo put ingresa un caracter a la vez
		}//fin de for
		fichero.close();// cierra el archivo
		cout << "Archivo creado satisfactoriamente" << endl;
		return 0;//si retorna 0 indica que se trabajo sin problemas
	}
	else{
		cout << "Error al tratar de abrir archivo";
		cin.get();
		return 1;//el 1 indica que ocurrio un error
	}
}

// abrir un archivo en disco cuyo nombre es dado por filename
int leerArchivo(char *filename)
{
	ifstream fichero(filename); // abrir archivo para lectura
							
	if (!fichero.fail()) {// verificar la apertura del archivo
		// lectura de datos
		while (!fichero.eof()){
			//getline(fichero,variable_string)
			cout << (char)fichero.get();
		}
		fichero.close();
		cout << endl << "Archivo leido satisfactoriamente" << endl;
		return 0;
	}
	else{
		cout << "Error al tratar de abrir archivo";
		cin.get();
		return 1;
	}
}

int Copiar() {
	try
	{
		ifstream origen("Prueba.txt");
		string linea;
		if (origen.fail()) throw 1;
		else
		{
			ofstream destino("Copia.txt", ios::_Noreplace);
			if (destino.fail()) throw 2;
			else
			{
				while (!origen.eof())
				{
					getline(origen,linea);
					destino << linea << endl;
					if (destino.fail()) throw 3;
				}
			}
			destino.close();
		}
		origen.close();
	}
	catch (int e)
	{
		if (e == 1) cerr << "Error al abrir el archivo Pruebas.txt" << endl;
		else if (e == 2) cerr << "Error al crear el archivo: Copia.txt" << endl;
		else if (e == 3) cerr << "Fallo de escritura en archivo" << endl;
	}
}

void pila() {
	stack<char> abec;
	for (int i = 'A'; i <= 'Z'; i++)
	{
		abec.push(i);
	}
	while (!abec.empty()) {
		cout << abec.top() << endl;
		abec.pop();
	}
}

int main()
{
	//crearArchivo(filename);
	//leerArchivo(filename);
	//Copiar();
	ofstream ArchivoSalida;
	ArchivoSalida.open("Prueba.txt", ios::app);
	ArchivoSalida << "\nTexto para prueba\n";
	ArchivoSalida << "Texto para prueba1\n";
	ArchivoSalida.close();
	//
	//ifstream Leer;
	//string frase;
	//Leer.open("ArchivoEjemplo.txt");
	//getline(Leer, frase);
	//while(!Leer.eof()){
	//	cout << "Frase leida: " << frase << endl;
	//	getline(Leer, frase);
	//}
	//Leer.close();
	////pila();
	system("pause");
	return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
