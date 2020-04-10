#ifndef BARBARIAN_H
#define BARBARIAN_H
#include "character.h"

using namespace std;

struct weapon {
	string name = "";
	int damage = 0;
	int stamina_cost = 0;
};

class Barbarian : public Character {
private:
	weapon active_weapon;
	int stamina = 100;

public:
	//constructors
	Barbarian(string, string, int, int, int);

	//getters
	int getStamina() const;

	//setters
	void setStamina(int);

	//other functions
	void EquipWeapon(string, int, int);
	void Attack(Character *);
	void Print();
};

#endif