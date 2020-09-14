#pragma once
#include "FakeSensor.h"
#include "RealSensor.h"
#include "Config.h"
#include <iostream>
#include <fstream>
#include <sstream>

//Data Processing for sensors
class SensorProcessor {
public:
	Config config;
	SensorProcessor(const ISensor* connection) :_sensor(connection) {}
	const ISensor* _sensor;
	std::bitset<16> Read() const { return _sensor->Read(); }

	void loadConfig() {
		std::ifstream fin("config.cfg");
		std::string line;
		while (std::getline(fin, line)) {
			std::istringstream sin(line.substr(line.find("=") + 1));
			if (line.find("density") != -1)
				sin >> config.density;
			else if (line.find("gravity") != -1)
				sin >> config.gravity;
			else if (line.find("barDivider") != -1)
				sin >> config.barDivider;
			else if (line.find("atmDivider") != -1)
				sin >> config.atmDivider;
			else if (line.find("maxBits") != -1)
				sin >> config.maxBits;
		}
	}

	float getDepth() {
		float ExactDepthValue = (_sensor->Read().to_ulong() * 600) / config.maxBits;
		float DepthValue = ExactDepthValue;
		return DepthValue;
	}

	float getkPaPressure() {
		float kPaPressure = this->getDepth() * config.density * config.gravity;
		return kPaPressure;
	}

	float getBarPressure() {
		float BarPressure = (this->getkPaPressure() / config.barDivider);
		return BarPressure;
	}

	float getAtmPressure() {
		float AtmPressure = (this->getkPaPressure() / config.atmDivider);
		return AtmPressure;
	}
};