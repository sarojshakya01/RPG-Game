#ifndef GAME_H
#define GAME_H
#include "character.h"

using namespace std;

int main();

class Game {
	private:
	Character *players[2];
	int current_turn, num_of_characters;

	public:
	Game();

	int getTurn();

	int getCharacters();

	void RemoveCharacter(int);

	void AddCharacter(Character *);

	void NextTurn();

	void Print();
	~Game();

};

#endif