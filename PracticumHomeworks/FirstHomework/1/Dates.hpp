/**
* Solution to homework assignment 1
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

class Dates {
private:
	unsigned short DD;
	unsigned short MM;
	unsigned short YYYY;
public:
	Dates();
	Dates(unsigned short day, unsigned short month, unsigned short year);
	void addDays(int days);
	void removeDays(int days);
	bool isLeapYear();
	int daysToChristmas();
	int daysToNewYear();
	int daysToEvent(Dates& ourEvent);
	bool isLaterThan(Dates& otherDate);

	void SetYear(unsigned short year);
	void SetMonth(unsigned short month);
	void print();
};
