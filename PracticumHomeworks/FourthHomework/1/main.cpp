/**
* Solution to homework assignment 4
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

	/*For readers convenience:
	MonsterCard(name,effect,attackPoints,defensePoints,rarity)
	MagicCard(name,effect,cardType,rarity)
	PendulumCard(name,effect,attackPoints,defensePoints,pendulumScale,cardType,rarity)

	But it saves and updates the duelist's deck in the given file format:
	MonsterCard: name|effect|rarity|attackPoints|defensePoints
	MagicCard: name|effect|rarity|type
	PendulumCard: name|effect|rarity|attackPoints|defencePoints|pendulumScale|type
	
	The reason this is so it to be reused as much code from the previous task as possible, and to fulfill the new criteria at the same time
	*/

	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000, 2500, 43);
		MonsterCard magician("Dark Magician", "The ultimate wizard.", 2500, 2100, 23);
	MagicCard swords("Swords of Revealing Light" ,"Your opponent's monsters cannot declare an attack.", CardType::SPELL, 123);
		MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.",CardType::TRAP, 9);
	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 1200, 600, 8, CardType::SPELL, 3);
		Duelist firstDuelist("Ivan Ivanov");
		firstDuelist.getDeck()->addCardToDeck(&dragon);

	firstDuelist.getDeck()->setDeckName("Magician Deck");
	firstDuelist.getDeck()->addCardToDeck(&swords);
	firstDuelist.getDeck()->addCardToDeck(&magician);
	firstDuelist.getDeck()->addCardToDeck(&cylinder);
	firstDuelist.getDeck()->addCardToDeck(&timegazer);
	firstDuelist.getDeck()->shuffle();
	

	MagicCard box("Mystic Box", "Destroy one monster.", CardType::SPELL, 0);
	firstDuelist.getDeck()->changeCardByIndex(2, &box);
	firstDuelist.saveDeck("magician_deck.txt");
	
	Duelist secondDuelist("Gosho Goshev");
	secondDuelist.getDeck()->addCardToDeck(&dragon);
	secondDuelist.getDeck()->addCardToDeck(&swords);
	secondDuelist.getDeck()->addCardToDeck(&magician);
	secondDuelist.getDeck()->addCardToDeck(&box);
	secondDuelist.getDeck()->addCardToDeck(&timegazer);
	secondDuelist.saveDeck("goshos_deck.txt");

	//cout<<magician.operator<(swords);

	firstDuelist.duel(secondDuelist);
	return 0;
}