#include<iostream>
#include <string.h>
#include <typeinfo>
#include "mage.h"
#include "barbarian.h"

using namespace std;

Mage :: Mage() {
	;
}

Mage :: Mage(string name, string race, int level, int health, int mana) :
	Character(name, race, level, health), mana(mana) {
		numberOfSpells = 0;
	}

inline int Mage :: getMana() {
	return mana;
}

inline void Mage :: updateMana(int mana) {
	this->mana = mana;
}

int Mage :: AddSpell(string spell_name, int spell_damage, int mana_cost) {
	if (numberOfSpells < 10) {
		spell temp_spell = {spell_name, spell_damage, mana_cost};
		this->spells[numberOfSpells] = temp_spell;
		this->numberOfSpells++;
		return this->numberOfSpells;
	} else {
		cout << "Spell limits reached!" << endl;
		return 0;
	}
}

void Mage :: nextSpell() {
	if (this->active_Spell == this->numberOfSpells - 1) {
		this->active_Spell = 0;
	} else {
		this->active_Spell++;
	}
}

void Mage :: Attack(Character *target) {
	int currHealth = target->getHealth();
	currHealth = currHealth - (this->spells[this->active_Spell].damage);
	this->updateHealth(currHealth);

	if (this->numberOfSpells == 0) {
		cout << "Mage has no spells!" << endl;
	} else {
		cout << this->getName() << " attacked " << target->getName() << " with a " 
		 	 << this->spells[this->active_Spell].name << ", dealing " << this->spells[this->active_Spell].damage << " damage" << endl;
	}

	this->nextSpell();

	if ((this-> mana) > (this->spells[this->active_Spell].mana_cost)) {
		cout << "Insufficient mana points!" << endl;
	}
}

void Mage :: Print() {

	cout << "Spells: " << endl;
	for(int i = 0; i < numberOfSpells; i++) {
		cout << this->spells[i].name << endl;
	}
	cout << "---" << endl;
}

Mage :: ~Mage() {
	;
}