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
#include "Card.hpp"
enum class MagicCardType
{
	trap, 
	buff, 
	spell
};

class MagicCard : Card
{
	char effect[101] = {0};
	MagicCardType type;
public:
	char* const GetEffect();
	MagicCard();
	MagicCard(const char name[26], const char effect[101],MagicCardType type);
};