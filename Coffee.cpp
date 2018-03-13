#include "Coffee.h"


Coffee::Coffee(std::string distributor, double price, double dignity, int arabica, int robusta, Coffe_type coffee_type, Roasting_degree roast, Taste_Characteristic taste)
{
	Coffee::distributor = distributor;
	Coffee::price = price;
	Coffee::dignity = dignity; 
	Coffee::arabica = arabica;
	Coffee::robusta = robusta;
	Coffee::coffee_type = coffee_type;
	Coffee::roast = roast;
	Coffee::taste = taste;
}


Coffee::~Coffee()
{
}

void Coffee::setCoffeePrice(double price)
{
	Coffee::price = price;
}

double Coffee::getCoffeePrice()
{
	return Coffee::price;
}

void Coffee::setCoffeeDignity(double dignity)
{
	Coffee::dignity = dignity;
}

double Coffee::getCoffeeDignity()
{
	return Coffee::dignity;
}

void Coffee::setCoffeeDistriburor(std::string distributor)
{
	Coffee::distributor = distributor;
}

std::string Coffee::getCoffeeDistriburor()
{
	return Coffee::distributor;
}

void Coffee::setArabicaRobustaPercentage(int percent)
{

}

Coffe_type Coffee::getCoffeeType()
{
	return Coffee::coffee_type;
}

Roasting_degree Coffee::getRoastingDegree()
{
	return Coffee::roast;
}

Taste_Characteristic Coffee::getTasteCharacteristic()
{
	return Coffee::taste;
}