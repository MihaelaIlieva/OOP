#include <iostream>
#include <vector>
#include <string>
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Equipment.hpp"
#include "Backpack.hpp"
#include "Money.hpp"
#include "Materials.hpp"
#include "Inventory.hpp"
using namespace std;

int main() {

	Weapon wepon;
	wepon.addEffect(std::pair<string, double>("fire", 5.0));
	wepon.addEffect(std::pair<string, double>("water", 6.0));
	wepon.addEffect(std::pair<string, double>("earth", 12.0));
	wepon.addEffect(std::pair<string, double>("bb", 5.0));
	Weapon wepon1;
	Weapon wepon2;

	Armor armor;

	Equipment<Weapon> weaponE;
	weaponE.addEquipment(wepon);
	weaponE.addEquipment(wepon1);
	weaponE.addEquipment(wepon2);

	Money money(12, 12);
	Backpack<Money> bp;
	bp.addToBackpack(money);
	bp.addToBackpack(money);

	std::vector<std::pair<MaterialType, int>> a{
		{MaterialType::cloths,3} ,
		{MaterialType::herbs,3} ,
		{MaterialType::essence,3} ,
		{MaterialType::ores,3}
	};


		std::vector<std::pair<MaterialType, int>> b{
		{MaterialType::cloths,56} ,
		{MaterialType::herbs,3} ,
		{MaterialType::essence,56} ,
		{MaterialType::ores,3}
	};
	Materials mtA(a);
	Materials mtB(b);
	Backpack<Materials> bpM;
	bpM.addToBackpack(mtA);
	bpM.addToBackpack(mtB);

	bpM.removeFromBackpack(0);

	
	Inventory<Equipment<Weapon>> w (&weaponE);
	Inventory<Backpack<Materials>> g (&bpM);

	

		return 0;
}