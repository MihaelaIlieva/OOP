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
#pragma once
#include "Card.hpp"
class MonsterCard : Card
{
	unsigned int attackPoints;
	unsigned int defensePoints;
public:
	unsigned int GetAttackPoints();
	unsigned int GetDefensePoints();
	MonsterCard();
	MonsterCard(const char name[26], unsigned int attackPoints,
		unsigned int defensePoints);
};