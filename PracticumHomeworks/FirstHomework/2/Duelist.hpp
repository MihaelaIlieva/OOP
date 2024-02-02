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
#include "Deck.hpp"
class Duelist
{
private:
	const char* name;
	Deck deck;
public:
	Duelist(const char* name);
	Duelist(const char*  name, Deck deck);
	void AddMonsterCard(MonsterCard monster);
	void AddMagicCard(MagicCard magic);
	int CountOfMagicCards();
	int CountOfMonsterCards();
	void ChangeMonsterCard(int index, MonsterCard monster);
	void ChangeMagicCard(int index, MagicCard magic);
	void ChangeMagicCard(int index, const char name[26], const char effect[101], MagicCardType type);
	void ChangeMonsterCard(int index, const char name[26], int atackPoints, int defensePoints);
};

