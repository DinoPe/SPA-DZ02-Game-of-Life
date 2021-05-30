#include "game_of_life.h"

bool game_of_life::slucajna_vrijednost()
{
	if ((rand() % 4) == 3) {
		return true;
	}
	return false;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (this->_generacija[i][j] == true) {
		return true;
	}
	
	return false;
}

int game_of_life::broji_susjede(int i, int j)
{
	int susjedi = 0;
	
	for (int p = -1; p < 2; p++) {
		for (int r = -1; r < 2; r++) {

			int a = ((i + p + STUPACA) % STUPACA);
			int b = ((j + r + REDAKA) % REDAKA);

			if (this->_generacija[a][b] == 1) {
				susjedi++;
				
			}
		}
	}
	return (susjedi-1);
}

void game_of_life::inicijalizacija()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (slucajna_vrijednost()) {
				this->_generacija[i][j] = 1;
				
			}
			else {
				this->_generacija[i][j] = 0;
			}
		}
	}


}

game_of_life::game_of_life()
{
	inicijalizacija();
}

void game_of_life::sljedeca_generacija()
{
	

	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (celija_zauzeta(i, j)) 
			
			{ // ALIVE
				if ((broji_susjede(i, j) >= 2) && (broji_susjede(i, j) <= 3)) {
					this->_sljedeca_generacija[i][j] = 1;
					
				}
				else {
					this->_sljedeca_generacija[i][j] = 0;
				}

			}
			else if (celija_zauzeta(i, j)==false)
			
			{ // DEAD
				if (broji_susjede(i, j) != 3) {
					this->_sljedeca_generacija[i][j] = 0;
				}
				else if (broji_susjede(i,j) == 3){
					this->_sljedeca_generacija[i][j] = 1;
				}
			}

		}
	}
}

void game_of_life::iscrtaj() {
	sljedeca_generacija();
	for (int i = 0; i < REDAKA; i++) {
		cout << endl;
		for (int j = 0; j < STUPACA; j++) {
			if (this->_generacija[i][j]) {
				cout << "o";
			}
			else {
				cout << " ";
			}
			this->_generacija[i][j] = this->_sljedeca_generacija[i][j];
		}
	} 
	
}
