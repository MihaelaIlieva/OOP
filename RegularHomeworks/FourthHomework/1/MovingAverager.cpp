#include "MovingAverager.hpp"

MovingAverager::MovingAverager(std::string id, size_t windowSize):Subscriber(id),windowSize(windowSize)
{
}

//void MovingAverager::signal(Message messageRecieved)
//{
//    this->messagesRecieved.push_back(messageRecieved.data);
//}

int MovingAverager::read() const
{
    if (messagesRecieved.empty()) {
        return 0;
    }
    else {
        if (windowSize <= messagesRecieved.size()) {
            int sum = 0;
            int test = messagesRecieved.size() - 1;
            int last = messagesRecieved.size() - this->windowSize;
            for (int i = test; i >= last; i--)
            {
                sum += messagesRecieved[i].data;
            }
            return (sum / this->windowSize);
        }
        else {
            
                int sum = 0;
            for (size_t i = 0; i < messagesRecieved.size(); i++)
            {
                sum += messagesRecieved[i].data;
            }
            return(sum / messagesRecieved.size());
        }
        
    }
}

