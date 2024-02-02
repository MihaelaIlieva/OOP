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
#include "Card.hpp"

Card::Card()
{
	this->name = "";
	this->effect = "";
}

Card::Card(string name, string effect)
{
	this->name = name;
	this->effect = effect;
}

string Card::getName() const
{
	return this->name;
}

string Card::getEffect() const
{
	return this->effect;
}
