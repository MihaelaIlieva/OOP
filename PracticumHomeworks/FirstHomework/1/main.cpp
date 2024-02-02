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
using namespace std;

int main() {
	Dates d1(31, 3, 2014); // 31.03.2014
	Dates d2; // 01.01.2000
	// the following were used for testing the program
	cout << d1.daysToChristmas()<<endl;
	cout << d1.daysToNewYear()<<endl;
	cout << d1.isLeapYear()<<endl;
	cout << d1.isLaterThan(d2)<<endl;
	d1.print();
	d1.addDays(1);
	d1.print();
	d1.removeDays(1);
	d1.print();
	d2.print();

	return 0;
}