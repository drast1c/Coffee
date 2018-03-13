#include "Controller.h"


Controller::Controller(View *view)
{
	Controller::view = view;
	Controller::caravan = NULL;
}


Controller::~Controller()
{
	if (Controller::caravan)
		delete Controller::caravan;
}

void Controller::createCaravan()
{
	std::string wayToJsonFile = "Data\\coffee.json";
	rapidjson::Document document;
	try 
	{
		double jsspace;
		document = parceJson(wayToJsonFile);
		if (!document.IsObject() || !document.HasMember("caravan"))
		{
			throw "invalid json";
		}
		const rapidjson::Value& jscaravan = document["caravan"];
		if (!jscaravan["space"].IsDouble())
		{
			throw "invalid json";
		}
		else 
			jsspace = jscaravan["space"].GetDouble();
		Controller::caravan = new Caravan(jsspace);
		Controller::caravan->loadCaravan(jscaravan);
	}
	catch (int i)
	{
		view->printErrorMessage(i, View::FILE_READING_ERROR);
		throw;
	}
	catch (rapidjson::ParseErrorCode)
	{

		view->printTextMessage(View::PARCE_JSON_ERROR);
		throw;
	}
	catch (const char* err)
	{
		view->printErrorMessageAndString(err, View::PARCE_JSON_ERROR);
		throw;
	}
	catch (...)
	{
		view->printTextMessage(View::INVALID_JSON_FORMAT);
		throw;
	}
	
	
}

void Controller::processUser()
{
	view->printTextMessage(View::OFFERING_AN_ACTION);
	int action = intInputValueValidation(1, 4);
	switch (action)
	{
	case 1:
	{	
		int criteria;
		view->printTextMessage(View::OFFERING_A_CRITERIA_FOR_SORTING);
		criteria = intInputValueValidation(1, 5);
		try 
		{
			caravan->sortByCriteria(criteria); 
		}
		catch (int i)
		{
			view->printErrorMessage(i, View::WRONG_INPUT_CRITERIA_FOR_SORTING);
		}
		view->printPackageVector(caravan->getCommodity());
		view->printTextMessage(View::BACK_OR_QUIT);
		int action;
		action = intInputValueValidation(1, 2);
		if (action == 1)
			processUser();
		else view->printTextMessage(View::PARTING);

		break;
	}
	case 2:
	{	
		
		view->printPackageVector(caravan->getCommodity());
		view->printTextMessage(View::BACK_OR_QUIT);
		int action;
		action = intInputValueValidation(1, 2);
		if (action == 1)
			processUser();
		else view->printTextMessage(View::PARTING);
		
		break;
	}
	case 3:
	{	
		int criteria;
		double bottom_limit;
		double top_limit;
		view->printTextMessage(View::OFFERING_A_CRITERIA_FOR_FINDING);
		criteria = intInputValueValidation(1, 3);
		view->printTextMessage(View::OFFERING_TO_TYPE_BOTTOM_RANGE_OF_FINDING);
		bottom_limit = doubleInputValueValidation();
		view->printTextMessage(View::OFFERING_TO_TYPE_TOP_RANGE_OF_FINDING);
		top_limit = doubleInputValueValidation();
		switch (criteria)
		{
		case 1:
		{
			std::vector<int> index = caravan->findPackagesByPrice(bottom_limit, top_limit);
			for (int i = 0; i < index.size(); i++)
				view->printPackage((*caravan->getCommodity())[i]);
			if (index.size() == 0)
				view->printTextMessage(View::NO_ELEMENTS_FOUNDED);
			break;
		}
		case 2:
		{	
			std::vector<int> index = caravan->findPackagesByWeight(bottom_limit, top_limit);
			for (int i = 0; i < index.size(); i++)
				view->printPackage((*caravan->getCommodity())[i]);
			if (index.size() == 0)
				view->printTextMessage(View::NO_ELEMENTS_FOUNDED);
			break;
		}
		case 3:
		{
			std::vector<int> index = caravan->findPackagesBySpace(bottom_limit, top_limit);
			for (int i = 0; i < index.size(); i++)
				view->printPackage((*caravan->getCommodity())[i]);
			if (index.size() == 0)
				view->printTextMessage(View::NO_ELEMENTS_FOUNDED);
			break;
		}
		default:
			break;
		}

		view->printTextMessage(View::BACK_OR_QUIT);
		int action;
		action = intInputValueValidation(1, 2);
		if (action == 1)
			processUser();
		else view->printTextMessage(View::PARTING);
		break;
	}
	case 4:
	{
		view->printTextMessage(View::PARTING);
		break;
	}
	}
	

}

void Controller::InitiallizeStartValues()
{	
	try
	{
		createCaravan();
		view->printTextMessage(View::GREETINGS_1);
	}
	catch (...)
	{
		throw;
	}	
}

int Controller::intInputValueValidation(int bottom_border, int top_border)
{
	int proper_int;
	for (;;)
	{
		if (std::cin >> proper_int)
		{	
			if (proper_int >= bottom_border && proper_int <= top_border)
				break;
			else
			{
				view->printTextMessage(View::ASKING_FOR_VALID_INTEGER);
				continue;
			}
		}
		else
		{
			view->printTextMessage(View::ASKING_FOR_VALID_INTEGER);
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return proper_int;
}

double Controller::doubleInputValueValidation()
{
	double proper_double;
	for (;;)
	{
		if (std::cin >> proper_double)
			break;
		else
		{
			view->printTextMessage(View::ASKING_FOR_VALID_DOUBLE);
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return proper_double;
}

rapidjson::Document Controller::parceJson(std::string wayToJsonFile)
{
	std::string parcingString;
	std::string buff;
	std::ifstream dataFile(wayToJsonFile);
	if (!dataFile.is_open())
	{
		throw 002;
	}

	while (std::getline(dataFile, buff))
	{
		parcingString += buff;
	}

	parcingString.erase(std::remove(parcingString.begin(), parcingString.end(), '\t'), parcingString.end());
	parcingString.erase(std::remove(parcingString.begin(), parcingString.end(), ' '), parcingString.end());

	rapidjson::Document document;
	if (document.Parse(parcingString.c_str()).HasParseError())
	{
		throw document.GetParseError();
	}
	else return document;
		
}


