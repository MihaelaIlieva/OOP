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
#include "Duelist.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

Duelist::Duelist()
{
    this->name = "";
    this->deck = Deck();
}

Duelist::Duelist(string name, Deck deck)
{
    this->name = name;
    this->deck = deck;
}

string Duelist::getName() const
{
    return this->name;
}

Deck* Duelist::getDeck()
{
    Deck* thisDeckPointer = &this->deck;
    return thisDeckPointer;
}

bool Duelist::saveDeck(string fileName)
{
    ofstream file;
    file.open(fileName);
    if (file.is_open()) {
        file << this->deck.getDeckName() << '|' << this->deck.getMonsterCardsCount() << "|" << this->deck.getMagicCardsCount() << "|" << this->deck.getPendulumCardsCount() << endl;
        for (size_t i = 0; i < this->deck.getMonsterCardsCount(); i++)
        {
            
            file << this->deck.monsterCards[i].getName() << "|" << this->deck.monsterCards[i].getEffect() << "|" << this->deck.monsterCards[i].getAttackPoints() << "|" << this->deck.monsterCards[i].getDefensePoints() << endl;
        }
        for (size_t i = 0; i < this->deck.getMagicCardsCount(); i++)
        {   
            string newCardType;
            if (this->deck.magicCards[i].getCardType() == 0) {
                newCardType = "TRAP";
            }
            else if (this->deck.magicCards[i].getCardType() == 1) {
                newCardType = "SPELL";
            }
            else if (this->deck.magicCards[i].getCardType() == 2 ) {
                newCardType = "BUFF";
            }

            file << this->deck.magicCards[i].getName() << "|" << this->deck.magicCards[i].getEffect() << "|" << newCardType<< endl;
        }
        for (size_t i = 0; i < this->deck.getPendulumCardsCount(); i++)
        {
            string newCardType;
            if (this->deck.pendulumCards[i].getCardType() == 0) {
                newCardType = "TRAP";
            }
            else if (this->deck.pendulumCards[i].getCardType() == 1) {
                newCardType = "SPELL";
            }
            else if (this->deck.pendulumCards[i].getCardType() == 2) {
                newCardType = "BUFF";
            }

            file << this->deck.pendulumCards[i].getName() << "|" << this->deck.pendulumCards[i].getEffect() << "|" <<this->deck.pendulumCards[i].getAttackPoints()<<"|"<< this->deck.pendulumCards[i].getDefensePoints() << "|" << this->deck.pendulumCards[i].getPendulumScale() << "|" << newCardType << endl;
        }
        return true;
    }
    file.close();
    return false;
}

bool Duelist::updateDeck(string fileName)
{
    int count = 0;
    string newName;
    string monsterCards;
    string magicCards;
    string pendulumCards;
    

    ifstream inputfile;
    inputfile.open(fileName);
    string firstLine;
    if (inputfile.is_open()) {
        this->deck.ClearDeck();
        getline(inputfile, firstLine);
        for (size_t i = 0; i < firstLine.size(); i++)
        {
            if (firstLine[i] == '|') { count++; }
            if (count < 1 && firstLine[i] != '|') {
                newName += firstLine[i];
            }
            if (count == 1 && firstLine[i] != '|') { monsterCards += firstLine[i]; }
            if (count == 2 && firstLine[i] != '|') { magicCards += firstLine[i]; }
            if (count == 3 && firstLine[i] != '|') { pendulumCards += firstLine[i]; }
        }
        this->deck.setDeckName(newName);

        int monsterCardsCount = stoi(monsterCards);
        int magicCardsCount = stoi(magicCards);
        int pendulumCardsCount = stoi(pendulumCards);

        for (size_t i = 0; i < monsterCardsCount; i++)
        {
            string line;
            string newName;
            string effect;
            string attackPoints;
            string defensePoints;
            getline(inputfile, line);
            count = 0;
            for (size_t j = 0; j < line.size(); j++)
            {
                if (line[j] == '|') { count++; }
                if (count < 1 && line[j] != '|') {
                    newName += line[j];
                }
                if (count == 1 && line[j] != '|') {effect += line[j]; }
                if (count == 2 && line[j] != '|') { attackPoints += line[j]; }
                if (count == 3 && line[j] != '|') { defensePoints += line[j]; }

            }
            MonsterCard newMonsterCard=MonsterCard(newName,effect,stoi(attackPoints),stoi(defensePoints));
            this->deck.addMonsterCard(newMonsterCard);
        }
        for (size_t i = 0; i <magicCardsCount; i++)
        {
            string line;
            string newName;
            string effect;
            string type;
            getline(inputfile, line);
            count = 0;

            for (size_t j = 0; j < line.size(); j++)
            {
                if (line[j] == '|') { count++; }
                if (count < 1 && line[j] != '|') {
                    newName += line[j];
                }
                if (count == 1 && line[j] != '|') { effect += line[j]; }
                if (count == 2 && line[j] != '|') { type += line[j]; }

            }
            CardType newCardType;
            if (type == "TRAP") {
                newCardType = CardType::TRAP;
            }
            else if (type == "SPELL") {
                newCardType = CardType::SPELL;
            }
            else if (type == "BUFF") {
                newCardType = CardType::BUFF;
            }
            MagicCard newMagicCard = MagicCard(newName,effect, newCardType);
            this->deck.addMagicCard(newMagicCard);
        }

        for (size_t i = 0; i < pendulumCardsCount; i++)
        {
            string line;
            string newName;
            string effect;
            string attackPoints;
            string defensePoints;
            string pendulumScale;
            string type;
            getline(inputfile, line);
            count = 0;

            for (size_t j = 0; j < line.size(); j++)
            {
                if (line[j] == '|') { count++; }
                if (count < 1 && line[j] != '|') {
                    newName += line[j];
                }
                if (count == 1 && line[j] != '|') { effect += line[j]; }
                if (count == 2 && line[j] != '|') { attackPoints += line[j]; }
                if (count == 3 && line[j] != '|') { defensePoints += line[j]; }
                if (count == 4 && line[j] != '|') { pendulumScale += line[j]; }
                if (count == 5 && line[j] != '|') { type += line[j]; }

            }
            CardType newCardType;
            if (type == "TRAP") {
                newCardType = CardType::TRAP;
            }
            else if (type == "SPELL") {
                newCardType = CardType::SPELL;
            }
            else if (type == "BUFF") {
                newCardType = CardType::BUFF;
            }
            PendulumCard newPendulumCard = PendulumCard(newName, effect,stoi(attackPoints),stoi(defensePoints),stoi(pendulumScale), newCardType);
            this->deck.addPendulumCard(newPendulumCard);
        }
        return true;
    }
    inputfile.close();
    return false;
}
