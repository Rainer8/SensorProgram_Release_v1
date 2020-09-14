#include "ISensor.h"
#include <bitset>

//Mock Sensor that increases the depth until ~63m and slowly getting back to sea level
class FakeSensor : public ISensor {
public:

	FakeSensor() {
		this->val = 40;
		_ascending = true;
	}

	//Checks if altitude reaches the ~63m. If it does, _ascending is switched
	//to false and the sensor will start descending
	FakeSensor(int value) {
		this->val = value;
		if (value <= 7000)
			_ascending = true;
		else
			_ascending = false;
	}

	//METHOD FOR FAKING THE SENSOR SCANNING THE SEA BED
	int ReadSensor() const {
		int x;
		if ((this->val.to_ulong() >= 7000) && (_ascending == true))
			_ascending = false;
		else
			if ((this->val.to_ulong() <= 220) && (_ascending == false))
				_ascending = true;
		if (_ascending == true)
			x = (this->val.to_ulong() + rand() % 110);
		else
			x = (this->val.to_ulong() - rand() % 110);
		return x;
	}

	std::bitset<16> Read() const {
		this->val = ReadSensor();
		return this->val;
	}
};