#pragma once
#include "Developer.hpp"
#include "Request.hpp"
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"
#include <vector>
using namespace std;

class TeamLead: virtual public Developer {
private:

public:
	vector<Developer*> team;
	vector<LeavingRequest> leavingRequests;
	vector<PromotionRequest> promotionRequests;

	TeamLead(const string& name);
	TeamLead(const string& name, double salary);

	string getName() const;
	double getSalary() const;
	TeamLead* getTeamLead() const;
	vector<Developer*> getTeam() const;

	void setInitialSalary(double amount);
	void sendLeavingRequest();
	void sendPromotionRequest(double amount);
	void addDeveloperToTeam(Developer* developer, double salary);
	void removeDeveloperFromTeam(const string& name);
	void increaseTeamSalariesBy(double amount);
	void decreaseTeamSalariesBy(double amount);
	void addLeavingRequest(const LeavingRequest& leavingRequest);
	void addPromotionRequest(const PromotionRequest& promotionRequest);
	void fulfillLeavingRequests();
	void fulfillPromotionRequests();
};