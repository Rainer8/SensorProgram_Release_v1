#pragma once
#include <string>

class ILogger {
public:
	virtual void print(const std::string& message)=0;
};
