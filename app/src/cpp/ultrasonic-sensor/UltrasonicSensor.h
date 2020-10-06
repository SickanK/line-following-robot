#include <Arduino.h>

#ifndef ULTRASONICSENSOR_H_INCLUDED
#define ULTRASONICSENSOR_H_INCLUDED

class UltrasonicSensor
{
public:
    // Constructor that sets the correct pinmode
    UltrasonicSensor(uint8_t triggerPin, uint8_t echoPin, int16_t timeout);

    // Triggers ultrasonic sensor and returns value
    // @return Time it took for ultrasonic sensor to get back a result
    uint16_t trigger();

protected:
    uint8_t m_triggerPin, m_echoPin;
    uint16_t m_timeout, m_previousMicroseconds;
};

#endif