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
#include "Deck.hpp"

void Deck::AddMonsterCard(MonsterCard monster)
{
	if (lastMonsterCardIndex != 20) {
		monsterCards[lastMonsterCardIndex] = monster;
		lastMonsterCardIndex++;
	}
}

void Deck::AddMagicCard(MagicCard magic)
{
	if (lastMagicCardIndex != 20) {
		magicCards[lastMagicCardIndex] = magic;
		lastMagicCardIndex++;
	}
}

int Deck::CountOfMagicCards()
{
	return (lastMagicCardIndex + 1);
}

int Deck::CountOfMonsterCards()
{
	return (lastMonsterCardIndex + 1);
}

// this method will only add a card if there is another card added on that index
void Deck::ChangeMonsterCard(int index, MonsterCard monster)
{	
	if (index<lastMonsterCardIndex) {
		monsterCards[index] = monster;;
	}
		
}

// this method will only add a card if there is another card added on that index
void Deck::ChangeMagicCard(int index, MagicCard magic)
{
	if (index<lastMagicCardIndex) {
		magicCards[index] = magic;
	}
		
}
// same as the upper one with the same name but with different parameters
// because of the examples given
void Deck::ChangeMonsterCard(int index, const char name[26],
	int atackPoints, int defensePoints)
{
	MonsterCard monsterCard(name, atackPoints, defensePoints);
	ChangeMonsterCard(index, monsterCard);
}
// same as the upper one with the same name but with different parameters
// because of the examples given
void Deck::ChangeMagicCard(int index, const char name[26],
	const char effect[101], MagicCardType type)
{
	MagicCard magicCard(name, effect, type);
	ChangeMagicCard(index, magicCard);
}