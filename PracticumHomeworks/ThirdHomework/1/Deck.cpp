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
#include "Deck.hpp"

Deck::Deck()
{
    this->name = "";
}

Deck::Deck(string name, vector<MonsterCard> monsterCards, vector<MagicCard> magicCards, vector<PendulumCard> pendulumCards)
{
    this->name = name;
    this->monsterCards = monsterCards;
    this->magicCards = magicCards;
    this->pendulumCards = pendulumCards;
}

string Deck::getDeckName() const
{
    return this->name;
}

int Deck::getMonsterCardsCount() const
{
    return this->monsterCards.size();
}

int Deck::getMagicCardsCount() const
{
    return this->magicCards.size();
}

int Deck::getPendulumCardsCount() const
{
    return this->pendulumCards.size();
}

void Deck::setDeckName(string name)
{
    this->name = name;
}

void Deck::addMonsterCard(MonsterCard newMonsterCard)
{
    this->monsterCards.push_back(newMonsterCard);
}

void Deck::addMagicCard(MagicCard newMagicCard)
{
    this->magicCards.push_back(newMagicCard);
}

void Deck::addPendulumCard(PendulumCard newPendulumCard)
{
    this->pendulumCards.push_back(newPendulumCard);
}

void Deck::changeMonsterCard(int index, MonsterCard newMonsterCard)
{
    this->monsterCards[index] = newMonsterCard;
}

void Deck::changeMagicCard(int index, MagicCard newMagicCard)
{
    this->magicCards[index] = newMagicCard;
}

void Deck::changePendulumCard(int index, PendulumCard newPendulumCard)
{
    this->pendulumCards[index] = newPendulumCard;
}

void Deck::ClearDeck()
{
    this->name = "";
    this->monsterCards.clear();
    this->magicCards.clear();
    this->pendulumCards.clear();
}
