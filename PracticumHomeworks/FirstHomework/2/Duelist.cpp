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
#include "Duelist.hpp"

Duelist::Duelist(const char* name)
{
	this->name = name;
}

Duelist::Duelist(const char* name, Deck deck)
{
	this->name = name;
	this->deck = deck;
}
// the two following methods add a certain card to the deck of same-type cards
void Duelist::AddMonsterCard(MonsterCard monster)
{
	this->deck.AddMonsterCard(monster);
}

void Duelist::AddMagicCard(MagicCard magic)
{
	this->deck.AddMagicCard(magic);
}
// the two following methods give the count of the certain type of cards
int Duelist::CountOfMagicCards()
{
	return this->deck.CountOfMagicCards();
}

int Duelist::CountOfMonsterCards()
{
	return this->deck.CountOfMonsterCards();
}
// the four following methods change a certain card
// but based on different parameters

void Duelist::ChangeMonsterCard(int index, MonsterCard monster)
{
	this->deck.ChangeMonsterCard(index, monster);
}

void Duelist::ChangeMagicCard(int index, MagicCard magic)
{
	this->deck.ChangeMagicCard(index, magic);
}

void Duelist::ChangeMagicCard(int index, const char name[26], const char effect[101], MagicCardType type)
{
	MagicCard magicCard(name, effect, type);
	ChangeMagicCard(index, magicCard);
}

void Duelist::ChangeMonsterCard(int index, const char name[26], int atackPoints, int defensePoints)
{
	MonsterCard monsterCard(name, atackPoints, defensePoints);
	ChangeMonsterCard(index, monsterCard);
}

