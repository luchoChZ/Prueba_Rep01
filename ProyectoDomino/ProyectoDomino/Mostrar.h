#pragma once

// Mostrar las fichas de un jugador
void mostrarFichasJugador(fichas fichasJ[], string jugadores[], int num) {
    int i=0 ;
    cout <<endl;
	cout <<"\t\tFichas de "<< jugadores[num] <<endl;
	cout << "\t\t";
	for (i = 0; i < 7; i++) {
         if(fichasJ[i].marca==0)
             cout << "F"<<i+1<<" ["<< fichasJ[i].ladoA << "|" << fichasJ[i].ladoB << "]  ";
     }
	cout << endl;
	cout <<"\t\t_____________________________________________________________________" <<endl;
}

//Muestra las fichas de la mesa
void mostrar_mesa(vector<fichas> mesaA) {
	int i, t = 0;
	system("cls");
	cout << endl;
	cout<<"\t\t\t\t Fichas en la mesa" <<endl;
	cout << endl << "\t\t_____________________________________________________________________" << endl << endl;
	cout << "\t\t";
	if (mesaA.size() <= 8)
		for (i = 0; i < mesaA.size(); i++) 
		 	cout << "[" << mesaA[i].ladoA << " | " << mesaA[i].ladoB << "]  ";
	t = mesaA.size()-8;
	if (mesaA.size() > 8) {
		for (i = 0; i < mesaA.size()-1; i++) {
			if (i == 7) {
				cout << endl << "\t\t";
				cout << "[" << mesaA[i-7].ladoA << " | " << mesaA[i-7].ladoB << "]  ";
			}else
				cout << "[" << mesaA[i + t].ladoA << " | " << mesaA[i + t].ladoB << "]  ";
		}
	}
	cout << endl << "\t\t_____________________________________________________________________" << endl;
}

//Muestra las fichas repartidas
void mostrafichasjugadores(fichas fj1[], fichas fj2[], fichas fj3[], fichas fj4[], string jugadores[]) {
	mostrarFichasJugador(fj1, jugadores, 0);
	mostrarFichasJugador(fj2, jugadores, 1);
	mostrarFichasJugador(fj3, jugadores, 2);
	mostrarFichasJugador(fj4, jugadores, 3);
}

//Lista de jugadores
void muetrajugadores(string jugadores[], int& numJugador) {
	int i;
	cout << endl << "\t\t Seleccine quien inicia la partida" << endl;
	
	for (i = 0; i < 4; i++) {
		cout << " \t\t " << i + 1 << " " << jugadores[i] << endl;
	}
	cout << "\t\t";
	cin >> numJugador;
	numJugador--;
}

void pantallaGanador(string jugadores[], int numJugador) {
	int i;
	system("cls");
	cout << endl << endl;
	cout <<"******************************************************************************"<< endl;
	for (i = 0; i < 12; i++) {
		    cout << "*                                                                            *" << endl;
			if (i == 5) {
				cout << "*                     El ganador(a) es                                     *" << endl;
				cout << "                                       "<< jugadores[numJugador]<< endl;
			}
	}
	cout << "******************************************************************************" << endl;

}
