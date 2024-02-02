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
#include <string>
#include <vector>


enum MaterialType {
	herbs,
	ores,
	cloths,
	essence
};
class Materials {
private:
	const int MAX_QUANTITY_ESSENCE = 10;
	const int MAX_QUANTITY_OTHERS = 20;
	vector<pair<MaterialType, int>> quantityOfMaterials;
	

	
public:

	void operator= (const Materials& materials) 
	{
		this->quantityOfMaterials = materials.quantityOfMaterials;
	}

	int SlotsOccupiedPerMaterial(MaterialType mt) 
	{
		if (MaterialType::essence==mt)
		{
			return this->quantityOfMaterials.at(mt).second / MAX_QUANTITY_ESSENCE;
		}
		else
		{
			return this->quantityOfMaterials.at(mt).second / MAX_QUANTITY_OTHERS;
		}
	}

	int Slots() 
	{
		int maxSlotsTaken = 1;
		for (size_t i = 0; i < 4; i++)
		{
			if (SlotsOccupiedPerMaterial((MaterialType)i)>maxSlotsTaken)
			{
				maxSlotsTaken = SlotsOccupiedPerMaterial((MaterialType)i);
			}
		}
		return maxSlotsTaken;
		
	}
	
	void SetQuantity(MaterialType mt, int quantity)
	{
		this->quantityOfMaterials[mt].second = quantity;
	}

	

	int GetQuantity(MaterialType mt)
	{
		
		return this->quantityOfMaterials.at(mt).second;
	}
	Materials(vector<pair<MaterialType, int>> quantites):Materials()
	{
		for (int i = 0; i < 4; i++)
		{
			SetQuantity(quantites.at(i).first, quantites.at(i).second);
		}
	}
	Materials()
	{
		for (int i = 0; i < 4; i++)
		{
			std::pair<MaterialType, int>  a((MaterialType)i, 0);
			this->quantityOfMaterials.insert(quantityOfMaterials.end(), a);
		}
	}

	/*Materials operator+ (const Materials& other) 
	{
		Materials toReturn(this->quantityOfMaterials);
		for (size_t i = 0; i < 4; i++)
		{
			toReturn.SetQuantity(
				toReturn.quantityOfMaterials.at(i).first, 
				toReturn.quantityOfMaterials.at(i).second + other.quantityOfMaterials.at(i).second);
		}
		return toReturn;
	}*/

	/*Materials operator- (const Materials& other)
	{
		Materials toReturn(this->quantityOfMaterials);
		for (size_t i = 0; i < 4; i++)
		{
			SetQuantity(
				toReturn.quantityOfMaterials.at(i).first,
				toReturn.quantityOfMaterials.at(i).second - other.quantityOfMaterials.at(i).second);
		}
	}*/

};
