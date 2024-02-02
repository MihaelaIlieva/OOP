#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Subscriber* newSubscriber)
{
	this->subscribers.push_back(newSubscriber);
}

//void SimplePublisher::subscribe(MovingAverager* newMovingAverager)
//{
//	this->movingAveragers.push_back(newMovingAverager);
//}
//
//void SimplePublisher::subscribe(PeriodicSampler* newPeriodicSampler)
//{
//	this->periodicSamplers.push_back(newPeriodicSampler);
//}

void SimplePublisher::unsubscribe(Subscriber* newSubscriber)
{
	int pos = 0;
	bool thereIsSuch = false;
	for (size_t i = 0; i < subscribers.size(); i++)
	{
		if (subscribers[i]->id.compare(newSubscriber->id)==0) {
			pos = i;
			thereIsSuch = true;
		}
	}
	if (thereIsSuch) {
		this->subscribers.erase(subscribers.begin() + pos);
	}
}

//void SimplePublisher::unsubscribe(MovingAverager* newMovingAverager)
//{
//	int pos = 0;
//	bool thereIsSuch = false;
//	for (size_t i = 0; i < movingAveragers.size(); i++)
//	{
//		if (movingAveragers[i]->id == newMovingAverager->id) {
//			pos = i;
//			thereIsSuch = true;
//		}
//	}
//	if (thereIsSuch) {
//		this->movingAveragers.erase(movingAveragers.begin() + pos);
//	}	
//}
//
//void SimplePublisher::unsubscribe(PeriodicSampler* newPeriodicSampler)
//{
//	int pos = 0;
//	bool thereIsSuch = false;
//	for (size_t i = 0; i < periodicSamplers.size(); i++)
//	{
//		if (periodicSamplers[i]->id == newPeriodicSampler->id) {
//			pos = i;
//			thereIsSuch = true;
//		}
//	}
//	if (thereIsSuch) {
//		this->periodicSamplers.erase(periodicSamplers.begin() + pos);
//	}
//}

void SimplePublisher::signal(Message message)
{
	for (size_t i = 0; i < subscribers.size(); i++)
	{
		subscribers[i]->signal(message);
	}
	/*for (size_t i = 0; i < movingAveragers.size(); i++)
	{
		movingAveragers[i]->signal(message);
	}
	for (size_t i = 0; i < periodicSamplers.size(); i++)
	{
		periodicSamplers[i]->signal(message);
	}*/
}
