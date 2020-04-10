#ifndef MAGE_H
#define MAGE_H
#include "character.h"

using namespace std;

struct spell {
	string name;
	int damage;
	int mana_cost;
};

class Mage : public Character {
private:
	spell spells[10];
	int numberOfSpells = 0;
	int mana = 100;
	int active_Spell = 0;

public:
	//constructors
	Mage(string, string, int, int, int);

	//getters
	int getMana() const;

	//setters
	void setMana(int);

	//other functions
	int AddSpell(string, int, int);
	void nextSpell();
	void Attack(Character *);
	void Print();
};

#endif