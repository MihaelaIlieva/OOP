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
#include "Money.hpp"

Money::Money() { this->gold = 0, this->silver = 0; }

Money::Money(int gold, int silver)
{
	if (silver > 99) {
		gold += silver / 100;
		silver = silver % 100;
	}
	this->gold = gold;
	this->silver = silver;
}


int Money::Slots() { return 0; }

void Money::operator= (const Money& other) {
	this->gold = other.gold;
	this->silver = other.silver;
}

int Money::GetGold() { return gold; }
int Money::GetSilver() { return silver; }
