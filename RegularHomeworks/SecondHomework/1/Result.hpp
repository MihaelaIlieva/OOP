#pragma once
#include <iostream>
#include <typeinfo>
#include "Error.hpp"
#include "Optional.hpp"

template<typename T>

class Result {
public:
    Result();
    Result(const T& result);
    Result(const std::string& error_message);

    Optional<T> get_result() const;
    Optional<Error> get_error() const;
    
    bool operator==(const T& other) const;
    bool operator==(const Error& other) const;
    bool isError = false;
private:
    T result;
    Error error;
    
};

template<typename T>
Result<T>::Result()
{
    this->result = T();
    this->error = Error();
}

template<typename T>
Result<T>::Result(const T& result)
{
    this->result = result;
    isError = false;
}

template<typename T>
Result<T>::Result(const std::string& error_message)
{
    this->error.errorMessage = error_message;
    isError = true;
}

template<typename T>
Optional<T> Result<T>::get_result() const
{
    return this->result;
}

template<typename T>
Optional<Error> Result<T>::get_error() const
{
    return this->error;
}

template<typename T>
bool Result<T>::operator==(const T& other) const
{
    if (isError == true) {
        return false;
    }
    else {
        if (typeid(this->result) == typeid(other)) {
            return true;
        }
        return false;
    }
}

template<typename T>
bool Result<T>::operator==(const Error& other) const
{
    if (isError == true) {
        return true;
    }
    return false;
}