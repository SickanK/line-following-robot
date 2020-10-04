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

void Engine::turn(int amount, bool stop_to_turn, bool direction)
{
    // in progress
}