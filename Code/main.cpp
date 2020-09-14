#include "SurveySeabed.h"
#include "CheckRunCondition.h"

int main() {
	if (checkRunCondition() == true) //checking if user wants to start in Normal or Debug mode
	{
		TestApplication MockApp;
		MockApp.run();
	}
	else {

		Application RealApp;
		RealApp.run();
	}
	return 0;
}