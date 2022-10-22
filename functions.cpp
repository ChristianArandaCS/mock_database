#include"creature_header.h"

// sets all variables
void Creature::setCreature(int creature_strength, int creature_health, string creature_id)
{
	strength = creature_strength;
	health = creature_health;
	id = creature_id;
}

// creating getFunctions
int Creature::getHealth()const
{
	return health;
}

int Creature::getStrength()const
{
	return strength;
}

string Creature::getId()const
{
	return id;
}

// pass by pointer function
int Creature::setDamage(int *strength)
{
	return (rand() % *strength) + 1;
}

string Creature::to_sting(string *id, int *health, int *strength)const
{
	ostringstream s1;
	s1 << setw(15) << *id << setw(10) << *health << setw(10) << *strength;
	return s1.str();
}

string Creature::search_function(string* id, int* health, int* strength, int* damage)const
{
	ostringstream s1;
	s1 << setw(15) << *id << setw(10) << *health << setw(10) << *strength << setw(10) << *damage;
	return s1.str();
}

