#include "MotorController.h"

MotorController::MotorController(uint8_t pinIn1, uint8_t pinIn2, uint8_t pinPwm, uint8_t pinStby, int8_t offset)
    : m_in1(pinIn1), m_in2(pinIn2), m_pwm(pinPwm), m_standby(pinStby), m_offset(offset)
{
    pinMode(m_in1, OUTPUT);
    pinMode(m_in2, OUTPUT);
    pinMode(m_pwm, OUTPUT);
    pinMode(m_standby, OUTPUT);
}

void MotorController::drive(int16_t speed)
{
    digitalWrite(m_standby, HIGH);
    speed = speed * m_offset;
    if (speed >= 0)
        forward(speed);
    else
        reverse(-speed);
}

void MotorController::brake()
{
    digitalWrite(m_in1, HIGH);
    digitalWrite(m_in2, HIGH);
    analogWrite(m_pwm, 0);
}

void MotorController::stop()
{
    digitalWrite(m_standby, LOW);
}

// Private

void MotorController::forward(int16_t speed)
{
    digitalWrite(m_in1, HIGH);
    digitalWrite(m_in2, LOW);
    analogWrite(m_pwm, speed);
}

void MotorController::reverse(int16_t speed)
{
    digitalWrite(m_in1, LOW);
    digitalWrite(m_in2, HIGH);
    analogWrite(m_pwm, speed);
}