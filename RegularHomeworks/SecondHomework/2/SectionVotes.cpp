#include "SectionVotes.hpp"

SectionVotes::SectionVotes()
{
	this->partyOneVotes = 0;
	this->partyTwoVotes = 0;
	this->partyThreeVotes = 0;
}

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes)
{
	this->partyOneVotes = party1Votes;
	this->partyTwoVotes = party2Votes;
	this->partyThreeVotes = party3Votes;
}

int SectionVotes::votesForParty(Party party) const
{
	if (party == 0) { return this->partyOneVotes; }
	if (party == 1) { return this->partyTwoVotes; }
	if (party == 2) { return this->partyThreeVotes;}
}

ostream& operator<<(ostream& outputStream, const SectionVotes& votes)
{
	outputStream << votes.partyOneVotes << " " << votes.partyTwoVotes << " " << votes.partyThreeVotes << endl;
	return outputStream;
}

istream& operator>>(istream& inputStream,SectionVotes& votes) {
	inputStream >> votes.partyOneVotes >> votes.partyTwoVotes>> votes.partyThreeVotes;
	return inputStream;
}