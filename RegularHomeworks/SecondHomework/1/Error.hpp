#pragma once
#include <string>

using namespace std;

class Error {
public:
    Error(const std::string& message = "");
    std::string get_message() const;
    bool operator==(const Error& other) const;
    string errorMessage;
};

