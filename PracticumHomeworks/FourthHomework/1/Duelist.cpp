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
#include "Duelist.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

Duelist::Duelist()
{
    this->name = "";
    this->deck = Deck();
}

Duelist::Duelist(string name)
{
    this->name = name;
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
        file << this->deck.getDeckName() << '|'<<this->deck.getCardsInDeckCount() <<'|' << this->deck.getMonsterCardsCount() << "|" 
            << this->deck.getMagicCardsCount() << "|" << this->deck.getPendulumCardsCount() << endl;
        for (size_t i = 0; i < this->deck.cardsInDeck.size(); i++)
        {
            if (this->deck.cardsInDeck[i]->typeOfCard == "MonsterCard") {
                MonsterCard* monsterCard=dynamic_cast<MonsterCard*>(this->deck.cardsInDeck[i]);
                file << monsterCard->getName() << "|" << monsterCard->getEffect()<<"|"<< monsterCard->getRarity() << "|" 
                    << monsterCard->getAttackPoints() << "|" << monsterCard->getDefensePoints() << endl;
            }
        }

        for (size_t i = 0; i < this->deck.cardsInDeck.size(); i++)
        {   
            if (this->deck.cardsInDeck[i]->typeOfCard == "MagicCard") {
                MagicCard* magicCard = dynamic_cast<MagicCard*>(this->deck.cardsInDeck[i]);
                string newCardType;
                if (magicCard->getCardType() == 0) {
                    newCardType = "TRAP";
                }
                else if (magicCard->getCardType() == 1) {
                    newCardType = "SPELL";
                }
                else if (magicCard->getCardType() == 2 ) {
                    newCardType = "BUFF";
                }
                file << magicCard->getName() << "|" << magicCard->getEffect()<<"|"<<magicCard->getRarity() << "|" 
                    << newCardType<< endl;     
            }
        }
        for (size_t i = 0; i < this->deck.cardsInDeck.size(); i++)
        {
            if (this->deck.cardsInDeck[i]->typeOfCard == "PendulumCard") {
                PendulumCard* pendulumCard = dynamic_cast<PendulumCard*>(this->deck.cardsInDeck[i]);
                string newCardType;
                if (pendulumCard->getCardType() == 0) {
                    newCardType = "TRAP";
                }
                else if (pendulumCard->getCardType() == 1) {
                    newCardType = "SPELL";
                }
                else if (pendulumCard->getCardType() == 2) {
                    newCardType = "BUFF";
                }
                file << pendulumCard->getName() << "|" << pendulumCard->getEffect()<<"|"<<pendulumCard->getRarity() << "|"
                    <<pendulumCard->getAttackPoints()<<"|"<< pendulumCard->getDefensePoints() << "|" 
                    << pendulumCard->getPendulumScale() << "|" << newCardType << endl;
            }
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
    string allCards;

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
            if (count == 1 && firstLine[i] != '|') { allCards += firstLine[i]; }
            if (count == 2 && firstLine[i] != '|') { monsterCards += firstLine[i]; }
            if (count == 3 && firstLine[i] != '|') { magicCards += firstLine[i]; }
            if (count == 4 && firstLine[i] != '|') { pendulumCards += firstLine[i]; }
        }
        this->deck.setDeckName(newName);

        int monsterCardsCount = stoi(monsterCards);
        int magicCardsCount = stoi(magicCards);
        int pendulumCardsCount = stoi(pendulumCards);
        int allCardsCount = stoi(allCards);

        for (size_t i = 0; i < monsterCardsCount; i++)
        {
            string line;
            string newName;
            string effect;
            string attackPoints;
            string defensePoints;
            string rarity;
            getline(inputfile, line);
            count = 0;
            for (size_t j = 0; j < line.size(); j++)
            {
                if (line[j] == '|') { count++; }
                if (count < 1 && line[j] != '|') {
                    newName += line[j];
                }
                if (count == 1 && line[j] != '|') {effect += line[j]; }
                if (count == 2 && line[j] != '|') { rarity += line[j]; }
                if (count == 3 && line[j] != '|') { attackPoints += line[j]; }
                if (count == 4 && line[j] != '|') { defensePoints += line[j]; }

            }
            MonsterCard newMonsterCard=MonsterCard(newName,effect,stoi(attackPoints),stoi(defensePoints),stoi(rarity));
            this->deck.addCardToDeck(&newMonsterCard);
        }
        for (size_t i = 0; i <magicCardsCount; i++)
        {
            string line;
            string newName;
            string effect;
            string type;
            string rarity;
            getline(inputfile, line);
            count = 0;

            for (size_t j = 0; j < line.size(); j++)
            {
                if (line[j] == '|') { count++; }
                if (count < 1 && line[j] != '|') {
                    newName += line[j];
                }
                if (count == 1 && line[j] != '|') { effect += line[j]; }
                if (count == 2 && line[j] != '|') { rarity += line[j]; }
                if (count == 3 && line[j] != '|') { type += line[j]; }

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
            MagicCard newMagicCard = MagicCard(newName,effect, newCardType,stoi(rarity));
            this->deck.addCardToDeck(&newMagicCard);
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
            string rarity;
            getline(inputfile, line);
            count = 0;

            for (size_t j = 0; j < line.size(); j++)
            {
                if (line[j] == '|') { count++; }
                if (count < 1 && line[j] != '|') {
                    newName += line[j];
                }
                if (count == 1 && line[j] != '|') { effect += line[j]; }
                if (count == 2 && line[j] != '|') { rarity += line[j]; }
                if (count == 3 && line[j] != '|') { attackPoints += line[j]; }
                if (count == 4 && line[j] != '|') { defensePoints += line[j]; }
                if (count == 5 && line[j] != '|') { pendulumScale += line[j]; }
                if (count == 6 && line[j] != '|') { type += line[j]; }

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
            PendulumCard newPendulumCard = PendulumCard(newName, effect,stoi(attackPoints),stoi(defensePoints),
                stoi(pendulumScale), newCardType,stoi(rarity));
            this->deck.addCardToDeck(&newPendulumCard);
        }
        return true;
    }
    inputfile.close();
    return false;
}

void Duelist::duel(const Duelist& other)
{
    
    if (this->getDeck()->getCardsInDeckCount() == other.deck.getCardsInDeckCount()) {
        this->deck.shuffle();
        Deck othersDeck(other.deck);
        othersDeck.shuffle();
        int thisDuelistPoints = 0;
        int otherDuelistPoints = 0;
        for (size_t i = 0; i < this->deck.cardsInDeck.size(); i++)
        {                  
                if (this->deck.cardsInDeck[i]->operator>(*other.deck.cardsInDeck[i])) {
                    thisDuelistPoints++;
                }
                else if (this->deck.cardsInDeck[i]->operator<(*other.deck.cardsInDeck[i])) {
                    otherDuelistPoints++;
                }
        }
        if (thisDuelistPoints > otherDuelistPoints) {
            cout << "Duelist " << this->name << " has won the duel with " << thisDuelistPoints << " points." << endl;
        }
        else if (thisDuelistPoints < otherDuelistPoints) {
            cout << "Duelist " << other.name << " has won the duel with " << otherDuelistPoints << " points." << endl;
        }
        else if(thisDuelistPoints==otherDuelistPoints) {
            cout << "The duel is a draw. Both opponents have " << thisDuelistPoints << " points each." << endl;
        }

    }
    else {
        cout << "Duel cannot be held due to the difference in pardicipants' card count!" << endl;
    }
}