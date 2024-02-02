#include "PromotionRequest.hpp"

PromotionRequest::PromotionRequest(const string& sender, double amount):Request("I want a raise!",sender)
{
    this->amount = amount;

}

PromotionRequest::PromotionRequest(const string& message, const string& sender):Request(message,sender)
{
    this->amount = 0;
}

string PromotionRequest::getMessage() const
{
    return this->message;
}

string PromotionRequest::getSender() const
{
    return this->sender;
}

int PromotionRequest::getCount() const
{
    return this->counter;
}

int PromotionRequest::getID() const
{
    return this->ID;
}

double PromotionRequest::getAmount() const
{
    return this->amount;
}
