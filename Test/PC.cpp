#include "PC.hpp"

PC::PC() :hddGb(0), ghZ(0), price(0)
{

}

 double PC::GetPriceInEuro() const
 {
	 return price * euroConversion;
 }

  unsigned int PC::GetHddGb() const { return hddGb; }

  double PC::GetGhz() const { return ghZ; }

  int PC::GetPrice() const { return price; }
