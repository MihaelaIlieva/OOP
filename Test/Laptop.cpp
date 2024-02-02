#include "Laptop.hpp"

 Laptop::Laptop() :PC(),opticDevice(false)
{

}

string Laptop::GetType() const
{
	return "Laptop";
}

 bool Laptop::GetOpticDevice() const { return opticDevice; }
