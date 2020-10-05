#include "motor.h"

Motor::Motor(int pinIn1, int pinIn2, int pinPwm, int pinStby, int offset)
    : m_in1(pinIn1), m_in2(pinIn2), m_pwm(pinPwm), m_standby(pinStby), m_offset(offset)
{
    pinMode(m_in1, OUTPUT);
    pinMode(m_in2, OUTPUT);
    pinMode(m_pwm, OUTPUT);
    pinMode(m_standby, OUTPUT);
}

void Motor::drive(int speed)
{
    digitalWrite(m_standby, HIGH);
    speed = speed * m_offset;
    if (speed >= 0)
        forward(speed);
    else
        reverse(-speed);
}

void Motor::brake()
{
    digitalWrite(m_in1, HIGH);
    digitalWrite(m_in2, HIGH);
    analogWrite(m_pwm, 0);
}

void Motor::stop()
{
    digitalWrite(m_standby, LOW);
}

// Private

void Motor::forward(int speed)
{
    digitalWrite(m_in1, HIGH);
    digitalWrite(m_in2, LOW);
    analogWrite(m_pwm, speed);
}

void Motor::reverse(int speed)
{
    digitalWrite(m_in1, LOW);
    digitalWrite(m_in2, HIGH);
    analogWrite(m_pwm, speed);
}