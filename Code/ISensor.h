#pragma once
#include <bitset>

//Interface for Real and Mock Sensor
class ISensor {
protected:
	mutable std::bitset<16> val;
	mutable bool _ascending;

public:
	virtual std::bitset<16> Read() const = 0;
};
