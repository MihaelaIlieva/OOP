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
#include "Dates.hpp"

int DaysByMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

Dates::Dates()
{
	this->DD = 1;
	this->MM = 1;
	this->YYYY = 2000;
}

Dates::Dates(unsigned short day, unsigned short month, unsigned short year)
{
	this->DD = day;
	this->MM = month;
	SetYear(year);
}

// setting the month correctly (it will always be between 1 and 12) and changing the year if necessary
void Dates::SetMonth(unsigned short month) 
{
	this->MM = month;
	if (this->MM>12) {
		this->MM = month % 12;
		SetYear(this->YYYY * month / 12);
	}
	else if (this->MM == 0) {
		this->MM = 12;
		SetYear(this->YYYY -1);
	}
	else if (this->MM < 0) {
		this->MM = (-month) % 12;
		SetYear(this->YYYY * (-month) / 12);
	}
}
// setting the year and the correct number of days for February
void Dates::SetYear(unsigned short year) 
{
	this->YYYY = year;
	if (this->isLeapYear()) {
		DaysByMonth[1] = 29;
	}
	else {
		DaysByMonth[1] = 28;
	}
}
void Dates::addDays(int days)
{
	// when the days are more or equal to those in one year
	while (days-365>=0)
	{
		days -=365;
		if (this->isLeapYear() && this->MM < 2 ) {
			days--;
		}
		SetYear(this->YYYY+1);
		//if 29th February is in our scope
		if (this->isLeapYear() && this->MM>2 || (this->MM==2 && this->DD==29)) {
				days--;
		}
	}
	// when the new date won't be in the same month
	while (this->DD + days > DaysByMonth[this->MM-1])
	{
		days -= DaysByMonth[this->MM - 1];	
		SetMonth(this->MM + 1);
	}
	// when the date will finally be in the same month
	this->DD += days;
}

int Dates::daysToEvent(Dates& date)
{
	int days = 0;
	Dates dateToModify(this->DD, this->MM, this->YYYY);
	// if the date of event is after the current date
	if (dateToModify.isLaterThan(date)) {
		// equalising the years
		while (dateToModify.YYYY < date.YYYY)
		{
			days += 365;
			if (dateToModify.isLeapYear() && dateToModify.MM < 2) {
				days++;
			}
			dateToModify.SetYear(dateToModify.YYYY + 1);
			//if 29th February is in our scope
			if (dateToModify.isLeapYear() && dateToModify.MM > 2 ||
				(dateToModify.MM == 2 && dateToModify.DD == 29)) {
				days++;
			}
		}
		// equalising the months
		while (dateToModify.MM != date.MM)
		{
			if (dateToModify.MM > date.MM) {
				dateToModify.MM--;
				if (dateToModify.MM == 0) {
					dateToModify.MM = 12;
				}
				days -= DaysByMonth[dateToModify.MM - 1];
			}
			if (dateToModify.MM < date.MM) {
				days += DaysByMonth[dateToModify.MM - 1];
				dateToModify.MM++;
			}
		}
		// equalising the days
		if (dateToModify.DD > date.DD) {
			days -= dateToModify.DD - date.DD;
		}
		else {
			days += date.DD - dateToModify.DD;
		}
		return days;
	}
	else {
		return -1;
	}
}

void Dates::removeDays(int days)
{
	// if the days are more than those in a year
	while (days - 365 >= 0)
	{
		days -= 365;
		// removing one more day if the year is leap because of 29th February
		if (this->isLeapYear() && this->MM > 2 ) {
			days--;
		}
		SetYear(this->YYYY - 1);
		//if
		if ((this->isLeapYear() && this->MM < 2 )|| (this->MM == 2 && this->DD == 29)) {
			days--;
		}
	}
	// if we have to go a month back
	while (this->DD - days <= 0)
	{
		SetMonth(this->MM - 1);	
		days -= DaysByMonth[this->MM - 1];		
	}
	// finally when the days that we remove won't change the month
	this->DD -= days;
}

bool Dates::isLeapYear()
{
	if (this->YYYY % 4 == 0) {
		if (this->YYYY % 100 == 0) {
			if (this->YYYY % 400 == 0) {
				return true;
			}	
			else {
				return false;
			}	
		}
		else {
			return true;
		}	
	}
	else {
		return false;
	}	
}

int Dates::daysToChristmas()
{
	//if this year's Christmas hasn't passed
	Dates christmas(25, 12, this->YYYY);
	if (this->isLaterThan(christmas)) {
		return this->daysToEvent(christmas);
	}
	//if this year's Christmas has passed, we count the days to next year's Christmas
	else {
		Dates christmasNext(25, 12, this->YYYY + 1);
		return this->daysToEvent(christmasNext);
	}
}

int Dates::daysToNewYear()
{
	// shows the days left to the first day of the new year
	Dates newYear(1, 1, this->YYYY + 1);
	return this->daysToEvent(newYear);
}
//if the other date is later than ours, not the other way around
bool Dates::isLaterThan(Dates& otherDate)
{
	if ((otherDate.YYYY > YYYY)
		||(otherDate.YYYY==YYYY && otherDate.MM>MM)
		||(otherDate.YYYY==YYYY && otherDate.MM==MM && otherDate.DD>DD)) {
		return true;
	}
	return false;
}
// additional method for easier checking
void Dates::print()
{
	if (DD < 10 && MM < 10) {
		std::cout << "0" << DD << ".0" << MM << "." << YYYY<<std::endl;
	}
	else if (DD <10&&MM>=10) {
		std::cout << "0" << DD << "." << MM << "." << YYYY << std::endl;
	}
	else if (DD >= 10 && MM < 10) {
		std::cout << DD << ".0" << MM << "." << YYYY << std::endl;
	}
	else {
		std::cout << DD << "." << MM << "." << YYYY << std::endl;
	}
}