#include "engine.h"

Engine::Engine(Motor motorLeft, Motor motorRight)
    : m_motorLeft(motorLeft), m_motorRight(motorRight)
{
}

void Engine::drive(int speed)
{
    m_motorLeft.drive(speed);
    m_motorRight.drive(speed);
}

void Engine::kill()
{
    m_motorLeft.stop();
    m_motorRight.stop();
}

void Engine::stopTurn(int speed, bool direction)
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