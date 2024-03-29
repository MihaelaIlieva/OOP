#include "Request.hpp"

int Request::counter = 0;

Request::Request(const string& message, const string& sender)
{
    this->message = message;
    this->sender = sender;
    this->counter++;
    this->ID = counter;
}

string Request::getMessage() const
{
    return this->message;
}

string Request::getSender() const
{
    return this->sender;
}

int Request::getCount() const
{
    return this->counter;
}

int Request::getID() const
{
    return this->ID;
}
