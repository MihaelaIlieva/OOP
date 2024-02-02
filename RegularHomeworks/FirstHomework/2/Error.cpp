#include "Error.hpp"

bool Error::hasMessage() const
{
    if (this->message != nullptr) {
        return true;
    }
    return false;
}

const char* Error::getMessage() const
{
    return this->message;
}

ErrorType Error::getType() const
{
    return this->errorType;
}

Error Error::newNone()
{
    ErrorType errorType = ErrorType::None;
    char* message = nullptr;

    return Error(errorType, message);
}

Error Error::newBuildFailed(const char* message)
{
    ErrorType errorType = ErrorType::BuildFailed;

    return Error(errorType, message);
}

Error Error::newWarning(const char* message)
{
    ErrorType errorType = ErrorType::Warning;

    return Error(errorType, message);
}

Error Error::newFailedAssertion(const char* message)
{
    ErrorType errorType = ErrorType::FailedAssertion;

    return Error(errorType, message);
}

Error::Error()
{
    this->errorType = ErrorType::None;
    this->message = nullptr;
}

Error::Error(ErrorType errorType,const char* message)
{
    this->errorType = errorType;
    if (message!=nullptr)
    {
        int messageSize = strlen(message);
        this->message = new char[messageSize+1];
        strcpy(this->message, message);
    }
}

// it's commented because it makes problems for some reason
Error::~Error()
{   
    // delete[] message;  
}
