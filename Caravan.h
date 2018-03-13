#pragma once
#include "Package.h"
#include <fstream>
#include "rapidjson\document.h"
#include <vector>
#include <algorithm>

class Caravan
{
public:
	Caravan(double space);
	~Caravan();

	void setCommodity();
	std::vector<Package*>* getCommodity();
	int getCommoditySize();

	void setCaravanSpace(double);
	double getCaravanSpace();

	std::vector<int> findPackagesByPrice(double bottom, double top);
	std::vector<int> findPackagesByWeight(double bottom, double top);
	std::vector<int> findPackagesBySpace(double bottom, double top);

	void loadCaravan(const rapidjson::Value& jscaravan);
	void sortByCriteria(int criteria);
	
	double getSummaryPrice();

private:
	std::vector<Package*> commodity;
	double space;
	double summary_price;
	void countSummaryPrice();
	void addPackage(Package_type package_type, double space, double package_weight, double package_price, int opacity, Package_fragility fragility, const rapidjson::Value & jscoffee);
	Package_type convertToPackage_type(std::string value);
	Package_fragility convertToPackage_fragility(std::string value);
};

