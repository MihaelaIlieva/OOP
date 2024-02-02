#include "Error.hpp"

Error::Error(const std::string& message)
{
    this->errorMessage = message;
}

std::string Error::get_message() const
{
    return this->errorMessage;
}

bool Error::operator==(const Error& other) const
{
    if (this->errorMessage == other.get_message()) {
        return true;
    }
    return false;
}