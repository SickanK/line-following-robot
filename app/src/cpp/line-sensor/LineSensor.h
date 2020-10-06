#include <Arduino.h>

#ifndef LINESENSOR_H_INCLUDED
#define LINESENSOR_H_INCLUDED

class LineSensor
{
public:
    int pin;
    // Constructor to setup pin
    LineSensor(int sensorPin);

    // Getter for line sensor
    int getReading() const { return internalReading; };

    // Setter for line sensor
    // @param reading Reading from linesensor
    void setReading(int reading);

protected:
    int internalReading = 0;
};

#endif