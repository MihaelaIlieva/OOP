#pragma once
#include "PC.hpp"
using namespace std;

class DesktopPC : public PC
{
private:
	int power;
public:
	
	DesktopPC();
	string GetType() const override;
	int GetPower() const;

};

