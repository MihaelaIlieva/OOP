#pragma once
#include "Counter.hpp"
#include "LimitedCounter.hpp"
#include "TwowayCounter.hpp"

class LimitedTwowayCounter: virtual public LimitedCounter,virtual public TwowayCounter {
private:
	
public:
	int min;
	LimitedTwowayCounter(int min, int max);
	LimitedTwowayCounter(int min, int max, int initial);
	LimitedTwowayCounter(int min, int max, int initial, unsigned int step);
	void increment();
	void decrement();
	int getMin() const;
	int getMax() const;
	int getTotal() const;
	unsigned int getStep() const;
};
