#include<iostream>
#include <string.h>
#include "game.h"

using namespace std;

Game :: Game () {
	for (int i = 0; i < 2; i++) {
		this->players[i] = NULL;
	}
}

inline int Game :: getTurn() {
	return current_turn;
}

inline int Game :: getCharacters() {
	return num_of_characters;
}

void Game :: RemoveCharacter(int index) {
	switch(index) {
		case 1:
			this->players[0] = NULL;
			break;
		case 2:
			this->players[1] = NULL;
			break;
		default:
			cout << "Invalid index!" << endl;
	}
}

void Game :: AddCharacter(Character *character) {

	for (int i = 0; i < 2; ++i) {

		if (this->players[0] != 0 && this->players[1] != 0) {
			cout << "Character limit reached, please wait for the next game!" << endl;
			break;
		}

		if (this->players[i] == NULL && this->players[i] != character) {

			this->players[i] = character;
			cout << "Character " << character->getName() << " added!" << endl;
			break;

		} else if (this->players[i] == character) {
			cout << "Character " << character->getName() << " already added!" << endl;
			break;
		}
	}

}

void Game :: NextTurn() {
	bool twoPlayer = false;

	if (this->players[0] != 0 && this->players[1] != 0) {
		twoPlayer = true;
	}

	if (!twoPlayer) {
		cout << "Need more players!" << endl;
	} else {
		this->players[0]->Attack(this->players[1]);
		if (this->players[1]->getHealth() < 0) {
			cout << "Players one wins!" << endl;
			std::exit(1);
		} else {
			this->players[1]->Attack(this->players[0]);
			if (this->players[0]->getHealth() < 0) {
				cout << "Players two wins!" << endl;
				std::exit(1);
			} else {
				// main();
			}
		}
	}
}

void Game :: Print() {
	for (int i = 0; i < 2; ++i) {
		if (this->players[i] != 0) {
			this->players[i]->Character::Print();
			this->players[i]->Print();
		}
	}
}

Game :: ~Game() {
	;
}