#pragma once
#include <string>
class TeamLead;
using namespace std;
class Developer {
private:

public:
	string name;
	double salary;
	TeamLead* teamLeader;

	Developer(const string& name);
	string getName() const;
	double getSalary() const;
	TeamLead* getTeamLead() const;
	void setInitialSalary(double amount);
	void setTeamLeader(TeamLead* teamlead);
	void sendLeavingRequest();
	void sendPromotionRequest(double amount);
};
