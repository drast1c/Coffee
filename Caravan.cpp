#include "Caravan.h"

Caravan::Caravan(double space)
{
	Caravan::space = space;
}

Caravan::~Caravan()
{
	for (unsigned int i = 0; i < commodity.size(); i++)
	{	
		delete commodity[i];
	}
		
}

void Caravan::loadCaravan(const rapidjson::Value & jscaravan)
{	
	if (!jscaravan.HasMember("packages"))
		throw "invalid json, can not find \"packages\"";
	const rapidjson::Value& jspackages = jscaravan["packages"];
	Package_type jstype;
	double jsspace;
	double jspackage_weight;
	double jspackage_price;
	int jsopacity;
	Package_fragility jsfragility;
	for (rapidjson::SizeType i = 0; i < jscaravan["packages"].Size(); i++)
	{
		if (!jspackages[i]["package_type"].IsString() || !jspackages[i]["space"].IsDouble() || !jspackages[i]["package_weight"].IsDouble() || !jspackages[i]["package_price"].IsDouble() || !jspackages[i]["opacity"].IsInt() || !jspackages[i]["fragility"].IsString() || !jspackages[i].HasMember("coffee") || !jspackages[i]["coffee"].IsObject())
			throw "invalid jason";
		jstype = convertToPackage_type(jspackages[i]["package_type"].GetString());
		jsspace = jspackages[i]["space"].GetDouble();
		jspackage_weight = jspackages[i]["package_weight"].GetDouble();
		jspackage_price = jspackages[i]["package_price"].GetDouble();
		jsopacity = jspackages[i]["opacity"].GetInt();
		jsfragility = convertToPackage_fragility(jspackages[i]["fragility"].GetString());
		addPackage(jstype, jsspace, jspackage_weight, jspackage_price, jsopacity, jsfragility, jspackages[i]["coffee"]);
	}
	countSummaryPrice();
}

void Caravan::addPackage(Package_type package_type, double space, double package_weight, double package_price, int opacity, Package_fragility fragility, const rapidjson::Value & jscoffee)
{
	Package *package = new Package(package_type, space, package_weight, package_price, opacity, fragility);
	package->loadCoffee(jscoffee);
	commodity.push_back(package);
		
}
int Caravan::getCommoditySize()
{
	return Caravan::commodity.size();
}

void Caravan::setCaravanSpace(double space)
{
	Caravan::space = space;
}

void Caravan::countSummaryPrice()
{
	for (unsigned int i = 0; i < commodity.size(); i++)
		Caravan::summary_price += commodity[i]->getPrice();
}
double Caravan::getSummaryPrice()
{
	return Caravan::summary_price;
}

bool cmpByPrice(Package *one, Package *two)
{
	return (one->price < two->price);
}

bool cmpBySpace(Package *one, Package *two)
{
	return (one->space < two->space);
}

bool cmpByWeight(Package *one, Package *two)
{
	return (one->weight < two->weight);
}

bool cmpByDistributor(Package *one, Package *two)
{
	return (one->coffee->getCoffeeDistriburor() < two->coffee->getCoffeeDistriburor());
}


void Caravan::sortByCriteria(int criteria)
{
	switch (criteria)
	{
	case 1:
	{
		std::sort(Caravan::commodity.begin(), Caravan::commodity.end(), cmpByPrice);
		break;
	}
	case 2:
	{
		std::sort(Caravan::commodity.begin(), Caravan::commodity.end(), cmpByWeight);
		break;
	}
	case 3:
	{
		std::sort(Caravan::commodity.begin(), Caravan::commodity.end(), cmpBySpace);
		break;
	}
	case 4:
	{
		std::sort(Caravan::commodity.begin(), Caravan::commodity.end(), cmpByDistributor);
		break;
	}
	case 5:
	{
		break;
	}
	default:
	{
		throw 001;
	}
	}
}

std::vector<Package*>* Caravan::getCommodity()
{
	return &commodity;
}

Package_type Caravan::convertToPackage_type(std::string value)
{
	Package_type var;
	if (value == "jar")
		var = jar;
	else if (value == "stick")
		var = stick;
	else if (value == "can")
		var = can;
	else throw "invalid package type";
		return var;
}

Package_fragility Caravan::convertToPackage_fragility(std::string value)
{
	Package_fragility var;
	if (value == "very_fragile")
		var = very_fragile;
	else if (value == "fragile")
		var = fragile;
	else if (value == "non_fragile")
		var = non_fragile;
	else throw "invalid package fragility";
	return var;
}

std::vector<int> Caravan::findPackagesByPrice(double bottom, double top)
{
	std::vector<int> index;
	for (int i = 0; i < commodity.size(); i++)
		if (commodity[i]->price > bottom && commodity[i]->price < top)
			index.push_back(i);
	return index;
}

std::vector<int> Caravan::findPackagesByWeight(double bottom, double top)
{
	std::vector<int> index;
	for (int i = 0; i < commodity.size(); i++)
		if (commodity[i]->weight > bottom && commodity[i]->weight < top)
			index.push_back(i);
	return index;
}

std::vector<int> Caravan::findPackagesBySpace(double bottom, double top)
{
	std::vector<int> index;
	for (int i = 0; i < commodity.size(); i++)
		if (commodity[i]->space > bottom && commodity[i]->space < top)
			index.push_back(i);
	return index;
}

