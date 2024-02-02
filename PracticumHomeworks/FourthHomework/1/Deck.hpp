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
#pragma once
#include "Card.hpp"
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "PendulumCard.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Deck {
protected:
	string name;
	
public:
	
	vector<Card*> cardsInDeck;

	Deck();
	Deck(string name, vector<Card*> cards);
	string getDeckName() const;
	int getMonsterCardsCount() const;
	int getMagicCardsCount() const;
	int getPendulumCardsCount() const;
	int getCardsInDeckCount() const;

	void addCardToDeck(Card* cardToAdd);
	void changeCardByIndex(int index, Card* newCard);
	void shuffle();

	void setDeckName(string name);
	void ClearDeck();

	void copyOther(const Deck& other);
	Deck(const Deck& other);
	Deck& operator=(const Deck& other);
	~Deck();
};
