#pragma once
#include "PC.hpp"
using namespace std;
class Laptop : public PC
{
private:
    bool opticDevice;
public:
    
    Laptop();
    string GetType() const override;
    bool GetOpticDevice() const;
};

