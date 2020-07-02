#pragma once
#include <xlocnum>

// Firmas de Funciones
void quienjuega(fichas fj1[], fichas fj2[], fichas fj3[], fichas fj4[], int numJugador, fichas ja[]);
void QuitarFicha(fichas fj1[], fichas fj2[], fichas fj3[], fichas fj4[], int numJugador, int numerodeFicha);
void mostrar_mesa(vector<fichas> mesaA);
void mostrafichasjugadores(fichas fj1[], fichas fj2[], fichas fj3[], fichas fj4[], string jugadores[]);
void cambialado(fichas jug_act[], int numerodeFicha);
void muetrajugadores(string jugadores[],int &numJugador);
void pideficha(int& numerodeFicha);
int verificaFicha(fichas fj1[], fichas fj2[], fichas fj3[], fichas fj4[], int numJugador, int nficha);
void ganoSinFichas(fichas fj1[], fichas fj2[], fichas fj3[], fichas fj4[], int numJugador, char &gano);
int ganaPorPuntos(fichas fj1[], fichas fj2[], fichas fj3[], fichas fj4[], int numJugador, char& gano, int na, int nb);
void ContarPuntos(fichas fj1[], fichas fj2[], fichas fj3[], fichas fj4[], int puntos[], int &numJugador);


void hacerjugada(fichas fj1[], fichas fj2[], fichas fj3[], fichas fj4[], string jugadores[], char &gano, int &numJugador)
{
	vector<fichas> mesaA(0);
	fichas jug_act[7];
	int puntos[4] = { 0,0,0,0 };
	int primeraFicha=0,numerodeFicha=0, v_masa_A=0, v_masa_B = 0,i=0,aux=0, colocada;

	muetrajugadores(jugadores, numJugador);
	mostrafichasjugadores(fj1, fj2, fj3, fj4, jugadores);
	if ((numJugador >= 0) && (numJugador <= 3)) {
		while (gano == 'N')
		{
			if (numJugador >= 4)
				numJugador = 0;
			colocada = 1;
			mostrar_mesa(mesaA);//Muestra las fichas que ya están en la mesa
			quienjuega(fj1, fj2, fj3, fj4, numJugador, jug_act);//Verifica cual es el jugador actual
			mostrarFichasJugador(jug_act, jugadores, numJugador);//Muestra el jugador actual
			pideficha(numerodeFicha);//le pide la ficha a l jugador actual

			if ((numerodeFicha >= 0) && (numerodeFicha <= 6)) {//Revisa que la ficha esté entre 1 y 7
				if (verificaFicha(fj1, fj2, fj3, fj4, numJugador, numerodeFicha) == 0) {//revisa que la ficha no se haya jugado
					if (primeraFicha == 0) {
						mesaA.insert(mesaA.begin(), 1, jug_act[numerodeFicha]);
						v_masa_A = jug_act[numerodeFicha].ladoA;
						v_masa_B = jug_act[numerodeFicha].ladoB;
						primeraFicha = 1;
						colocada = 0;//la ficha si se inserta en alguna de las posiciones
					}
					else if (jug_act[numerodeFicha].ladoA == v_masa_B) {
						mesaA.push_back(jug_act[numerodeFicha]);
						v_masa_B = jug_act[numerodeFicha].ladoB;
						colocada = 0;
					}
					else if (jug_act[numerodeFicha].ladoB == v_masa_A) {
						mesaA.insert(mesaA.begin(), 1, jug_act[numerodeFicha]);
						v_masa_A = jug_act[numerodeFicha].ladoA;
						colocada = 0;
					}
					else if (jug_act[numerodeFicha].ladoA == v_masa_A) {
						cambialado(jug_act, numerodeFicha);
						mesaA.insert(mesaA.begin(), 1, jug_act[numerodeFicha]);
						v_masa_A = jug_act[numerodeFicha].ladoA;
						colocada = 0;
					}
					else if (jug_act[numerodeFicha].ladoB == v_masa_B) {
						cambialado(jug_act, numerodeFicha);
						mesaA.push_back(jug_act[numerodeFicha]);
						v_masa_B = jug_act[numerodeFicha].ladoB;
						colocada = 0;
					}
					if (colocada == 0) {
						numJugador++;
						QuitarFicha(fj1, fj2, fj3, fj4, numJugador - 1, numerodeFicha);
						ganoSinFichas(fj1, fj2, fj3, fj4, numJugador - 1, gano);
						
						if (ganaPorPuntos(fj1, fj2, fj3, fj4, numJugador - 1, gano, v_masa_A, v_masa_B) == 1) {
							cout << " Ya no hay jugadas posibles " << endl;
							ContarPuntos(fj1, fj2, fj3, fj4, puntos, numJugador);
							ganoSinFichas(fj1, fj2, fj3, fj4, numJugador - 1, gano);
							gano = 'S';
							system("pause");
						}
					}
					else {
						cout << "\t\t No se puede colocar la ficha " << endl;
						system("pause");
					}
				}
				else {
					cout << "\t\t Esa ficha ya no la tiene " << endl;
					system("pause");
				}
			}
			else {
				if (numerodeFicha == 7) {
					numJugador++;
				}
				else {
					cout <<"\t\t Numero de ficha muy alto" << endl;
					system("pause");
				}
			}

		}//fin while
	}
	else
	{
		system("cls");
		cout <<"\t\t Numero de jugador incorrecto" << endl;
		system("pause");
		system("cls");
		hacerjugada(fj1, fj2, fj3, fj4, jugadores, gano, numJugador);
	}
}

