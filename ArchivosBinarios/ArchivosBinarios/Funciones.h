#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Registro {
	int codigo;
	char nombre[30];
	int edad;
	float altura;
};

Registro AlumnoBuscar = { 0,"",0,0 };

bool CrearArchivo(int tipo = 0) {
	char resp = 's';
	int cod = 1;
	Registro Alumno; //estructura que se utilizar para manipular registros
	ofstream Escribir;
	if (tipo == 0)
		Escribir.open("prueba.dat", ios::out | ios::binary);
	else
		Escribir.open("prueba.dat", ios::out | ios::binary | ios::app);
	
	if (!Escribir.fail()) {
		do {
			Alumno.codigo = cod++;
			cout << "Digite el nombre\n";
			cin >> Alumno.nombre;
			cout << "Digite la edad\n";
			cin >> Alumno.edad;
			cout << "Digite la altura\n";
			cin >> Alumno.altura;
			Escribir.write((char*)&Alumno, sizeof(Registro));
			cout << "Desea agregar otro alumno? s/n\n";
			cin >> resp;
		} while (resp == 's' && Escribir.good());
		Escribir.close();
		return true;
	}
	else {
		return false;
	}
}

int CantidadRegistros() {
	ifstream Leer("prueba.dat", ios::in | ios::binary);
	Leer.seekg(0, Leer.end);
	long length = (long)Leer.tellg() / (long)sizeof(Registro);
	Leer.close();
	return length;
}
//Busca por nombre
bool BuscarRegistro(Registro& Datos) {
	ifstream Leer("prueba.dat", ios::in | ios::binary);
	bool encontrado = false;
	char Alumno[30];
	strcpy_s(Alumno, Datos.nombre);
	if (!Leer.fail()) {
		Leer.read((char*)&Datos, sizeof(Registro));
		while (!Leer.eof() && encontrado == false) {
			if (strcmp(Alumno, Datos.nombre) == 0)
				encontrado = true;
			else
				Leer.read((char*)&Datos, sizeof(Registro));
		}
		Leer.close();
	}
	return encontrado;
}
//Busca por coódigo
bool BuscarRegistroCodigo(Registro& Datos) {
	ifstream Leer("prueba.dat", ios::in | ios::binary);
	bool encontrado = false;
	int cod;
	cod = Datos.codigo;
	if (!Leer.fail()) {
		Leer.read((char*)&Datos, sizeof(Registro));
		while (!Leer.eof() && encontrado == false) {
			if (cod == Datos.codigo)
				encontrado = true;
			else
				Leer.read((char*)&Datos, sizeof(Registro));
		}
		Leer.close();
	}
	return encontrado;
}

void MostrarArchivo() {
	Registro Alumno;
	ifstream Leer("prueba.dat", ios::in | ios::binary);
	cout << "Codigo\t\tNombre\t\tEdad\t\tAltura" << endl;
	Leer.read((char*)&Alumno, sizeof(Registro));
	while (!Leer.eof() && !Leer.fail()) {
		cout << Alumno.codigo << "\t\t" << Alumno.nombre << "\t\t"
			<< Alumno.edad << "\t\t" << Alumno.altura << endl;
		Leer.read((char*)&Alumno, sizeof(Registro));
	}
	Leer.close();
}


//copiar un archivo a un axiliar y modifica
int CopiarArchivoModifica(Registro &alum) {
	try
	{	
		Registro Al; //estructura que se utilizar para manipular registros
		ifstream origen("prueba.dat", ios::in | ios::binary);
		string N_nombre;
		if (origen.fail()) throw 1;
		else
		{
			ofstream destino("copia.dat", ios::out | ios::binary);
			if (destino.fail()) throw 2;
			else
			{
				origen.read((char*)&Al, sizeof(Registro));
				while (!origen.eof())
				{
					if (Al.codigo == alum.codigo) {
						cout << "Digite el nuevo nombre\n";
						cin >> Al.nombre;
						cout << "Digite la nueva edad\n";
						cin >> Al.edad;
						cout << "Digite la nueva altura\n";
						cin >> Al.altura;
					}			
					destino.write((char*)&Al, sizeof(Registro));		
					origen.read((char*)&Al, sizeof(Registro));
					if (destino.fail()) throw 3;
				}
			}
			destino.close();
		}
		origen.close();
		remove("prueba.dat");
		rename("copia.dat", "prueba.dat");
	}
	catch (int e)
	{
		if (e == 1) cerr << "Error al abrir el archivo Pruebas.txt" << endl;
		else if (e == 2) cerr << "Error al crear el archivo: Copia.txt" << endl;
		else if (e == 3) cerr << "Fallo de escritura en archivo" << endl;
		// se puede devolver la variable a la función que la llama 
		// para saber porqué se generó el error.
//		throw e;

	}
}


