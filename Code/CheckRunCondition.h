#pragma once
#include <sstream>
#include <fstream>

//Checking if app should be started in Normal or Debug mode
//Change config.cfg to "true" for debug mode or "false" for Normal mode
bool checkRunCondition() {
	std::ifstream fin("DebugMode.cfg");
	std::string line;
	std::getline(fin, line);
	std::istringstream sin(line.substr(line.find("=") + 1));
	if (line.find("true") != -1)
		return true;
	else
		return false;
}