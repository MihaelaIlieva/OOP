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
#include "PendulumCard.hpp"

PendulumCard::PendulumCard():Card(),MonsterCard(),MagicCard()
{
    this->pendulumScale = MIN_PENDULUM_SCALE_SCORE;
}

PendulumCard::PendulumCard(string name, string effect, unsigned int attackPoints, unsigned int defensePoints, unsigned int pendulumScale,CardType cardType): Card(name,effect), MonsterCard(name,effect,attackPoints,defensePoints),MagicCard(name,effect,cardType)
{
    this->pendulumScale = pendulumScale;
}

unsigned int PendulumCard::getPendulumScale() const
{
    return this->pendulumScale;
}