/*
Esta función debe solicitar al usuario el código del alumno que se desea modificar
una vez encontrado debe mostrar los datos almacenados y solicitar los nuevos valores para este registro
y modificar el archivo. Para modificar el archivo utilice el siguiente método:
1. crear un archivo auxiliar, en donde va a copiar todos los datos del archivo original
2. cuando encuentre el registro debe guardar en el archivo auxiliar los nuevos valores solicitados
3.cuando termine el copiar el archivo con los nuevos valores se deben cerrar ambos archivos
4.eliminar el archivo original y renombrar el archivo auxiliar con el nombre del archivo original*/
//La función debe retornar un valor booleano (true si se completa el proceso, false si ocurre algún error)	

bool ModificarRegistro() {
	bool correcto = false;
	cout << "Digite el codigo del alumno que desea Modificar: \n";
	cin >> AlumnoBuscar.codigo;
	if (BuscarRegistroCodigo(AlumnoBuscar)) {//si encuentra el registro lo muestra
		cout << "Registro a modificar : \n"
			<< AlumnoBuscar.nombre << "\n"
			<< AlumnoBuscar.edad << "\n"
			<< AlumnoBuscar.altura << "\n";
		if (CopiarArchivoModifica(AlumnoBuscar)) {
			cout << endl << "Datos modificados correctamente" << endl;
			correcto = true;
		}
	}
	else
	{
		cout << "El registro no se encuentra \n";
	}
	return correcto;
}

//*******************************************


//copiar un archivo a un axiliar y modifica
int CopiarArchivoElimina(Registro alum) {
	try
	{
		Registro Al; //estructura que se utilizar para manipular registros
		ifstream origen("prueba.dat", ios::in | ios::binary);
		string N_nombre;
		if (origen.fail()) throw 1;
		else
		{
			ofstream destino("copia.dat", ios::out | ios::binary);
			if (destino.fail()) throw 2;
			else
			{
				origen.read((char*)&Al, sizeof(Registro));
				while (!origen.eof())
				{
					if (Al.codigo != alum.codigo) 
						destino.write((char*)&Al, sizeof(Registro));
					
					origen.read((char*)&Al, sizeof(Registro));
					if (destino.fail()) throw 3;
				}
			}
			destino.close();
		}
		origen.close();
		remove("prueba.dat");
		rename("copia.dat", "prueba.dat");
	}
	catch (int e)
	{
		if (e == 1) cerr << "Error al abrir el archivo Pruebas.txt" << endl;
		else if (e == 2) cerr << "Error al crear el archivo: Copia.txt" << endl;
		else if (e == 3) cerr << "Fallo de escritura en archivo" << endl;
	}
}


/*
Esta función debe solicitar al usuario el código del alumno que se desea eliminar.
Para eliminar el registro utilice el siguiente método:
1. crear un archivo auxiliar, en donde va a copiar todos los datos del archivo original
2. cuando encuentre el registro a eliminar no copiarlo en el archivo auxiliar
3.cuando termine el copiar todos los registros que se desean mantener, cerrar ambos archivos
4.eliminar el archivo original y renombrar el archivo auxiliar con el nombre del archivo original

La función debe retornar un valor booleano (true si se completa el proceso, false si ocurre algún error)
*/



bool EliminarRegistro() {
	bool correcto = false;
	MostrarArchivo();
	cout << "Digite el codigo del alumno que desea Eliminar: \n";
	cin >> AlumnoBuscar.codigo;
	if (BuscarRegistroCodigo(AlumnoBuscar)) {//si encuentra el registro lo muestra

		if (CopiarArchivoElimina(AlumnoBuscar)) {
			cout << endl << "Datos eliminados correctamente" << endl;
			correcto = true;
		}
	}
	else
	{
		cout << "El registro no se encuentra \n";
	}
	return correcto;
}
