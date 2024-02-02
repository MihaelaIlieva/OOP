#include "TwowayCounter.hpp"

TwowayCounter::TwowayCounter():Counter()
{
}

TwowayCounter::TwowayCounter(int initial):Counter(initial)
{
}

TwowayCounter::TwowayCounter(int initial, unsigned int step):Counter(initial,step)
{
}

void TwowayCounter::increment()
{
	this->initial += this->step;
}

int TwowayCounter::getTotal() const
{
	return this->initial;
}

unsigned int TwowayCounter::getStep() const
{
	return this->step;
}

void TwowayCounter::decrement()
{
	this->initial -= this->step;
}
