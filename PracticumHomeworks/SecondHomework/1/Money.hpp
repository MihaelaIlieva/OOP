/**
* Solution to homework assignment 2
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
#include <string>
#include <vector>
using namespace std;

class Money {
private:
	int gold;
	int silver;
public:
	Money();
	Money(int gold, int silver);
	Money operator+ (const Money& other);
	Money operator- (const Money& other);
	void operator= (const Money& other);
	int GetGold();
	int GetSilver();
	int Slots();
};
