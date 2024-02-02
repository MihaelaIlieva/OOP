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
#include "Deck.hpp"

Deck::Deck()
{
    this->name = "";
}

Deck::Deck(string name, vector<Card*> cards)
{
    this->name = name;
    for (size_t i = 0; i < cards.size(); i++)
    {
        cardsInDeck[i] = cards[i]->clone();
    }
}

string Deck::getDeckName() const
{
    return this->name;
}

int Deck::getMonsterCardsCount() const
{
    int counter = 0;
    for (size_t i = 0; i < cardsInDeck.size(); i++)
    {
        if (cardsInDeck[i]->typeOfCard.compare("MonsterCard") ==0 ) {
            counter++;
        }
    }
    return counter;
}

int Deck::getMagicCardsCount() const
{
    int counter = 0;
    for (size_t i = 0; i < cardsInDeck.size(); i++)
    {
        if (cardsInDeck[i]->typeOfCard.compare("MagicCard") ==0 ) {
            counter++;
        }
    }
    return counter;
}

int Deck::getPendulumCardsCount() const
{
    int counter = 0;
    for (size_t i = 0; i < cardsInDeck.size(); i++)
    {
        if (cardsInDeck[i]->typeOfCard.compare("PendulumCard") ==0 ) {
            counter++;
        }
    }
    return counter;
}

int Deck::getCardsInDeckCount() const
{
    return this->cardsInDeck.size();
}

void Deck::addCardToDeck(Card* cardToAdd)
{
    this->cardsInDeck.push_back(cardToAdd->clone());
}

void Deck::changeCardByIndex(int index, Card* newCard) {
    if (cardsInDeck[index]->typeOfCard.compare(newCard->typeOfCard) ==0 ) {
        cardsInDeck[index] = newCard->clone();
    }
    else {
        cout << "Did not change the deck. No match in cards' types."<<endl;
    }
}

void Deck::shuffle()
{
    random_shuffle(cardsInDeck.begin(), cardsInDeck.end());
}

void Deck::setDeckName(string name)
{
    this->name = name;
}

void Deck::ClearDeck()
{
    this->name = "";
    for (auto card : cardsInDeck) {
        delete card;
    }
    this->cardsInDeck.clear();
}

void Deck::copyOther(const Deck& other)
{
    this->name = other.name;
    for (auto card : other.cardsInDeck) {
        this->cardsInDeck.push_back(card->clone());
    }
}

Deck::Deck(const Deck& other)
{
    copyOther(other);
}

Deck& Deck::operator=(const Deck& other)
{
    if (this != &other) {
        this->ClearDeck();
        copyOther(other);
    }
    return *this;
}

Deck::~Deck()
{
    for (auto card : cardsInDeck) {
        delete card;
    }
    this->cardsInDeck.clear();
}
