#pragma once
#include "ConsoleLogger.h"
#include "SensorProcessor.h"
#include <chrono>
#include <thread>

//Application for running the app using the Real Sensor
class Application {
public:
	virtual void run() {
		ConsoleLogger logger;
		logger.print("Starting the app...");
		RealSensor real();
	}
};

//Derived app for running it in Debug mode using Mock sensor
class TestApplication : public Application {
public:

	std::string cut(float value) {
		std::string cutMessage = (std::to_string(value)).substr(0, 4);
		return cutMessage;
	}

	virtual void run() {
		ConsoleLogger logger; //Logging to Console
		logger.print("Starting the app...");
		FakeSensor mock; //Starting Mock Sensor
		logger.print("Real Sensor not found, simulating sensor...");
		SensorProcessor process(&mock);
		process.loadConfig();
		while (true) {
			std::string message = "Currently at the depth of " + cut(process.getDepth()) +
				" meters, having a pressure of " + cut(process.getAtmPressure())
				+ " atm / " + cut(process.getBarPressure()) + " bar.";
			logger.print(message);
			std::this_thread::sleep_for(std::chrono::milliseconds(970));
		}
	}
};