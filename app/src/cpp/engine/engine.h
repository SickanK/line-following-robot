#include <Arduino.h>
#include "../motor-controller/MotorController.h"

#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

class Engine
{
public:
    // Left and right turn variables
    bool left = false, right = true;

    // Constructor
    Engine(MotorController motorLeft, MotorController motorRight);
    Engine() = default;

    // Drive motors either forwards or backwards
    // @param speed Motor speed negative or positive
    void drive(int16_t speed);

    // Puts both motors in standby
    void kill();

    // Turns the vehicle @amount of degrees in any angle
    // @param amount Amount of turn in degrees
    // @param direction Direction to turn
    //void turn(int amount, bool direction);

    // Vehicle stops and then turns @speed amount in @direction
    // @param speed Speed of wheel that turns
    // @param direction Direction to turn
    void stopTurn(int16_t speed, bool direction);

protected:
    MotorController m_motorLeft, m_motorRight;
};

#endif