#include "Developer.hpp"
#include "TeamLead.hpp"

TeamLead::TeamLead(const string& name):Developer(name)
{
    this->teamLeader = this;
}

TeamLead::TeamLead(const string& name, double salary):TeamLead(name)
{
    this->salary = salary;
}

string TeamLead::getName() const
{
    return this->name;
}

double TeamLead::getSalary() const
{
    return this->salary;
}

TeamLead* TeamLead::getTeamLead() const
{
    return this->teamLeader;
}

vector<Developer*> TeamLead::getTeam() const
{
    return this->team;
}

void TeamLead::setInitialSalary(double amount)
{
    if ((this->getSalary()) == 0.0) {
        this->salary = amount;
    }
}

void TeamLead::sendLeavingRequest()
{
    if (this->teamLeader != nullptr) {
        LeavingRequest leavingRequestToSend = LeavingRequest(this->name);
        this->teamLeader->leavingRequests.push_back(leavingRequestToSend);
    } 
}

void TeamLead::sendPromotionRequest(double amount)
{
    if (this->teamLeader != nullptr) {
        PromotionRequest promotionRequestToSend = PromotionRequest(name, amount);
        this->teamLeader->promotionRequests.push_back(promotionRequestToSend);
    }
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary)
{
    developer->setInitialSalary(salary);
    developer->setTeamLeader(this);
    this->team.push_back(developer);
}

void TeamLead::removeDeveloperFromTeam(const string& name)
{
    bool isRemoved = false;
    for (int i = (team.size()-1); i>=0; i--)
    {
        if (isRemoved==false && team[i]->name == name) {
            this->team[i]->setTeamLeader(nullptr);
            this->team.erase(this->team.begin() + i);
            isRemoved = true;
        }
    }
}

void TeamLead::increaseTeamSalariesBy(double amount)
{
   for (size_t i = 0; i < team.size(); i++)
    {
        this->team[i]->salary += amount;
    }
}

void TeamLead::decreaseTeamSalariesBy(double amount)
{
    for (size_t i = 0; i < team.size(); i++)
    {
        this->team[i]->salary -= amount;
    }
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest)
{
    this->leavingRequests.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest)
{
    this->promotionRequests.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests()
{
    for (size_t i = 0; i < (this->team.size()); i++)
    {
        for (size_t j = 0; j < (leavingRequests.size()); j++)
        {
            if ((team[i]->name) == leavingRequests[j].sender) {
                
                this->removeDeveloperFromTeam(team[i]->name);
                team[i]->teamLeader = nullptr;
                this->leavingRequests.erase(this->leavingRequests.begin() + j);
            }       
        }     
    }
}

void TeamLead::fulfillPromotionRequests()
{
    for (size_t i = 0; i < (this->team.size()); i++)
    {
        for (size_t j = 0; j < (promotionRequests.size()); j++)
        {
            if ((team[i]->name) == promotionRequests[j].sender) {
                team[i]->salary += promotionRequests[j].amount;
                this->promotionRequests.erase(this->promotionRequests.begin() + j);
            }
        }
    }
}
