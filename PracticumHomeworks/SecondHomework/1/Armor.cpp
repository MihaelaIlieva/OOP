/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Mihaela Ilieva
* @idnumber 62550
* @task 1
* @compiler VC
*/
#include "Armor.hpp"

Armor::Armor()
{
	this->type = ArmorType::cloth;
	this->defense = 0;
}

Armor::Armor(ArmorType type, int defense, vector<pair<string, double>> effects, vector<double> Gearscore)
{
	this->type = type;
	this->defense = defense;
	this->effects = effects;
	this->Gearscore = Gearscore;
}

void Armor::changeArmorType(ArmorType newType)
{
	this->type = newType;
}
ArmorType Armor::GetType() { return type; }

int Armor::GetDefense() { return defense; }
