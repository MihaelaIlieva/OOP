/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Mihaela Ilieva
* @idnumber 62550
* @task 2
* @compiler VC
*/
#include "Deck.hpp"
#include "Card.hpp"
#include "Duelist.hpp"
#include "MagicCard.hpp"
#include "MonsterCard.hpp"
#include <iostream>

using namespace std;

int main() {
	//the following are commands used for testing the program
	// from homework's document
	//40 cards = 20 MonsterCards/20 MagicCards
	Deck d;
	// 4-th card in the Monster deck becomes "Blue-eyes white dragon" with
	//ATK: 3000 DEF: 2500
	d.ChangeMonsterCard(4, "Blue-eyes white dragon", 3000, 2500);
	// 5-th card in the Magic deck is added/changed to "Monster reborn"
	d.ChangeMagicCard(5, "Monster reborn", "revive", MagicCardType::spell);
	//Returns the amount of MagicCards in the deck
	cout<<d.CountOfMagicCards()<<endl; 
	//Returns the amount of MonsterCards in the deck
	cout << d.CountOfMonsterCards()<<endl; 
	Duelist player1("Seto Kaiba");
	MagicCard ma("Monster reborn", "revive", MagicCardType::spell);
	MagicCard mb("Monster reborn", "revive", MagicCardType::trap);
	player1.AddMagicCard(ma);
	player1.AddMagicCard(ma);
	player1.AddMagicCard(ma);
	player1.AddMagicCard(ma);
	player1.AddMagicCard(ma);
	cout << player1.CountOfMagicCards() << endl; 
	player1.AddMagicCard(ma);
	player1.ChangeMagicCard(6, mb);
	cout << player1.CountOfMagicCards() << endl; 
	///Changes the 2-nd monster card in the Monster deck to“Dark Magician”
	MonsterCard DarkMagician("Dark Magician", 2500, 2100);
	player1.ChangeMonsterCard(2, DarkMagician);
	Duelist player2("Yugi Muto");
	//Changes the 2-nd magic card in the Magic deck to “Reflection”
	MagicCard Reflection("Reflection", "Reflects the last played spell", MagicCardType::trap);
}