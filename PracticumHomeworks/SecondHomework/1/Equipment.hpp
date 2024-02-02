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
#include "Weapon.hpp"

template <class T>
class Equipment
{
	T* equipmentArray;
	int slots;
	int currentEquipmentIndex;
public:
	Equipment():slots(24),currentEquipmentIndex(0) {
		equipmentArray = new T[slots];
	}

	bool isEmpty() { return currentEquipmentIndex == 0; }
	bool isFull() { return currentEquipmentIndex + 1 == slots; }
	void clear() { currentEquipmentIndex == 0; equipmentArray == nullptr; }

	void addEquipment(T equipmentToAdd);
	void removeEquipment(int index);
	int getMaxSlots() { return slots; }
	T getEquipment(int index) { return equipmentArray[currentEquipmentIndex]; }
	T getBestEquipment();

	
};

