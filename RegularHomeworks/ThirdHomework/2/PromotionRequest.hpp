#pragma once
#include "Request.hpp"
#include <string>
using namespace std;

class PromotionRequest : virtual public Request {
public:
	double amount;
	PromotionRequest(const string& sender, double amount);
	PromotionRequest(const string& message, const string& sender);
	string getMessage() const;
	string getSender() const;
	int getCount() const;
	int getID() const;
	double getAmount() const;
};
