#include "Component.h"
#include <iostream>
#include <vector>

double Component::get_voltage() const
{
    return 0.0;
}

void Component::simulate()
{
}

std::string Component::get_name() const
{
    return std::string();
}

double Resistor::get_current() const
{
    return 0;
}

double Capacitor::get_current() const
{
    return 0;
}

double Battery::get_current() const
{
    return 0;
}



