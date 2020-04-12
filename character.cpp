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
void Character :: SetName(string name) {
	this->name = name;
}

void Character :: SetRace(string race) {
	this->race = race;
}

void Character :: SetLevel(int leve) {
	this->level = leve;
}

void Character :: SetHealth(int health) {
	this->health = health;
}

//implement Print function
void Character :: Print() {
	cout << "Character Status:" << endl;
	cout << "Name: " << this->name << endl;
	cout << "Race: " << this->race << endl;
	cout << "Level: " << this->level << endl;
	cout << "Health: " << this->health << endl;
	cout << "---" << endl;
}