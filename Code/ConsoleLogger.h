#pragma once
#include "InterfaceLogger.h"
#include <iostream>

class ConsoleLogger : public ILogger {
public:

	void print(const std::string& message) {
		std::cout << std::endl << message;
	}
};
