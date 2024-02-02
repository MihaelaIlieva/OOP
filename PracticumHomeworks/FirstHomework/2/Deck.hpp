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
#pragma once
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
class Deck
{
private:
	MonsterCard monsterCards[20];
	int lastMonsterCardIndex = 0;
	MagicCard magicCards[20];
	int lastMagicCardIndex = 0;
public:	
	void AddMonsterCard(MonsterCard monster);
	void AddMagicCard(MagicCard magic);
	int CountOfMagicCards();
	int CountOfMonsterCards();
	void ChangeMonsterCard(int index, MonsterCard monster);
	void ChangeMagicCard(int index, MagicCard magic);
	void ChangeMagicCard(int index, const char name[26], const char effect[101], MagicCardType type);
	void ChangeMonsterCard(int index, const char name[26], int atackPoints, int defensePoints);
};

