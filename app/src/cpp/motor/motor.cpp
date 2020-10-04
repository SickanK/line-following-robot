#include "motor.h"

Motor::Motor(int pin_in_1, int pin_in_2, int pin_pwm, int pin_stby, int offset)
{
    m_in_1 = pin_in_1;
    m_in_2 = pin_in_2;
    m_pwm = pin_pwm;
    m_standby = pin_stby;
    m_offset = offset;

    pinMode(m_in_1, OUTPUT);
    pinMode(m_in_2, OUTPUT);
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
    digitalWrite(m_in_1, HIGH);
    digitalWrite(m_in_2, HIGH);
    analogWrite(m_pwm, 0);
}

void Motor::stop()
{
    digitalWrite(m_standby, LOW);
}

// Private

void Motor::forward(int speed)
{
    digitalWrite(m_in_1, HIGH);
    digitalWrite(m_in_2, LOW);
    analogWrite(m_pwm, speed);
}

void Motor::reverse(int speed)
{
    digitalWrite(m_in_1, LOW);
    digitalWrite(m_in_2, HIGH);
    analogWrite(m_pwm, speed);
}