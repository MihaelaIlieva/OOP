/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Mihaela Ilieva
* @idnumber 62550
* @task 1
* @compiler VC
*/
#include "Card.hpp"
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "PendulumCard.hpp"
#include "Deck.hpp"
#include "Duelist.hpp"
#include <iostream>
#include <vector>

using namespace std;
int main() {

	MonsterCard dragon("Blue-Eyes White Dragon" , "This legendary dragon is a powerful engine of destruction" , 3000, 2500);

	MonsterCard magician("Dark Magician", "The ultimate wizard.", 2500, 2100);

	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", CardType::SPELL);

    MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", CardType::TRAP);

	PendulumCard timegazer("Timegazer Magician","Your opponent cannot activate Trap Magic Cards", 1200, 600,8, CardType::SPELL );

	
	Duelist firstDuelist("Ivan Ivanov",Deck());
	
	firstDuelist.getDeck()->setDeckName("Magician Deck");
	firstDuelist.getDeck()->addMonsterCard(dragon);
	firstDuelist.getDeck()->addMagicCard(swords);
	firstDuelist.getDeck()->addMonsterCard(magician);
	firstDuelist.getDeck()->addMagicCard(cylinder);
	firstDuelist.getDeck()->addPendulumCard(timegazer);
	
	firstDuelist.updateDeck("magician_deck.txt");
	
	MagicCard box("Mystic Box", "Destroy one monster.", CardType::SPELL);
	
	firstDuelist.getDeck()->changeMagicCard(1, box);
	firstDuelist.saveDeck("magician_deck.txt");
	return 0;
}