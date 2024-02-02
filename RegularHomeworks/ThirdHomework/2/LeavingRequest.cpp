#include "LeavingRequest.hpp"

LeavingRequest::LeavingRequest(const string& sender):Request("I want to leave!",sender)
{
  
}

LeavingRequest::LeavingRequest(const string& message, const string& sender):Request(message,sender)
{
    
}

string LeavingRequest::getMessage() const
{
    return this->message;
}

string LeavingRequest::getSender() const
{
    return this->sender;
}

int LeavingRequest::getCount() const
{
    return this->counter;
}

int LeavingRequest::getID() const
{
    return this->ID;
}
