/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Mihaela Ilieva
* @idnumber 62550
* @task 1
* @compiler VC
*/
#pragma once
#include "Card.hpp"
class MonsterCard: virtual public Card {
private:
	unsigned int attackPoints;
	unsigned int defensePoints;
public:
	MonsterCard();
	MonsterCard(string name, string effect, unsigned int attackPoints, unsigned int defensePoints);
	unsigned int getAttackPoints() const;
	unsigned int getDefensePoints() const;
};