//cargar jugador actual
void CargaJugador(fichas ja[], fichas fj[]) {
	int i;
	for (i = 0; i <= 7; i++) {
		ja[i] = fj[i];
	}
}

// cual es el jugador
void quienjuega(fichas fj1[], fichas fj2[], fichas fj3[], fichas fj4[], int numJugador,fichas ja[]) {
	if(numJugador==0){
		CargaJugador(ja, fj1);
	}else	if (numJugador == 1) {
		CargaJugador(ja, fj2);
	}
	else	if (numJugador == 2) {
		CargaJugador(ja, fj3);
	}
	else	if (numJugador == 3) {
		CargaJugador(ja, fj4);
	}
}

// quitar ficha de jugador
void QuitarFicha(fichas fj1[], fichas fj2[], fichas fj3[], fichas fj4[], int numJugador, int numerodeFicha) {
	if (numJugador == 0) {
		fj1[numerodeFicha].marca = -1;
	}
	else	if (numJugador == 1) {

		fj2[numerodeFicha].marca = -1;
	}
	else	if (numJugador == 2) {
		fj3[numerodeFicha].marca = -1;
	}
	else	if (numJugador == 3) {
		fj4[numerodeFicha].marca = -1;
	}
}
//cambia lado ficha
void cambialado(fichas jug_act[], int numerodeFicha) {
	int aux;
	aux = jug_act[numerodeFicha].ladoA;
	jug_act[numerodeFicha].ladoA = jug_act[numerodeFicha].ladoB;
	jug_act[numerodeFicha].ladoB = aux;
}


//pide la ficha al jugador
void pideficha(int &numerodeFicha) {
	cout << "\n";
	cout << "\t\t Escriba el numero de ficha: " << endl;
	cout << "\t\t 8 para pasar: " << endl;
	cout << "\t\t ";
	cin >> numerodeFicha;
	numerodeFicha--;
}


//Revisa si la ficha está disponible
int verificaFicha(fichas fj1[], fichas fj2[], fichas fj3[], fichas fj4[], int numJugador, int nFicha) {
	int disponible = 0;
	if (numJugador == 0) {
		if (fj1[nFicha].marca == -1)
			disponible = 1;
	}
	else if (numJugador == 1) {
		if (fj2[nFicha].marca == -1)
			disponible = 1;
	}
	else if (numJugador == 2) {
		if (fj3[nFicha].marca == -1)
			disponible = 1;
	}
	else if (numJugador == 3) {
		if (fj4[nFicha].marca == -1)
			disponible = 1;
	}
	return disponible;
}

int buscaJugadorSinFichas(fichas fj[], char gano) {
	int ganador = 1, i;
	for (i = 0; i < 7; i++) {
		if (fj[i].marca == 0)
			ganador = 0;
	}
	return ganador;
}


//revisa que si un jugador se queda sin fichsa gana
void ganoSinFichas(fichas fj1[], fichas fj2[], fichas fj3[], fichas fj4[], int numJugador, char &gano) {
	
	if (numJugador == 0) {
		if (buscaJugadorSinFichas(fj1, gano) == 1)
			gano = 'S';
	} 
	if (numJugador == 1) {
			if (buscaJugadorSinFichas(fj2, gano) == 1)
				gano = 'S';
	}
	if (numJugador == 2) {
		if (buscaJugadorSinFichas(fj3, gano) == 1)
			gano = 'S';
	}
	if (numJugador == 3) {
		if (buscaJugadorSinFichas(fj4, gano) == 1)
			gano = 'S';
	}
}

//***************   revisa posibles jugaas
int PosiblesJugada(fichas fj[], int na, int nb) {
	int puedejugar = 0,i;
	for (i = 0; i < 7;i++) {
		if(fj[i].marca==0)
		   if ((fj[i].ladoA == na) or (fj[i].ladoA == nb) or (fj[i].ladoB == na) or (fj[i].ladoB == nb))
				puedejugar = 1;//puede jugar
	}
	return puedejugar;
}

//********  revisa si gana cuando no hay jugadas
int ganaPorPuntos(fichas fj1[], fichas fj2[], fichas fj3[], fichas fj4[], int numJugador, char& gano, int na, int nb) {
	int sinJugadas = 0,ja=0,jb=0,jc=0,jd=0;// si no hay jugadas se pone en 1
		if (PosiblesJugada(fj1, na, nb) == 1)
			ja = 1;
		if (PosiblesJugada(fj2, na, nb) == 1)
			jb = 1;
		if (PosiblesJugada(fj3, na, nb) == 1)
			jc = 1;
		if (PosiblesJugada(fj4, na, nb) == 1)
			jd = 1;
	if ((ja == 0) && (jb == 0) && (jc == 0) && jd == 0)
		sinJugadas = 1;
	return sinJugadas;
}
//contar los puntos cuando no se gastan las fichas

int suma(fichas fichasjugador[]) {
	int i, total=0;
	for (i = 0; i < 7; i++) {
		if (fichasjugador[i].marca != -1) {
			total = total + fichasjugador[i].ladoA + fichasjugador[i].ladoB;
		}
	}
	return total;
}

void ContarPuntos(fichas fj1[], fichas fj2[], fichas fj3[], fichas fj4[], int puntos[], int& numJugador) {
	int menor,i;
		puntos[0] = suma(fj1);
		puntos[1] = suma(fj2);
		puntos[2] = suma(fj3);
		puntos[3] = suma(fj4);
		menor = puntos[0];
		numJugador = 0;
		for (i = 0; i < 4; i++) {
			if (menor > puntos[i]) {
				menor = puntos[i];
				numJugador = i;
			}
		}
}