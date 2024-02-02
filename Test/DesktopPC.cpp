#include "DesktopPC.hpp"

 DesktopPC::DesktopPC() :PC(), power(0)
{

}

string DesktopPC::GetType() const
{
	return "DesktopPC";
}

 int DesktopPC::GetPower()  const  { return power; }
