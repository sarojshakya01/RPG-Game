#ifndef GAME_H
#define GAME_H
#include "character.h"

using namespace std;

class Game {
private:
	Character *players[2];
	int current_turn;
	int num_of_characters;

public:
	//constructors
	Game();

	//getters
	int getTurn();
	int getCharacters();

	//other functions
	void RemoveCharacter(int);
	void AddCharacter(Character *);
	void NextTurn();
	void Print();
};

#endif