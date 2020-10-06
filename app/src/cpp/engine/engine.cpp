#include "Engine.h"

Engine::Engine(MotorController motorLeft, MotorController motorRight)
    : m_motorLeft(motorLeft), m_motorRight(motorRight)
{
}

void Engine::drive(int16_t speed)
{
    m_motorLeft.drive(speed);
    m_motorRight.drive(speed);
}

void Engine::kill()
{
    m_motorLeft.stop();
    m_motorRight.stop();
}

void Engine::stopTurn(int16_t speed, bool direction)
{
    if (direction)
    {
        m_motorLeft.drive(speed);
        m_motorRight.drive(0);
    }
    else
    {
        m_motorLeft.drive(0);
        m_motorRight.drive(speed);
    }
}