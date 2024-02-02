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
#include <cstring>

using namespace std;

class Card {
	char name[26] = {0};
public:
	char* const GetName();
	Card();
	Card(const char name[26]);
};
