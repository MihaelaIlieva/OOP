#include "VendingMachine.hpp"

VendingMachine::VendingMachine()
{ 
	this->income = 0.0;
	this->drinks = new Drink[1];
	this->lastIndexInDrinks = 0;
}

VendingMachine::VendingMachine(const VendingMachine& from)
{
	this->income = from.income;
	for (size_t i = 0; i <= from.lastIndexInDrinks; i++)
	{
		this->drinks[i] = from.drinks[i];
	}
}

VendingMachine& VendingMachine::operator=(const VendingMachine& from)
{
	if (&from != this) {

		delete[] drinks;
		int size = from.lastIndexInDrinks+1;
		drinks = new Drink[size];
		for (size_t i = 0; i < size; i++)
		{
			drinks[i] = from.drinks[i];
		}

		this->income = from.income;
		this->lastIndexInDrinks = from.lastIndexInDrinks;
	}
	return *this;
}

bool VendingMachine::add_drink(const Drink& to_add)
{
	bool isThere = false;
	for (size_t i = 0; i < lastIndexInDrinks; i++)
	{
		if (strcmp(this->drinks[i].get_name(), to_add.get_name())==0) {
			isThere = true;
		}
	}
	if (isThere) {
		return false;
	}
	else {
		drinks[lastIndexInDrinks] = to_add;
		lastIndexInDrinks++;
		return true;
	}
}

int VendingMachine::buy_drink(const char* drink_name, const double money)
{
	for (size_t i = 0; i < lastIndexInDrinks; i++)
	{
		if (strcmp(this->drinks[i].get_name(), drink_name) == 0) {

			if (money >= this->drinks[i].get_price()) {
				this->income += money;
				for (size_t j = i; j < lastIndexInDrinks-1; j++)
				{
					this->drinks[j] = drinks[j + 1];
				}
				this->lastIndexInDrinks--;
				return 0;
			}
			else if (money < this->drinks[i].get_price()) {
				this->income += money;
				return 1;
			}
		}
	}
	return 2;
}

double VendingMachine::get_income() const
{
	return this->income;
}

VendingMachine::~VendingMachine()
{
	delete[] drinks;
}
