#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Subscriber* newSubscriber)
{
	this->subscribers.push_back(newSubscriber);
	for (size_t i = 0; i < messages.size(); i++)
	{
		newSubscriber->signal(messages[i]);
	}
}

//void BacklogPublisher::subscribe(MovingAverager* newMovingAverager)
//{
//	this->movingAveragers.push_back(newMovingAverager);
//	for (size_t i = 0; i < messages.size(); i++)
//	{
//		newMovingAverager->signal(messages[i]);
//	}
//}
//
//void BacklogPublisher::subscribe(PeriodicSampler* newPeriodicSampler)
//{
//	this->periodicSamplers.push_back(newPeriodicSampler);
//	for (size_t i = 0; i < messages.size(); i++)
//	{
//		newPeriodicSampler->signal(messages[i]);
//	}
//}

void BacklogPublisher::unsubscribe(Subscriber* newSubscriber)
{
	int pos = 0;
	bool isThereSuch = false;
	for (size_t i = 0; i < subscribers.size(); i++)
	{
		if (subscribers[i]->id == newSubscriber->id) {
			pos = i;
			isThereSuch = true;
		}
	}
	if (isThereSuch) {
		this->subscribers.erase(subscribers.begin() + pos);
	}
	
}
//
//void BacklogPublisher::unsubscribe(MovingAverager* newMovingAverager)
//{
//	int pos = 0;
//	for (size_t i = 0; i < movingAveragers.size(); i++)
//	{
//		if (movingAveragers[i]->id == newMovingAverager->id) {
//			pos = i;
//		}
//	}
//	this->movingAveragers.erase(movingAveragers.begin() + pos);
//}
//
//void BacklogPublisher::unsubscribe(PeriodicSampler* newPeriodicSampler)
//{
//	int pos = 0;
//	for (size_t i = 0; i < periodicSamplers.size(); i++)
//	{
//		if (periodicSamplers[i]->id == newPeriodicSampler->id) {
//			pos = i;
//		}
//	}
//	this->periodicSamplers.erase(periodicSamplers.begin() + pos);
//}

void BacklogPublisher::signal(Message message)
{
	this->messages.push_back(message);

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
