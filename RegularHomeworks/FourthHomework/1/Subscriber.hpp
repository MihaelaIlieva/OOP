#pragma once
#include "Message.hpp"

#include <string>
#include <vector>

using namespace std;

class Subscriber
{
public:
	const string id;
	Subscriber(std::string id);
	vector<Message> messagesRecieved;
	virtual void signal(Message messageRecieved);
	virtual int read() const=0;
	virtual Subscriber* clone() const = 0;
};