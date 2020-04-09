#include<iostream>
#include <string.h>
#include "barbarian.h"

using namespace std;

Barbarian :: Barbarian() {
	;
}

Barbarian :: Barbarian(string name, string race, int level, int health, int stamina) :
	Character(name, race, level, health), stamina(stamina) {}

inline int Barbarian :: getStamina() {
	return this->stamina;
}

inline int Barbarian :: getDamage() {
	return this->active_weapon.damage;
}

inline void Barbarian :: updateStamina(int stamina) {
	this->stamina = stamina;
}

void Barbarian :: EquipWeapon(string name, int damage, int stamina_cost) {
	weapon temp_weapon = {name, damage, stamina_cost};
	this->active_weapon = temp_weapon;
}

void Barbarian :: Attack(Character * target) {
	int currHealth = target->getHealth();
	currHealth = currHealth-this->active_weapon.damage;
	this->updateHealth(currHealth);

	if (this->active_weapon.name == ""){
		cout << "Barbarian has no weapon!" << endl;
	} else {
		cout << this->getName() << " attacked " << target->getName() << " with a " 
		 	 << this->active_weapon.name << ", dealing " << this->active_weapon.damage << " damage" << endl;
	}

	if ((this-> stamina) > (this->active_weapon.stamina_cost)) {
		cout << "Insufficient stamina points!" << endl;
	}
}

void Barbarian :: Print() {
	cout << "Weapon: " << this->active_weapon.name << endl;
	cout << "---" << endl;
}

Barbarian :: ~Barbarian() {
	;
}