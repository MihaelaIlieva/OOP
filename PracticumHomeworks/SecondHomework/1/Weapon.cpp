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
#include "Weapon.hpp"

Weapon::Weapon():weaponScore(0)
{
	this->type = WeaponType::onehanded;
	this->kind = "";
	this->hitDamage.first = 0;
	this->hitDamage.second = 0;
	this->weaponScore = this->getWeaponScore();
}

void Weapon::changeWeaponKind(string newKind)
{
	this->kind = newKind;
}

WeaponType Weapon::GetWeaponType() { return type; }

void Weapon::changeWeaponType()
{
	if (this->type == WeaponType::onehanded) {
		this->type = WeaponType::twohanded;
	}
	else {
		this->type = WeaponType::onehanded;
	}
}

// checking if we already have this effect and if we do
// we only change its power if its bigger than the one we have
// if there is no 
void Weapon::addEffect(pair<string, double> newEffect)
{
	bool alreadyAdded = false;
	for (int i = 0; i < this->effects.size(); i++) {
		if (this->effects[i].first == newEffect.first&&
			this->effects[i].second == newEffect.second) {
			alreadyAdded = true;
		}
		else if (this->effects[i].first == newEffect.first &&
			this->effects[i].second < newEffect.second) {
			this->effects[i].second = newEffect.second;
			alreadyAdded = true;
		}
	}
	if (alreadyAdded == false) {
		this->effects.push_back(newEffect);
	}
	this->weaponScore = this->getWeaponScore();
}

void Weapon::removeEffect(pair<string, double> effect)
{
	bool alreadyAdded = false;
	for (int i = 0; i < this->effects.size(); i++) {
		if (this->effects[i].first == effect.first &&
			this->effects[i].second == effect.second) {
			this->effects.erase(this->effects.begin() + i);
		}
	}
	this->weaponScore = this->getWeaponScore();
}

double Weapon::getWeaponScore()
{
	double coefic = 0.0;
	double sumOfEffects = 0.0;
	if (this->type == WeaponType::onehanded) {
		coefic = 0.75;
	}
	else {
		coefic = 1.5;
	}
	for (int i = 0; i < this->effects.size(); i++) {
		sumOfEffects += this->effects[i].second ;
	}
	return ((((this->hitDamage.first + this->hitDamage.second) / 2) + sumOfEffects)*coefic);
}

void Weapon::changeEffectPower(pair<string, double> effect, double newPower)
{
	for (int i = 0; i < this->effects.size(); i++) {
		if (this->effects[i].first == effect.first &&
			this->effects[i].second == effect.second) {
			this->effects[i].second = newPower;
		}	
	}
	this->weaponScore = this->getWeaponScore();
}
