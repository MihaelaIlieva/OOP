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
#include "MagicCard.hpp"

//shows the effect of the card
char* const MagicCard::GetEffect()
{
	return effect;
}
// the default type that I chose
MagicCard::MagicCard()
{
	this->type = MagicCardType::trap;
}

MagicCard::MagicCard(const char name[26], const char effect[101], MagicCardType type) :Card(name)
{
	strcpy_s(this->effect, effect);
	this->type = type;
}
