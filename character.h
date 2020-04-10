#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;

class Character {
private:
	string name;
	string race;
	int level;
	int health;

public:
	//constructors
	Character(string, string, int, int);

	//getter functions
	string getName() const;
	string getRace() const;
	int getLevel() const;
	int getHealth() const;

	//setter functions
	void setName(string);
	void setRace(string);
	void setLevel(int);
	void setHealth(int);

	//other functions
	virtual void Attack(Character *) = 0;
	virtual void Print();
};

#endif