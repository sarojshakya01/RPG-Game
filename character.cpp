//include the necessary header files
#include <iostream>
#include <string>
#include "character.h"

using namespace std;

//implement constructors
Character :: Character(string name, string race, int level, int health) {
	this->name = name;
	this->race = race;
	this->level = level;
	this->health = health;
}


//implement getter functions
string Character :: getName() const {
	return name;
}

string Character :: getRace() const {
	return race;
}

int Character :: getLevel() const {
	return level;
}

int Character :: getHealth() const {
	return health;
}


//implement setter functions
void Character :: setName(string name) {
	this->name = name;
}

void Character :: setRace(string race) {
	this->race = race;
}

void Character :: setLevel(int leve) {
	this->level = leve;
}

void Character :: setHealth(int health) {
	this->health = health;
}

//implement Print function
void Character :: Print() {
	cout << "Character Status:" << endl;
	cout << "Name: " << this->name << endl;
	cout << "Race: " << this->race << endl;
	cout << "Level: " << this->level << endl;
	cout << "Health: " << this->health << endl;
}