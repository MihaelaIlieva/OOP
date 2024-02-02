#pragma once
#include<string>

using namespace std;

class Serializable {
public:
	virtual string to_string()const = 0;
	virtual void from_string(const string& givenString) = 0;
};