#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life {
private:
	static const unsigned int STUPACA = 40; // y
	static const unsigned int REDAKA = 20; // x
	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost(); //inicijalizacija stanja ćelije
	bool celija_zauzeta(int i, int j); // provjera stanja ćelije
	int broji_susjede(int i, int j); // broji susjede za određivanje next gen
	void inicijalizacija(); // radi polje REDAKA * STUPACA i randomizira za 25% chance to live

public:
	game_of_life(); // zove inicijalizaciju
	void sljedeca_generacija(); // računa next gen
	void iscrtaj(); 
};

#endif
