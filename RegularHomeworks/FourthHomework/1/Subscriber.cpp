#include "Subscriber.hpp"

Subscriber::Subscriber(std::string id) :id(id)
{
}

void Subscriber::signal(Message messageRecieved)
{
	messagesRecieved.push_back(messageRecieved);
}
