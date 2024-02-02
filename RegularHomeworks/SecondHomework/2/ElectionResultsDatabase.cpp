#include "ElectionResultsDatabase.hpp"

void ElectionResultsDatabase::addResultsFromFile(const char* filename)
{
    ifstream inputFile;
    inputFile.open(filename);
    SectionVotes secVotes;
    while (inputFile >> secVotes) {
        this->partyOneVotes += secVotes.votesForParty(PARTY1);
        this->partyTwoVotes += secVotes.votesForParty(PARTY2);
        this->partyThreeVotes += secVotes.votesForParty(PARTY3);  
        this->votes.push_back(secVotes);
    }
    inputFile.close();
}

int ElectionResultsDatabase::numberOfSections() const
{
    return this->votes.size();
}

int ElectionResultsDatabase::votesForParty(Party party) const
{
    if (party== Party::PARTY1) {return this->partyOneVotes;}
    else if (party == Party::PARTY2) {return this->partyTwoVotes;}
    else if (party == Party::PARTY3) {return this->partyThreeVotes;}
}

Party ElectionResultsDatabase::winningParty() const
{
    if (partyOneVotes > partyTwoVotes && partyOneVotes > partyThreeVotes) {
        return PARTY1;
    }
    else if (partyTwoVotes > partyOneVotes && partyTwoVotes > partyThreeVotes) {
        return PARTY2;
    }
    else if (partyThreeVotes > partyOneVotes && partyThreeVotes > partyTwoVotes) {
        return PARTY3;
    }
    else if ((partyOneVotes == partyTwoVotes && partyOneVotes >= partyThreeVotes)|| 
        (partyOneVotes == partyThreeVotes && partyOneVotes >= partyTwoVotes)) {
        return PARTY1;
    }
    else if (partyTwoVotes == partyThreeVotes && partyTwoVotes > partyOneVotes) {
        return PARTY2;
    }
}

ostream& operator<<(ostream& outputStream, const ElectionResultsDatabase& results)
{
    SectionVotes secVotes;
    for (size_t i = 0; i < results.numberOfSections(); i++)
    {
        outputStream<<(results.votes[i]);      
    }
    return outputStream;
}

istream& operator>>(istream& inputStream, ElectionResultsDatabase& resultsDatabase)
{
    SectionVotes secVotes;
    while (inputStream >> secVotes) {
        resultsDatabase.votes.push_back(secVotes);       
    }
    return inputStream;
}