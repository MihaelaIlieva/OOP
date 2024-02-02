#include "Semaphore.hpp"

//Semaphore::Semaphore():LimitedTwowayCounter(min,max,initial,step)
//{
//}

//Semaphore::Semaphore(bool counterValue): LimitedTwowayCounter(min, max, initial, step)
//{
//    if (counterValue) {
//        this->initial = 1;
//    }
//    else {
//        this->initial = 0;
//    }
//}

bool Semaphore::isAvailable()
{
    return this->initial>0;
}

void Semaphore::wait()
{
    this->initial -= this->step;
    if (this->initial < this->min) {
        this->initial += this->step;
    }
}

void Semaphore::signal()
{
    this->initial += this->step;
    if (this->initial > this->max) {
        this->initial -= this->step;
    }
}
