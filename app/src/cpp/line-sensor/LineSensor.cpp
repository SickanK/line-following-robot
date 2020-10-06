#include "LineSensor.h"

LineSensor::LineSensor(uint8_t sensorPin)
    : m_pin(sensorPin)
{
    pinMode(sensorPin, INPUT);
}

void LineSensor::setReading()
{
    uint8_t reading = digitalRead(m_pin);
    if (reading == 0 || reading == 1)
        internalReading = reading;
};