#pragma once
#include <string>

using namespace std;
class Request {
private:
	
public:
	string message;
	string sender;
	static int counter;
	int ID;
	Request(const string& message, const string& sender);
	string getMessage() const;
	string getSender() const;
	int getCount() const;
	int getID() const;
};
