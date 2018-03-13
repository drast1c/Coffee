#pragma once
#include "rapidjson\document.h"
#include "Coffee.h"

class Package
{
public:
	double price;
	double weight;
	double space;
	Package_type package_type;
	Coffee *coffee;

	Package(Package_type type, double space, double package_weight, double package_price, int opacity, Package_fragility fragility);
	~Package();

	void setPackageType(Package_type);
	Package_type getPackageType();

	void sePackageWeight(double);
	double getPackageWeight();

	void setPackagePrice(double);
	double getPackagePrice();

	void setPackageOpacity(int);
	int getPackageOpacity();

	void setPackageFragility(Package_fragility);
	Package_fragility getPackageFragility();

	void setCoffee(Coffee);
	Coffee getCoffee();

	double getPrice();
	double getSpace();
	double getWeight();

	void loadCoffee(const rapidjson::Value & jscoffee);

private:
	double package_weight;
	double package_price;
	double weight_to_price;
	int opacity;
	Package_fragility fragility;
	

	void countPrice();
	void countWeight();
	void countWeight_to_Price();
	void chooseCoffee(std::string distributor, double price, double dignity, int arabica, int robusta, Coffe_type coffee_type, Roasting_degree roast, Taste_Characteristic taste);
	Coffe_type convertToCoffee_type(std::string value);
	Roasting_degree convertToRoasting_degree(std::string value);
	Taste_Characteristic convertToTaste_Characteristics(std::string value);
};

