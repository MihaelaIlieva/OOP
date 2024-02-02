#include "Developer.hpp"
#include "TeamLead.hpp"
Developer::Developer(const string& name)
{
    this->name = name;
    this->salary = 0;
    this->teamLeader = nullptr;
}

string Developer::getName() const
{
    return this->name;
}

double Developer::getSalary() const
{
    return this->salary;
}

TeamLead* Developer::getTeamLead() const
{
    return this->teamLeader;
}

void Developer::setInitialSalary(double amount)
{
    if ((this->salary) == 0) {
        this->salary = amount;
    }
}

void Developer::setTeamLeader(TeamLead* teamlead)
{
    this->teamLeader = teamlead;
}

void Developer::sendLeavingRequest()
{
    if (this->teamLeader != nullptr) {
        LeavingRequest leavingRequestToSend=LeavingRequest(this->name);
        this->teamLeader->leavingRequests.push_back(leavingRequestToSend);
    }   
}

void Developer::sendPromotionRequest(double amount)
{
    if (this->teamLeader != nullptr) {
        PromotionRequest promotionRequestToSend = PromotionRequest(name, amount);
        this->teamLeader->promotionRequests.push_back(promotionRequestToSend);
    }
}
