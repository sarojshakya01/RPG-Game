#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;

class Character {
	private:
	string name, race;
	int level, health;

	public:
	Character();

	Character(string, string, int, int);

	string getName();

	string getRace();

	int getLevel();

	int getHealth();

	void updateName(string);

	void updateRace(string);

	void updateLevel(int);

	void updateHealth(int);

	virtual void Attack(Character *);

	virtual void Print();

	~Character();

};

#endif