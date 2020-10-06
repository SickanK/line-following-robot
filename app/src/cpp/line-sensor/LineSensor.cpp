#include "LineSensor.h"

LineSensor::LineSensor(uint8_t sensorPin)
    : pin(sensorPin)
{
    pinMode(sensorPin, INPUT);
}

void LineSensor::setReading(uint8_t reading)
{
    if (reading == 0 || reading == 1)
        internalReading = reading;
};