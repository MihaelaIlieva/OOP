#pragma once
#include "Request.hpp"
#include <string>
using namespace std;

class LeavingRequest: virtual public Request {
public:
	LeavingRequest(const string& sender);
	LeavingRequest(const string& message, const string& sender);
	string getMessage() const;
	string getSender() const;
	int getCount() const;
	int getID() const;
};