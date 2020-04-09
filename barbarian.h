#ifndef BARBARIAN_H
#define BARBARIAN_H
#include "character.h"

using namespace std;

typedef struct weapon {
	string name;
	int damage, stamina_cost;
}weapon;

class Barbarian : public Character {
	private:
	int stamina;
	weapon active_weapon;

	public:
	Barbarian();

	Barbarian(string, string, int, int, int);

	int getStamina();

	int getDamage();

	void updateStamina(int);

	void EquipWeapon(string, int, int);

	void Attack(Character *);

	void Print();

	~Barbarian();

};

#endif