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

enum CardType {
	TRAP,
	SPELL,
	BUFF
};

class MagicCard: virtual public Card {
private:
	CardType cardType;
public:
	MagicCard();
	MagicCard(string name, string effect, CardType cardType);
	CardType getCardType() const;
};
