#include "Package.h"


Package::Package(Package_type package_type, double space, double package_weight, double package_price, int opacity, Package_fragility fragility)
{
	Package::package_type = package_type;
	Package::space = space;
	Package::package_weight = package_weight;
	Package::package_price = package_price;
	Package::opacity = opacity;
	Package::fragility = fragility;
	Package::coffee = NULL;
}


Package::~Package()
{
	if (Package::coffee)
		delete Package::coffee;
}

void Package::chooseCoffee(std::string distributor, double price, double dignity, int arabica, int robusta, Coffe_type coffee_type, Roasting_degree roast, Taste_Characteristic taste)
{
	Package::coffee = new Coffee(distributor, price, dignity, arabica, robusta, coffee_type, roast, taste);
}

void Package::countPrice()
{
	Package::price = package_price + weight * coffee->getCoffeePrice();
}

void Package::countWeight()
{
	Package::weight = package_weight + coffee->getCoffeeDignity() * space;
}

void Package::countWeight_to_Price()
{
	Package::weight_to_price = weight / price;
}

void Package::loadCoffee(const rapidjson::Value & jscoffee)
{
	if (!jscoffee["distributor"].IsString() || !jscoffee["price"].IsDouble() || !jscoffee["dignity"].IsDouble() || !jscoffee["arabica"].IsInt() || !jscoffee["robusta"].IsInt() || !jscoffee["coffee_type"].IsString() || !jscoffee["roasting_degree"].IsString() || !jscoffee["taste"].IsString())
		throw "invalid json";
	std::string jsdistributor = jscoffee["distributor"].GetString();
	double jsprice = jscoffee["price"].GetDouble();
	double jsdignity = jscoffee["dignity"].GetDouble();
	int jsarabica = jscoffee["arabica"].GetInt();
	int jsrobusta = jscoffee["robusta"].GetInt();
	Coffe_type jstype = convertToCoffee_type(jscoffee["coffee_type"].GetString());
	Roasting_degree jsroast = convertToRoasting_degree(jscoffee["roasting_degree"].GetString());
	Taste_Characteristic jstaste = convertToTaste_Characteristics(jscoffee["taste"].GetString());

	chooseCoffee(jsdistributor, jsprice, jsdignity, jsarabica, jsrobusta, jstype, jsroast, jstaste);
	countWeight();
	countPrice();
	countWeight_to_Price();
}

double Package::getPrice()
{
	return Package::price;
}

Package_type Package::getPackageType()
{
	return Package::package_type;
}

Coffe_type Package::convertToCoffee_type(std::string value)
{	
	Coffe_type var;
	if (value == "grain")
		var = grain;
	else if (value == "melt")
		var = melt;
	else throw "invalid coffee_type";
	return var;
	
}

Roasting_degree Package::convertToRoasting_degree(std::string value)
{
	Roasting_degree var;
	if (value == "light")
		var = light;
	else if (value == "medium")
		var = medium;
	else if (value == "dark")
		var = dark;
	else throw "invalid Roasting_degree";
	return var;
}

Taste_Characteristic Package::convertToTaste_Characteristics(std::string value)
{
	Taste_Characteristic var;
	if (value == "bitter")
		var = bitter;
	else if (value == "sour")
		var = sour;
	else if (value == "sweet")
		var = sweet;
	else throw "invalid Roasting_degree";
	return var;
}
