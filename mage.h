#ifndef MAGE_H
#define MAGE_H
#include "character.h"

using namespace std;

typedef struct spell {
	string name;
	int damage, mana_cost;
}spell;

class Mage : public Character {
	private:
	int mana, numberOfSpells, active_Spell;
	spell spells[10];

	public:
	Mage();
	Mage(string, string, int, int, int);

	int getMana();

	void updateMana(int);

	int AddSpell(string, int, int);

	void nextSpell();

	void Attack(Character *);

	void Print();

	~Mage();

};

#endif