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
#include "PendulumCard.hpp"
#include <iostream>
#include <vector>
using namespace std;
class Deck {
private:
	string name;
	
public:
	vector<MonsterCard> monsterCards;
	vector<MagicCard> magicCards;
	vector<PendulumCard> pendulumCards;
	Deck();
	Deck(string name, vector<MonsterCard> monsterCards,
		vector<MagicCard> magicCards,
		vector<PendulumCard> pendulumCards);
	string getDeckName() const;
	int getMonsterCardsCount() const;
	int getMagicCardsCount() const;
	int getPendulumCardsCount() const;
	void setDeckName(string name);
	void addMonsterCard(MonsterCard newMonsterCard);
	void addMagicCard(MagicCard newMagicCard);
	void addPendulumCard(PendulumCard newPendulumCard);
	void changeMonsterCard(int index, MonsterCard newMonsterCard);
	void changeMagicCard(int index, MagicCard newMagicCard);
	void changePendulumCard(int index, PendulumCard newPendulumCard);
	void ClearDeck();
};
