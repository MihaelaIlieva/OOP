#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(std::string id, size_t period) :Subscriber(id), period(period)
{

}

//void PeriodicSampler::signal(Message messageRecieved)
//{
//    this->messagesRecieved.push_back(messageRecieved.data);
//}

int PeriodicSampler::read() const
{
    if (this->messagesRecieved.empty()) {
        return 0;
    }
    else {
        /*for (int i = messagesRecieved.size(); i >0; i--)
        {
            if (i % period == 0) {
                return messagesRecieved[i-1].data;
            }
        }*/
        if (messagesRecieved.size() % period==0) {
            int b = (messagesRecieved.size() / period -1)* period+1;
            return messagesRecieved[b - 1].data;
        }
        else {
            int b = (messagesRecieved.size() / period) * period + 1;
            return messagesRecieved[b-1].data;
        }
        return 0;
    }
    return 0;
}

