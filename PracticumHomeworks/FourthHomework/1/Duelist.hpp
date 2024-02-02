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
#include "Deck.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Duelist {
protected:
	string name;
	Deck deck;
public:
	Duelist();
	Duelist(string name);
	Duelist(string name, Deck deck);

	string getName() const;
	Deck* getDeck();
	bool saveDeck(string fileName);
	bool updateDeck(string fileName);

	void duel(const Duelist& other);
};