#include "drink.hpp"
Drink::Drink()
{
	int nameLength = strlen(defaultName);
	this->name = new char[nameLength + 1];
	strcpy(this->name, defaultName);

	this->calories = 0;
	this->quantity = 0.0;
	this->price = 0.0;
}

Drink::Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price)
{
	int nameLength = strlen(init_name);
	this->name = new char[nameLength + 1];
	strcpy(this->name, init_name);

	this->calories = init_calories;
	this->quantity = init_quantity;
	this->price = init_price;
}

Drink::Drink(const Drink& other)
{
	int nameLength = strlen(other.name);
	this->name = new char[nameLength + 1];
	strcpy(this->name,other.name);

	this->calories = other.calories;
	this->quantity = other.quantity;
	this->price = other.price;
}

Drink& Drink::operator=(const Drink& other)
{
	if (&other != this) {

		set_name(other.name);
		this->calories = other.calories;
		this->quantity = other.quantity;
		this->price = other.price;
	}
	return *this;
}

const char* Drink::get_name() const
{
	return this->name;
}

int Drink::get_calories() const
{
	return this->calories;
}

double Drink::get_quantity() const
{
	return this->quantity;
}

double Drink::get_price() const
{
	return this->price;
}

void Drink::set_name(const char* new_name)
{	
	delete[] name;
	int nameLength = strlen(new_name);
	this->name = new char[nameLength + 1];
	strcpy(this->name, new_name);	
}

Drink::~Drink()
{
	delete[] name;
}
