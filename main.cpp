#include <iostream>
#include <fstream>
#include <string>

#include "barbarian.h"
#include "mage.h"
#include "game.h"

using namespace std;

int main() {

	string filename;
	cout<<"Enter input file name: " << endl;
	cin >> filename;
	ifstream input(filename);

	if (!input.is_open()) {
		cout << "file not found!" << endl;
		exit(0);
	}

	Game game;

	string name, occupation, race, level, health;

	for (int i = 0; i < 2; i++){
		getline(input, occupation);
		getline(input, name);
		getline(input, race);
		getline(input, level);
		getline(input, health);

		if (occupation == "Barbarian") {
			string weapon_name, weapon_damage, weapon_cost, stamina;

			getline(input, stamina);
			getline(input, weapon_name);
			getline(input, weapon_damage);
			getline(input, weapon_cost);

			//Create the Barbarian object
			Barbarian *b = new Barbarian(name, race, stoi(level), stoi(health), stoi(stamina));

			//Equip the weapon to the Barbarian
			b->EquipWeapon(weapon_name, stoi(weapon_damage), stoi(weapon_cost));

			//Add the Barbarian character to the game
			game.AddCharacter(b);

		}

		else if (occupation == "Mage") {
			string mana;
			getline(input, mana);

			//Create a Mage object
			Mage *m = new Mage(name, race, stoi(level), stoi(health), stoi(mana));

			string spell_num;
			getline(input, spell_num);

			for (int i = 0; i < stoi(spell_num); i++) {

				string spell_name, spell_damage, spell_cost;

				getline(input, spell_name);
				getline(input, spell_damage);
				getline(input, spell_cost);

				//Add the spell to the Mage
				m->AddSpell(spell_name, stoi(spell_damage), stoi(spell_cost));
			}

			//Add the Mage to the game
			game.AddCharacter(m);

		}

		string newline;
		getline(input, newline);

	}

	input.close();

	int option = -1;
	do {
		cout << "Please choose an option: " << endl
			 << "1 - Next Turn" << endl
			 << "2 - Print All Characters" << endl
			 << "3 - Exit" << endl;

		cin >> option;
		cout << endl;

		switch (option) {
			case 1: game.NextTurn(); break;
			case 2: game.Print(); break;
			case 3: exit(0);
			default:
				cout << "Invalid Option!" << endl;
		}

		cout << endl;

	}while (option != 3);

	return 0;
}