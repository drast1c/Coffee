#include "View.h"


View::View()
{
}


View::~View()
{
}

const std::string View::ASKING_FOR_VALID_DOUBLE = "Please, enter a valid double\n";
const std::string View::NO_ELEMENTS_FOUNDED = "There is no elements in such range.\n";
const std::string View::OFFERING_TO_TYPE_BOTTOM_RANGE_OF_FINDING = "Type the bottom limit:";
const std::string View::OFFERING_TO_TYPE_TOP_RANGE_OF_FINDING = "Type the top limit:";
const std::string View::OFFERING_A_CRITERIA_FOR_FINDING = "What criteria would u like to choose the range in?\n\t1  -  to find by price\n\t2  -  to find by weight\n\t3  -  to find by space\nType the appropriate value to choose the criteria.\n";
const std::string View::INVALID_JSON_FORMAT = "Json. file format is invalid.\n";
const std::string View::GREETINGS_1 = "The caravan is created.\n";
const std::string View::OFFERING_AN_ACTION = "What would u like to do?\n\t1  -  to sort a caravan by criteria;\n\t2  -  to show the packages\n\t3  -  to show the packages in the range of values\n\t4  -  to quit the programm\nType the appropriate value to choose an action.\n";
const std::string View::OFFERING_A_CRITERIA_FOR_SORTING = "What criteria will I sort by?\n\t1  -  by price;\n\t2  -  by weight;\n\t3  -  by space\n\t4  -  by distributor\n\t5  -  by some another coffee parameter\nType the appropriate value to choose the criteria.\n";
const std::string View::PARTING = "Ok. See you!\n";
const std::string View::ASKING_FOR_VALID_INTEGER = "Please, enter a valid integer:\n";
const std::string View::WRONG_INPUT_CRITERIA_FOR_SORTING = "Sorting denied! Wrong input has been detected.\n";
const std::string View::FILE_READING_ERROR = "Can not open the data file.\n";
const std::string View::INITIALIZATION_ERROR = "Something went wrong with starting initaliztion. The executing of the porgram is no longer possible\n";
const std::string View::BACK_OR_QUIT = "Do you want to get back or to quit?\n\t1  -  to get back\n\t2  -  to quit\n";
const std::string View::PARCE_JSON_ERROR = "A problem has been occured with parcing the .json file.\n";

void View::printTextMessage(std::string message)
{
	std::cout << message;
}

void View::printIntValue(int value)
{
	std::cout << value << std::endl;
}

void View::printPackageVector(std::vector<Package*> *vector)
{
	for (unsigned int i = 0; i < vector->size(); i++)
		printPackage((*vector)[i]);
}

void View::printPackage(Package *package)
{
	printCoffee(package->coffee);
	std::cout << std::setiosflags(std::ios::left) << std::setw(szof_col1) << "Price" << std::resetiosflags(std::ios::left) << std::setw(szof_col2) << package->price << std::endl;
	std::cout << std::setiosflags(std::ios::left) << std::setw(szof_col1) << "Weight" << std::resetiosflags(std::ios::left) << std::setw(szof_col2) << package->weight << std::endl;
	std::cout << std::setiosflags(std::ios::left) << std::setw(szof_col1) << "Space" << std::resetiosflags(std::ios::left) << std::setw(szof_col2) << package->space << std::endl;
	printPackageType(package->getPackageType());
	std::cout << std::endl;
}

void View::printCoffeeType(Coffe_type type)
{
	switch (type)
	{
	case grain:
	{
		std::cout << std::setiosflags(std::ios::left) << std::setw(szof_col1) << "Coffee type" << std::resetiosflags(std::ios::left) << std::setw(szof_col2) << "grain" << std::endl;
		break; 
	}
	case melt:
	{
		std::cout << std::setiosflags(std::ios::left) << std::setw(szof_col1) << "Coffee type" << std::resetiosflags(std::ios::left) << std::setw(szof_col2) << "melt" << std::endl;
		break;
	}
	}
}

void View::printRoastingDegree(Roasting_degree degree)
{
	switch (degree)
	{
	case light:
	{
		std::cout << std::setiosflags(std::ios::left) << std::setw(szof_col1) << "Roasting degree" << std::resetiosflags(std::ios::left) << std::setw(szof_col2) << "light" << std::endl;
		break;
	}
	case medium:
	{
		std::cout << std::setiosflags(std::ios::left) << std::setw(szof_col1) << "Roasting degree" << std::resetiosflags(std::ios::left) << std::setw(szof_col2) << "medium" << std::endl;
		break;
	}
	case dark:
	{
		std::cout << std::setiosflags(std::ios::left) << std::setw(szof_col1) << "Roasting degree" << std::resetiosflags(std::ios::left) << std::setw(szof_col2) << "dark" << std::endl;
		break;
	}
	}
}

void View::printTasteCharacteristic(Taste_Characteristic characteristic)
{
	switch (characteristic)
	{
	case bitter:
	{
		std::cout << std::setiosflags(std::ios::left) << std::setw(szof_col1) << "Taste characteristic" << std::resetiosflags(std::ios::left) << std::setw(szof_col2) << "bitter" << std::endl;
		break;
	}
	case sour:
	{
		std::cout << std::setiosflags(std::ios::left) << std::setw(szof_col1) << "Taste characteristic" << std::resetiosflags(std::ios::left) << std::setw(szof_col2) << "sour" << std::endl;
		break;
	}
	case sweet:
	{
		std::cout << std::setiosflags(std::ios::left) << std::setw(szof_col1) << "Taste characteristic" << std::resetiosflags(std::ios::left) << std::setw(szof_col2) << "sweet" << std::endl;
		break;
	}
	}
}

void View::printCoffee(Coffee *coffee)
{
	std::cout << std::setiosflags(std::ios::left) << std::setw(szof_col1) << "Distributor" << std::resetiosflags(std::ios::left) << std::setw(szof_col2) << coffee->getCoffeeDistriburor() << std::endl;
	printCoffeeType(coffee->getCoffeeType());
	printRoastingDegree(coffee->getRoastingDegree());
	printTasteCharacteristic(coffee->getTasteCharacteristic());
}

void View::printPackageType(Package_type type)
{
	switch (type)
	{
	case jar:
	{
		std::cout << std::setiosflags(std::ios::left) << std::setw(szof_col1) << "Package type" << std::resetiosflags(std::ios::left) << std::setw(szof_col2) << "jar" << std::endl;
		break;
	}
	case stick:
	{
		std::cout << std::setiosflags(std::ios::left) << std::setw(szof_col1) << "Package type" << std::resetiosflags(std::ios::left) << std::setw(szof_col2) << "stick" << std::endl;
		break;
	}
	case can:
	{
		std::cout << std::setiosflags(std::ios::left) << std::setw(szof_col1) << "Package type" << std::resetiosflags(std::ios::left) << std::setw(szof_col2) << "can" << std::endl;
		break;
	}
	}
}

void View::printErrorMessage(int err, std::string message)
{
	std::cout << "Error #" << err << ".\t";
	printTextMessage(message);
}

void View::printErrorMessageAndString(std::string err, std::string message)
{
	std::cout << "Error_type[\"" << err << "\"]. " << message;
}