#include "View.h"
#include "Controller.h"
#include "Caravan.h"

int main()
{
	View view;
	Controller controller(&view);
	try
	{
		controller.InitiallizeStartValues();
	}
	catch (...)
	{
		view.printTextMessage(View::INITIALIZATION_ERROR);
		system("pause");
		return 1;
	}
	controller.processUser();

	system("pause");
	return 0;
}