#include <iostream>
#include <fstream>
#include <string.h>
#include "game.h"
#include "mage.h"
#include "barbarian.h"

using namespace std;

int main() {

	ifstream infile("input.txt");

	string input;
	string name, race, weaponname, spellname;
	int level, health, stamina, weapondamage, weaponstamina_cost, mana, noOfSpulls, spelldamage, spellmana_cost;

	Barbarian *b;
	Mage *m;

	while(infile){

		getline(infile, input);

		if (input == "Barbarian") {

			getline(infile, input);
			name = input;

			getline(infile, input);
			race = input;

			getline(infile, input);
			level = stoi(input);

			getline(infile, input);
			health = stoi(input);

			getline(infile, input);
			stamina = stoi(input);

			getline(infile, input);
			weaponname = input;

			getline(infile, input);
			weapondamage = stoi(input);

			getline(infile, input);
			weaponstamina_cost = stoi(input);

			b = new Barbarian(name, race, level, health, stamina);
			b->EquipWeapon(weaponname, weapondamage, weaponstamina_cost);

		} else if (input == "Mage") {

			getline(infile, input);
			name = input;

			getline(infile, input);
			race = input;

			getline(infile, input);
			level = stoi(input);

			getline(infile, input);
			health = stoi(input);

			getline(infile, input);
			mana = stoi(input);

			getline(infile, input);
			noOfSpulls = stoi(input);

			m = new Mage(name, race, level, health, mana);

			for (int i = 0; i < noOfSpulls; i++) {
				getline(infile, input);
				spellname = input;

				getline(infile, input);
				spelldamage = stoi(input);

				getline(infile, input);
				spellmana_cost = stoi(input);

				m->AddSpell(spellname, spelldamage, spellmana_cost);

			}

		}
	}

	infile.close();

	// b->Print();
	// m->Print();

	Game *game = new Game();
	// game->AddCharacter(b);
	// game->AddCharacter(m);

	int option = 0;
	do {
		cout << "Please choose an option: " << endl
			 << "1 - Add Player " << b->getName() << endl
			 << "2 - Add Player " << m->getName() << endl
			 << "3 - Next Turn" << endl
			 << "4 - Print All Characters" << endl
			 << "5 - Exit" << endl;

		cin.clear();
		cin >> option;

		cout << endl;

		switch(option) {
			case 1:
				game->AddCharacter(b);
				break;
			case 2:
				game->AddCharacter(m);
				break;
			case 3:
				game->NextTurn();
				break;
			case 4:
				game->Print();
				break;
			case 5:
				exit(0);
			default:
				cout << "Invalid Option!" << endl;
		}

		cout << endl;
	} while (option != 5);


/*
	string name = "Ram";
	string race = "Human";
	int level = 10, health = 100, stamina = 10;
	
	Barbarian b(name, race, level, health, stamina);
	Barbarian *pb = &b;
	string weaponname = "Sword";
	int weapondamage = 8, weaponstamina_cost = 9;

	pb->EquipWeapon("Sword", weapondamage, weaponstamina_cost);

	name = "Hari";
	race = "Human";
	level = 10, health = 50;
	int mana = 10;

	Mage m(name, race, level, health, mana);
	Mage *pm = &m;

	string spellname = "Fireball";
	int spelldamage = 6;
	int spellmana_cost = 7;
	pm->AddSpell(spellname, spelldamage, spellmana_cost);

	spellname = "Waterball";
	spelldamage = 5;
	spellmana_cost = 9;
	pm->AddSpell(spellname, spelldamage, spellmana_cost);

	spellname = "Fireball";
	spelldamage = 4;
	spellmana_cost = 8;
	pm->AddSpell(spellname, spelldamage, spellmana_cost);

	// b.Print();
	// m.Print();

	Game *game = new Game();
	
	game->AddCharacter(pb);
	game->AddCharacter(pm);

	Character c;
	Character *pc = pb;
	// pc = &c;
	pc->Print();
	pc = &b;
	pc->Print();
	
	// game->NextTurn();

	// game->Print();
*/
	return 0;
}