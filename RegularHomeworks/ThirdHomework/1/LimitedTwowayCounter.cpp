#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max):LimitedCounter(max)
{
    this->min = min;
    this->max = max;
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial):LimitedCounter(max,initial)
{
    this->min = min;
    this->max = max;
    this->initial = initial;
    this->step = 1;
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial, unsigned int step):LimitedCounter(max,initial,step)
{
    this->min = min;
    this->max = max;
    this->initial = initial;
    this->step = step;
}

void LimitedTwowayCounter::increment()
{
    this->initial += this->step;
    if (this->initial > this->max) {
        this->initial -= this->step;
    }
}

void LimitedTwowayCounter::decrement()
{
    this->initial -= this->step;
    if (this->initial < this->min) {
        this->initial += this->step;
    }
}

int LimitedTwowayCounter::getMin() const
{
    return this->min;
}

int LimitedTwowayCounter::getMax() const
{
    return this->max;
}

int LimitedTwowayCounter::getTotal() const
{
    return this->initial;
}

unsigned int LimitedTwowayCounter::getStep() const
{
    return this->step;
}
