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
#include "MagicCard.hpp"

MagicCard::MagicCard():Card()
{
    this->cardType = CardType::TRAP;
    this->typeOfCard = "MagicCard";
}

MagicCard::MagicCard(string name, string effect, CardType cardType,unsigned int rarity):Card(name,effect,rarity)
{
    this->cardType = cardType;
    this->typeOfCard = "MagicCard";
}

CardType MagicCard::getCardType() const
{
    return this->cardType;
}

Card* MagicCard::clone() const
{
    return new MagicCard(*this);
}
