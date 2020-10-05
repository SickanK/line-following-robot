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

    // Drive motors either forwards or backwards
    // @param speed Motor speed negative or positive
    void drive(int speed);

    // Puts both motors in standby
    void kill();

    // Turns the vehicle @amount of degrees in any angle
    // @param amount Amount of turn in degrees
    // @param direction Direction to turn
    //void turn(int amount, bool direction);

    // Vehicle stops and then turns @speed amount in @direction
    // @param speed Speed of wheel that turns
    // @param direction Direction to turn
    void stopTurn(int speed, bool direction);

protected:
    Motor m_motorLeft, m_motorRight;
};

#endif