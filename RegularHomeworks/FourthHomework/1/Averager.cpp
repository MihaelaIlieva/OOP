#include "Averager.hpp"

Averager::Averager(std::string id):Subscriber(id)
{
}

//void Averager::signal(Message messageRecieved)
//{
//    messagesRecieved.push_back(messageRecieved.data);
//}

int Averager::read() const
{
    if (messagesRecieved.empty()) {
        return 0;
    }
    else {
        int sum = 0;
        for (auto messageNumber : messagesRecieved) {
            sum += messageNumber.data;
        }
        return (sum / messagesRecieved.size());
    }
    return 0;
}

