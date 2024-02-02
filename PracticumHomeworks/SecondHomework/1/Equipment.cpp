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
#include "Equipment.hpp"

template<>
	void Equipment<Weapon>::addEquipment(Weapon equipmentToAdd){
		if (!isFull()) {
			this->equipmentArray[currentEquipmentIndex]
				= equipmentToAdd;
			this->currentEquipmentIndex += equipmentToAdd.GetWeaponType();
		}
	}
template<class T>
	void Equipment<T>::addEquipment(T equipmentToAdd)
	{
		if (!isFull()) {
			this->equipmentArray[currentEquipmentIndex]
				= equipmentToAdd;
			this->currentEquipmentIndex++;
		}
	}
	template<class T>
	void Equipment<T>::removeEquipment(int index)
	{
		for (size_t i = 0; i < length; i++)
		{

		}
	}

	template<class T>
	T Equipment<T>::getBestEquipment()
	{
		int indexGreatest = 0;
		for (size_t i = 0; i <= this->currentEquipmentIndex; i++)
		{
			if (this->equipmentArray[currentEquipmentIndex].Greatest)
			{

			}
		}
	}