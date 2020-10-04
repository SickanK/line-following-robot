#include <Arduino.h>

class Motor
{
public:
    // Constructor, sets up pins
    Motor(int pin_in_1, int pin_in_2, int pin_pwm, int pin_stby, int offset);
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
    int m_in_1, m_in_2, m_pwm, m_standby, m_offset;
};
