//include the necessary header files
#include <iostream>
#include <string>
#include "barbarian.h"

using namespace std;

//implement constructors
Barbarian :: Barbarian(string name, string race, int level, int health, int stamina) :
	Character(name, race, level, health), stamina(stamina) {}

//implement getter functions
int Barbarian :: getStamina() const {
	return this->stamina;
}

//implement setter functions
void Barbarian :: setStamina(int stamina) {
	this->stamina = stamina;
}

//other funtion implementations
void Barbarian :: EquipWeapon(string name, int damage, int stamina_cost) {
	weapon temp_weapon;
	temp_weapon.name = name;
	temp_weapon.damage = damage;
	temp_weapon.stamina_cost = stamina_cost;
	this->active_weapon = temp_weapon;
}

void Barbarian :: Attack(Character * target) {
	int currHealth = target->getHealth();
	currHealth = currHealth - (this->active_weapon.damage);
	this->setHealth(currHealth);

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