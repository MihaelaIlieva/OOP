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
#include "PendulumCard.hpp"

PendulumCard::PendulumCard():Card(),MonsterCard(),MagicCard()
{
    this->pendulumScale = MIN_PENDULUM_SCALE_SCORE;
    this->typeOfCard = "PendulumCard";
}

PendulumCard::PendulumCard(string name, string effect, unsigned int attackPoints, unsigned int defensePoints, unsigned int pendulumScale,CardType cardType,unsigned int rarity): Card(name,effect,rarity), MonsterCard(name,effect,attackPoints,defensePoints,rarity),MagicCard(name,effect,cardType,rarity)
{
    this->pendulumScale = pendulumScale;
    this->typeOfCard = "PendulumCard";
}

unsigned int PendulumCard::getPendulumScale() const
{
    return this->pendulumScale;
}

Card* PendulumCard::clone() const
{
    return new PendulumCard(*this);
}