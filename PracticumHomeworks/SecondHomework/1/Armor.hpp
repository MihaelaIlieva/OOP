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

	enum ArmorType {
		cloth,
		leather,
		mail
	};

class Armor {
private:
	ArmorType type;
	int defense;
	vector<pair<string, double>> effects;
	vector<double> Gearscore;
public:
	Armor();
	Armor(ArmorType type,int defense,vector<pair<string, double>> effects,
		vector<double> Gearscore);
	void changeArmorType(ArmorType newType);
	ArmorType GetType();

	int GetDefense();
};
