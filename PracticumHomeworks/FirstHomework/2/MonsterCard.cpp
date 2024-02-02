/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Mihaela Ilieva
* @idnumber 62550
* @task 2
* @compiler VC
*/
#include "MonsterCard.hpp"

unsigned int MonsterCard::GetAttackPoints()
{
	return attackPoints;
}

unsigned int MonsterCard::GetDefensePoints()
{
	return defensePoints;
}

MonsterCard::MonsterCard()
{
	this->attackPoints = 0;
	this->defensePoints = 0;
}

MonsterCard::MonsterCard(const char name[26], unsigned int attackPoints, 
	unsigned int defensePoints) :Card(name)
{
	this->attackPoints = attackPoints;
	this->defensePoints = defensePoints;

}