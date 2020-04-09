#include <iostream>
#include <string.h>
#include "character.h"

using namespace std;

Character :: Character() {
	;
}

Character :: Character(string name, string race, int level, int health) {
	this->name = name;
	this->race = race;
	this->level = level;
	this->health = health;
}

string Character :: getName() {
	return name;
}

string Character :: getRace() {
	return race;
}

int Character :: getLevel() {
	return level;
}

int Character :: getHealth() {
	return health;
}

void Character :: updateName(string name) {
	this->name = name;
}

void Character :: updateRace(string race) {
	this->race = race;
}

void Character :: updateLevel(int leve) {
	this->level = leve;
}

void Character :: updateHealth(int health) {
	this->health = health;
}

void Character :: Attack(Character *){

}

void Character :: Print() {
	cout << "Character Status:" << endl;
	cout << "Name: " << this->name << endl;
	cout << "Race: " << this->race << endl;
	cout << "Level: " << this->level << endl;
	cout << "Health: " << this->health << endl;
}

Character :: ~Character() {
	;
}