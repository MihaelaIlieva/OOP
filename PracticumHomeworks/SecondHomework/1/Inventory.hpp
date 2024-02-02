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
template<class T>
class Inventory
{
public:
	T* container;

	Inventory(T* container)
	{
		this->container = container;
	}

	//friend std::ostream& operator<< (ostream& os, const T& dt);

	bool operator== (const T& a) 
	{
		if ((*container).Slots()==a.Slots())
		{
			return true;
		}
		else
		{
			false;
		}
	}

	bool operator!= (const T& a)
	{
		return !(*container == a);
	}


};

