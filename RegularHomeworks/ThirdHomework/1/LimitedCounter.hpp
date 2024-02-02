#pragma once
#include "Counter.hpp"

class LimitedCounter:virtual public Counter{
private:
	
public:
	int max;
	LimitedCounter(int max);
	LimitedCounter(int max, int initial);
	LimitedCounter(int max, int initial, unsigned int step);
	void increment();
	int getMax() const;
	int getTotal() const;
	unsigned int getStep() const;
};
