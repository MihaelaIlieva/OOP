#pragma once
#include "SectionVotes.hpp"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class ElectionResultsDatabase
{
public:
    void addResultsFromFile(const char* filename);
    int numberOfSections() const;
    int votesForParty(Party) const;
    Party winningParty() const;

    friend ostream& operator<<(ostream& outputStream, const ElectionResultsDatabase& results);
    friend istream& operator>>(istream& inputStream, ElectionResultsDatabase& results);
private:
    int partyOneVotes = 0;
    int partyTwoVotes = 0;
    int partyThreeVotes = 0;
    vector<SectionVotes> votes;
};