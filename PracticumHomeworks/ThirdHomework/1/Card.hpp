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
#include <iostream>

using namespace std;

class Card {
private:
	string name;
	string effect;
public:
	Card();
	Card(string name, string effect);
	string getName() const;
	string getEffect() const;
};
