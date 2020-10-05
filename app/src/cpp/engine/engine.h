#include <Arduino.h>
#include "../motor/motor.h"

#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

class Engine
{
public:
    // Left and right turn variables
    bool left = false, right = true;

    // Constructor
    Engine(Motor motorLeft, Motor motorRight);
    Engine() = default;

    // Drive motors either forwards if positive integer by @speed
    // or backwards for negative integer
    // @params speed - motor speed negative or positive
    void drive(int speed);

    // Puts both motors in standby
    void kill();

    // Turns the vehicle @amount of degrees in any angle
    // @params amount - Amount of turn in degrees
    // @params direction - Direction to turn with predefined variables
    //void turn(int amount, bool direction);

    // Vehicle stops and then turns @speed amount in @direction
    // @params speed - speed of wheel that turns
    // @params direction - Direction to turn with predefined variables
    void stopTurn(int speed, bool direction);

protected:
    Motor m_motorLeft, m_motorRight;
};

#endif