#include "lineSensor.h"

LineSensor::LineSensor(int sensorPin)
: pin(sensorPin)
{
    pinMode(sensorPin, INPUT);
    
}

void LineSensor::setReading(int reading) 
{ 
    if(reading == 0 || reading == 1) 
        internal_reading = reading;
    
};