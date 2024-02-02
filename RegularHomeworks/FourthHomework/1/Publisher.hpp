#pragma once
#include "Subscriber.hpp"

#include <vector>

using namespace std;

class Publisher
{
protected:

	vector<Subscriber*>subscribers;

	// subscribe registers a Subscriber to start receiving messages
	// The new subscriber should receive all previous messages
	virtual void subscribe(Subscriber*) = 0;


	// unsubscribe removes a Subscriber from the Publisher
	// Subscribers are removed based on their `id`
	// id-s will always be unique
	virtual void unsubscribe(Subscriber*) = 0;


	// signal receives a message from an external source
	// and replays that message to all the current subscribers
	virtual void signal(Message) = 0;
};