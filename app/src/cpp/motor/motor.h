#include <Arduino.h>

#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED

class Motor
{
public:
    // Constructor, sets up pins
    Motor(int pinIn1, int pinIn2, int pinPwm, int pinStby, int offset);
    Motor() = default;

    // Drive motor forwards or backwards with offset in mind
    // @params speed - motor speed
    void drive(int speed);

    // Set motor speed to 0
    void brake();

    // Turn on standby mode
    void stop();

private:
    // Used in drive function
    // @params speed - motor speed
    void forward(int speed);
    void reverse(int speed);

protected:
    // Pins
    int m_In1, m_In2, m_pwm, m_standby, m_offset;
};

#endif