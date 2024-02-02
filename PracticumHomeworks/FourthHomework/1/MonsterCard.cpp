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
#include "MonsterCard.hpp"

MonsterCard::MonsterCard():Card()
{
    this->attackPoints = 0;
    this->defensePoints = 0;
    this->typeOfCard = "MonsterCard";
}

MonsterCard::MonsterCard(string name, string effect, unsigned int attackPoints, unsigned int defensePoints,unsigned int rarity):Card(name,effect,rarity)
{
    this->attackPoints = attackPoints;
    this->defensePoints = defensePoints;
    this->typeOfCard = "MonsterCard";
}

unsigned int MonsterCard::getAttackPoints() const
{
    return this->attackPoints;
}

unsigned int MonsterCard::getDefensePoints() const
{
    return this->defensePoints;
}

Card* MonsterCard::clone() const
{
    return new MonsterCard(*this);
}