#include <Arduino.h>
#include "../motor/motor.h"

class Engine
{
public:
    // Constructor
    Engine(Motor motor_left, Motor motor_right);
    Engine() = default;

    // Drive motors either forwards if positive integer
    // or backwards for negative integer
    // @params speed - motor speed negative or positive
    void drive(int speed);

    // Puts both motors in standby
    void kill();

    // Turns the vehicle x amount of degrees in any angle
    // @params amount - Amount of turn in degrees
    // @params stop_to_turn - If vehicle should first stop then loop around itself
    // @params @direction - Direction to turn with predefined variables
    void turn(int amount, bool stop_to_turn, bool direction);

protected:
    Motor m_motor_left, m_motor_right;
    bool left = false, right = true;
};