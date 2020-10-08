#include <Arduino.h>

#ifndef MOTORCONTROLLER_H_INCLUDED
#define MOTORCONTROLLER_H_INCLUDED

class MotorController
{
public:
    // Constructor, sets up pins
    MotorController(uint8_t pinIn1, uint8_t pinIn2, uint8_t pinPwm, uint8_t pinStby, int8_t offset);
    MotorController() = default;

    // Drive motor forwards or backwards with offset in mind
    // @param speed MotorController speed
    void drive(int16_t speed);

    // Set motor speed to 0
    void brake();

    // Turn on standby mode
    void stop();

private:
    // Used in drive function
    // @param speed MotorController speed
    void forward(int16_t speed);
    void reverse(int16_t speed);

protected:
    // Pins
    uint8_t m_in1, m_in2, m_pwm, m_standby;
    int8_t m_offset;
};

#endif