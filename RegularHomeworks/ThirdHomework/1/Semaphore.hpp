#pragma once
#include "Counter.hpp"
#include "LimitedCounter.hpp"
#include "TwowayCounter.hpp"
#include "LimitedTwowayCounter.hpp"

class Semaphore: public LimitedTwowayCounter {
private:

public:
	//Semaphore();
	//Semaphore(bool counterValue);
	bool isAvailable();
	void wait();
	void signal();

};
