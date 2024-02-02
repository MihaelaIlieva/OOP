#pragma once
#include <string>
using namespace std;

class PC
{
	
protected:
	const double euroConversion = 0.5113;
	unsigned int hddGb;
	double ghZ;
	int price;
public:
	
	
	PC();
	double GetPriceInEuro() const;
	virtual string GetType() const = 0;
	unsigned int GetHddGb() const;
	double GetGhz() const;
	int GetPrice() const;
};

