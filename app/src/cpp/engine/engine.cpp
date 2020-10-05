#include "engine.h"

Engine::Engine(Motor motor_left, Motor motor_right)
{
    m_motor_left = motor_left;
    m_motor_right = motor_right;
}

void Engine::drive(int speed)
{
    m_motor_left.drive(speed);
    m_motor_right.drive(speed);
}

void Engine::kill()
{
    m_motor_left.stop();
    m_motor_right.stop();
}

void Engine::stopTurn(int speed, bool direction)
{
    if(direction) 
    {
       m_motor_left.drive(speed);
       m_motor_right.drive(0);
    }
    else
    {
       m_motor_left.drive(0);
       m_motor_right.drive(speed);
    }
}