#include<iostream>
#include <string>
#include "game.h"

using namespace std;

Game :: Game () {
	for (int i = 0; i < 2; i++) {
		this->players[i] = NULL;
	}
	current_turn = 0;
	num_of_characters = 0;
}

int Game :: getTurn() {
	return current_turn;
}

int Game :: getCharacters() {
	return num_of_characters;
}

void Game :: RemoveCharacter(int index) {
	if (index < 0 || index > 1) {
		cout << "Invalid index!" << endl;
	} else if (this->getCharacters() > 0 && this->getCharacters() < 3) {
		if (this->players[index] != NULL && this->players[index] != 0) {
			this->players[index] = NULL;
			this->num_of_characters--;
		} 
	} else {
		cout << "Game should have 2 players! Found " << this->getCharacters() << endl;
	}
}

void Game :: AddCharacter(Character *character) {

	if (this->getCharacters() < 2) {
		for (int i = 0; i < 2; ++i) {
			if (this->players[i] == NULL && this->players[i] != character) {
		 		this->players[i] = character;
		 		this->num_of_characters++;
		 		break;
			}
		 } 
	} else if (this->getCharacters() == 2) {
		cout << "Character limit reached, please wait for the next game!" << endl;
	} else if (this->getCharacters() == 0) {
		cout << "Game should have 2 players! Found " << this->getCharacters() << endl;
	}

}

void Game :: NextTurn() {

	if (this->players[0] == 0 || this->players[1] == 0) {
		cout << "Need more players!" << endl;
	} else {
		if (this->getTurn() == 0) {
			this->players[0]->Attack(this->players[1]);

			this->current_turn = 1;

			if (this->players[1]->getHealth() < 0) {
				cout << players[0]->getName() <<" wins!" << endl;
			} else {

				this->players[1]->Attack(this->players[0]);

				this->current_turn = 0;

				if (this->players[0]->getHealth() < 0) {
					cout << players[1]->getName() << " wins!" << endl;
				}
			}
		} else if (this->getTurn() == 1) {

			this->players[1]->Attack(this->players[0]);

			this->current_turn = 0;

			if (this->players[0]->getHealth() < 0) {
				cout << players[1]->getName() <<" wins!" << endl;
			} else {

				this->players[0]->Attack(this->players[1]);

				this->current_turn = 1;

				if (this->players[1]->getHealth() < 0) {
					cout << players[0]->getName() << " wins!" << endl;
				}
			}
		}
	}
}

void Game :: Print() {
	for (int i = 0; i < 2; ++i) {
		if (this->players[i] != 0) {
			this->players[i]->Print();
		}
	}
}