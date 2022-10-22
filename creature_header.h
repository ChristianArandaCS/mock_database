#ifndef creature_H
#define creature_H

#include<iomanip>
#include <sstream>
#include<iostream>

using namespace std;

class Creature {
private:
	int strength;
	int health;
	string user_search;
	string id;
public:
	// function to set all character variables
	void setCreature(int creature_strength, int creature_health, string creature_id);

	// setting up getFunctions
	int getHealth()const;
	int getStrength()const;
	string getId()const;
	//
	int setDamage(int *strength);
	string to_sting(string* id, int* health, int* strength)const;
	string search_function(string* id, int* health, int* strength, int* damage)const;

};
#endif