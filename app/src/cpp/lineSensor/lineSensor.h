#include <Arduino.h>

#ifndef LINESENSOR_H_INCLUDED
#define LINESENSOR_H_INCLUDED

class LineSensor
{
public:
    int pin;
    // Constructor to setup pin
    LineSensor(int sensorPin);

    // Get internal reading variable
    int getReading() const { return internalReading; };

    // Set internal reading variable
    // @params reading - reading value from sensor
    void setReading(int reading);

protected:
    int internalReading = 0;
};

#endif