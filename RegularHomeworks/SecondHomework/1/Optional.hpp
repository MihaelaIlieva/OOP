#pragma once

template <typename T>

class Optional {
public:
    Optional();
    Optional(const T& value);

    bool is_none() const;
    T get_value() const;

private:
    T parameter;
    bool isEmpty = false;
};

template<typename T>
Optional<T>::Optional()
{
    this->parameter = T();
    isEmpty = true;
}

template<typename T>
Optional<T>::Optional(const T& value)
{
    this->parameter = value;
}

template<typename T>
bool Optional<T>::is_none() const
{
    if (isEmpty==true) {
        return true;
    }
    return false;
}

template<typename T>
T Optional<T>::get_value() const
{
    return this->parameter;
}
