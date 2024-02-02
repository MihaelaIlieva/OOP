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
#include <iostream>

using namespace std;

class Card {
protected:
	string name;
	string effect;
	unsigned int rarity;
public:
	Card();
	Card(string name, string effect, unsigned int rarity);
	string getName() const;
	string getEffect() const;
	int getRarity() const;

	string typeOfCard;

	virtual Card* clone()const = 0;
	virtual ~Card() = default;
	virtual bool operator>(const Card& other) const;
	virtual bool operator<(const Card& other) const;
};
