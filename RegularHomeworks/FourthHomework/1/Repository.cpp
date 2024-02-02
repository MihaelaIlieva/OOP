#include "Repository.hpp"


void Repository::add(Subscriber* newSubscriber) {
    //Make a copy
    this->subscribers.push_back(newSubscriber->clone());
}


Subscriber* Repository::get(std::string id)
{
    for (size_t i = 0; i < subscribers.size(); i++)
    {
        if (subscribers[i]->id.compare(id) == 0) {

            return (subscribers[i]);
        }
    }
    return nullptr;
}

Repository::Repository()
{
}

Repository::Repository(const Repository& other)
{       
        this->subscribers.clear();
        for (size_t i = 0; i < other.subscribers.size(); i++)
        {
            this->subscribers.push_back(other.subscribers[i]->clone());
        }
}

Repository& Repository::operator=(const Repository& other)
{
    if (&other !=this) {
        this->subscribers.clear();
        for (size_t i = 0; i < other.subscribers.size(); i++)
        {
            this->subscribers.push_back(other.subscribers[i]->clone());
        }
    }
    return *this;
}
//#include "Repository.hpp"
//
//
//void Repository::add(Subscriber* newSubscriber) {
//    this->subscribers.push_back(newSubscriber);
//}
////void Repository::add(Averager* newAverager)
////{
////    this->averagers.push_back(newAverager);
////}
////
////void Repository::add(MovingAverager* newMovingAverager)
////{
////    this->movingAveragers.push_back(newMovingAverager);
////}
////
////void Repository::add(PeriodicSampler* newPeriodicSampler)
////{
////    this->periodicSamplers.push_back(newPeriodicSampler);
////}
//
//Subscriber* Repository::get(std::string id)
//{
//    for (size_t i = 0; i < subscribers.size(); i++)
//    {
//        if (subscribers[i]->id.compare(id)==0) {
//            
//            return (subscribers[i]);
//        }
//    }
//    /*for (size_t i = 0; i < movingAveragers.size(); i++)
//    {
//        if (movingAveragers[i]->id.compare(id) == 0) {
//            return static_cast<void*>(movingAveragers[i]);
//        }
//    }
//    for (size_t i = 0; i < periodicSamplers.size(); i++)
//    {
//        if (periodicSamplers[i]->id.compare(id) == 0) {
//            return static_cast<void*>(periodicSamplers[i]);
//        }
//    }*/
//    return nullptr;
//}
