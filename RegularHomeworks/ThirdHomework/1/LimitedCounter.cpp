#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(int max):Counter()
{
    this->max = max;
}

LimitedCounter::LimitedCounter(int max, int initial)
{
    this->max = max;
    this->initial = initial;
    this->step = 1;
}

LimitedCounter::LimitedCounter(int max, int initial, unsigned int step)
{
    this->max = max;
    this->initial = initial;
    this->step = step;
}

void LimitedCounter::increment()
{
    this->initial += this->step;
    if (this->initial > this->max) {
        this->initial -= this->step;
    }
}

int LimitedCounter::getMax() const
{
    return this->max;
}

int LimitedCounter::getTotal() const
{
    return this->initial;
}

unsigned int LimitedCounter::getStep() const
{
    return this->step;
}
