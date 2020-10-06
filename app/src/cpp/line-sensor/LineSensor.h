#include <Arduino.h>

#ifndef LINESENSOR_H_INCLUDED
#define LINESENSOR_H_INCLUDED

class LineSensor
{
public:
    int pin;
    // Constructor to setup pin
    LineSensor(uint8_t sensorPin);

    // Getter for line sensor
    uint8_t getReading() const { return internalReading; };

    // Setter for line sensor
    // @param reading Reading from linesensor
    void setReading(uint8_t reading);

protected:
    int internalReading = 0;
};

#endif