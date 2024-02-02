#pragma once
#include <iostream>
#include <fstream>
using namespace std;

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

enum Party
{
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

class SectionVotes
{
public:
    SectionVotes();
    SectionVotes(int party1Votes, int party2Votes, int party3Votes);

    int votesForParty(Party) const;

    friend ostream& operator<<(ostream& outputStream, const SectionVotes& votes);
    friend istream& operator>>(istream& inputStream, SectionVotes& votes);
private:
    int partyOneVotes;
    int partyTwoVotes;
    int partyThreeVotes;
};