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
#include "Inventory.hpp"
#include "Equipment.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Backpack.hpp"
#include "Money.hpp"
#include "Materials.hpp"

template <class T>
std::ostream& operator<< (ostream& os, const T& dt) 
{

}

//template<>
// std::ostream& Inventory<Equipment<Weapon>>::operator<< (ostream& os, const Inventory<Equipment<Weapon>>& dt)
//{
//	//type,kind,hitDamage, weaponScore ,effect
//	for (size_t i = 0; i < this->container.getMaxSlots(); i++)
//	{
//		os << "Type: "
//			<< this->container.getEquipment(i).GetType() << "Handed"
//			<< " Kind: " << this->container.getEquipment(i).Kind()
//			<< " HitDamage: Lower" << this->container.getEquipment(i).GetPairHitDamage().first
//			<< " HitDamage: Upper" << this->container.getEquipment(i).GetPairHitDamage().second
//			<< "WeaponScore: " << this->container.getEquipment(i).getWeaponScore()
//			<< std::endl;
//
//	}
//	
//
//}
//template<>
//std::ostream& Inventory<Equipment<Armor>>::operator<< (ostream& os, const Inventory<Equipment<Armor>>& dt)
//{
//	//type, defence, effects, gearScore
//	for (size_t i = 0; i < this->container.getMaxSlots(); i++)
//	{
//		os << "Type: " << this->container.getEquipment(i).GetType()
//			<< " Defence: " << this->container.getEquipment(i).GetDefense()<<
//		std::endl;
//
//	}
//
//}
//template<>
//std::ostream& Inventory<Backpack<Money>>::operator<< (ostream& os, const Inventory<Backpack<Money>>& dt)
//{
//	//money, gold ,silver , slots
//	for (size_t i = 0; i < this->container.getMaxSlots(); i++)
//	{
//		os << " Gold: " << this->container.getBackpackItem(i).GetGold()
//			<< " Silver: " << this->container.getBackpackItem(i).GetSilver()
//			<< std::endl;
//	}
//
//}
//template<>
//std::ostream& Inventory<Backpack<Materials>>::operator<< (ostream& os, const Inventory<Backpack<Materials>>& dt)
//{
//	// materials , slots
//	for (size_t i = 0; i < this->container.getMaxSlots(); i++)
//	{
//		
//		os
//			<< " Slots " << this->container.getMaxSlots()
//			<< std::endl;
//	}
//
//	
//}
//
