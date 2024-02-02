/**
* Solution to homework assignment 4
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
	this->rarity = 0;
	this->typeOfCard = "none";
}

Card::Card(string name, string effect, unsigned int rarity)
{
	this->name = name;
	this->effect = effect;
	this->rarity = rarity;
	this->typeOfCard = "none";
}

string Card::getName() const
{
	return this->name;
}

string Card::getEffect() const
{
	return this->effect;
}

int Card::getRarity() const
{
	return this->rarity;
}

bool Card::operator>(const Card& other) const
{
	return (this->getRarity()>other.getRarity());
}

bool Card::operator<(const Card& other) const
{
	return (this->getRarity() < other.getRarity());
}
