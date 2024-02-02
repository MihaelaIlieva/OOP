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
#include "Card.hpp"

char* const Card::GetName()
{
	return name;
}
Card::Card()
{

}
Card::Card(const char name[26])
{
	strcpy_s(this->name, name);
}
