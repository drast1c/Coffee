#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include "Package.h"
class View
{
public:
	View();
	~View();
	void printTextMessage(std::string message);
	void printIntValue(int value);
	void printPackageVector(std::vector<Package*> *vector);
	void printPackage(Package *package);
	void printCoffee(Coffee *coffee);
	void printCoffeeType(Coffe_type type);
	void printPackageType(Package_type type);
	void printRoastingDegree(Roasting_degree degree);
	void printTasteCharacteristic(Taste_Characteristic characteristic);
	void printErrorMessage(int err, std::string message);
	void printErrorMessageAndString(std::string err, std::string message);

	static const std::string OFFERING_A_CRITERIA_FOR_FINDING;
	static const std::string OFFERING_TO_TYPE_BOTTOM_RANGE_OF_FINDING;
	static const std::string OFFERING_TO_TYPE_TOP_RANGE_OF_FINDING;
	static const std::string ASKING_FOR_VALID_DOUBLE;
	static const std::string NO_ELEMENTS_FOUNDED;
	static const std::string FILE_READING_ERROR;
	static const std::string INITIALIZATION_ERROR;
	static const std::string PARCE_JSON_ERROR;
	static const std::string INVALID_JSON_FORMAT;
	static const std::string GREETINGS_1;
	static const std::string BACK_OR_QUIT;
	static const std::string OFFERING_AN_ACTION;
	static const std::string OFFERING_A_CRITERIA_FOR_SORTING;
	static const std::string PARTING;
	static const std::string ASKING_FOR_VALID_INTEGER;
	static const std::string WRONG_INPUT_CRITERIA_FOR_SORTING;
private:
	const unsigned int szof_col1 = 20;
	const unsigned int szof_col2 = 12;
};

