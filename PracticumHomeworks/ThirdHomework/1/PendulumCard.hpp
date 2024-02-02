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
#include "MonsterCard.hpp"
#include "MagicCard.hpp"

const int MIN_PENDULUM_SCALE_SCORE = 1;
const int MAX_PENDULUM_SCALE_SCORE = 13;

class PendulumCard:public MonsterCard, public MagicCard {
private:
	unsigned int pendulumScale;
public:
	PendulumCard();
	PendulumCard(string name,string effect,unsigned int attackPoints, unsigned int defensePoints, unsigned int pendulumScale,CardType cardType);
	unsigned int getPendulumScale() const;
};
