#pragma once

#include <string>
#include "Enums.h"

class Coffee 
{
public:
	Coffee(std::string distributor, double price, double dignity, int arabica, int robusta, Coffe_type coffee_type, Roasting_degree roast, Taste_Characteristic taste);
	~Coffee();

	void setCoffeeDistriburor(std::string distributor);
	std::string getCoffeeDistriburor();

	void setCoffeePrice(double price);
	double getCoffeePrice();

	void setCoffeeDignity(double dignity);
	double getCoffeeDignity();

	void setArabicaRobustaPercentage(int percent);
	int getArabicaRobustaPercentage();

	void setCoffeeType(Coffe_type);
	Coffe_type getCoffeeType();

	void setRoastingDegree(Roasting_degree);
	Roasting_degree getRoastingDegree();

	void setTasteCharacteristic(Taste_Characteristic);
	Taste_Characteristic getTasteCharacteristic();


private:
	std::string distributor;
	double price;
	double dignity;
	int arabica;
	int robusta;
	Coffe_type coffee_type;
	Roasting_degree roast;
	Taste_Characteristic taste;
};

