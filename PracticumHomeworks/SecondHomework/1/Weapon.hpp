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
using namespace std;

enum WeaponType {
	onehanded=1,
	twohanded=2
};

class Weapon {
private:
	WeaponType type;
	string kind;
	pair<double, double> hitDamage;
	vector<pair<string, double>> effects;
	double weaponScore;
public:
	Weapon();
	WeaponType GetWeaponType();
	Weapon(WeaponType type,string kind,pair<double, double> hitDamage,
		vector<pair<string, double>> effects);
	void changeWeaponKind(string newKind);
	void changeWeaponType();
	void addEffect(pair<string, double> newEffect);
	void removeEffect(pair<string, double> effect);
	void changeEffectPower(pair<string, double> effect, double newPower);
	double getWeaponScore();

	WeaponType GetType() { return type; }
	string Kind() { return kind; }
	double GetScore() { return weaponScore; }
	std::pair<double, double> GetPairHitDamage() { return hitDamage; }



};
