#pragma once
#include "View.h"
#include "Caravan.h"
#include <fstream>
#include <string.h>
#include "rapidjson\document.h"

class Controller
{

public:
	Controller(View *view);
	~Controller();
	void processUser();
	void InitiallizeStartValues();

private:
	View *view;
	Caravan *caravan;
	void createCaravan();
	double doubleInputValueValidation();
	int intInputValueValidation(int bottom_border, int top_border);
	rapidjson::Document parceJson(std::string wayToJsonFile);

};

