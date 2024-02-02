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
#include <vector>
template <class T>
class Backpack
{
	const int MAX_SLOTS = 16;
	int SlotsTaken = 0;
public:
	std::vector<T> items;

	Backpack() {}
	int Slots() 
	{
		return SlotsTaken;
	}
	bool isEmpty()
	{
		if (items.size() == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isFull() {

		if (items.size() != 16) {
			return false;
		}
		else {
			return true;
		}
	}
	void clear() {
		items.clear();
	}
	void addToBackpack(T item) {

		items.push_back(item);
			SlotsTaken+=this->items.back().Slots();
	}
	void removeFromBackpack(int index) {
		auto nth = this->items.begin() + index;
		if (index==0) {
			auto nth = this->items.begin();
		}
		SlotsTaken -= nth->Slots();
		items.erase(nth);	
	}
	T getBackpackItem(int index) { 
		return items[index];
	}
	int getMaxSlots() { 
		return SlotsTaken;
	}
};




	

	