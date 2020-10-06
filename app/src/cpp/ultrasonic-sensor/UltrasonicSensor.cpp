#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(uint8_t triggerPin, uint8_t echoPin, int16_t timeout)
    : m_triggerPin(triggerPin), m_echoPin(echoPin), m_timeout(timeout)
{
    pinMode(m_triggerPin, OUTPUT);
    pinMode(m_echoPin, INPUT);
}

uint16_t UltrasonicSensor::trigger()
{
    digitalWrite(m_triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(m_triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(m_triggerPin, LOW);

    m_previousMicroseconds = micros();
    while (!digitalRead(m_echoPin) && (micros() - m_previousMicroseconds) <= m_timeout)
        ;
    m_previousMicroseconds = micros();
    while (digitalRead(m_echoPin) && (micros() - m_previousMicroseconds) <= m_timeout)
        ;

    return micros() - m_previousMicroseconds;
}
