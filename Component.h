#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include "stdafx.h"
#include <vector>

class Connection
{
public:
    double charge;
};

class Component
{
public:
    double get_voltage() const;
    virtual double get_current() const = 0;
    void simulate();
protected:
    Connection &a;
    Connection &b;
    std::string name;
public:
    Component(Connection & c1, Connection & c2, std::string const & n) 
	: a{ c1 }, b{ c2 }, name{ n } {};
    std::string get_name() const;
    virtual ~Component() = default;
};

class Resistor : public Component
{
public:
    Resistor(int resistance, Connection &c1, Connection &c2, std::string name) 
	: Component{ c1, c2, name }, resistance{ resistance } {};
    double get_current() const override;
private:
    int resistance;
};

class Capacitor : public Component
{
public:
    Capacitor(double farad, Connection &c1, Connection &c2, std::string name) 
	: Component{ c1, c2, name } {};
    double get_farad{ farad } {};
private:
    double farad;
};

class Battery : public Component
{
public:
    Battery(double voltage, Connection &c1, Connection &c2, std::string name) 
	: Component{ c1, c2, name }, voltage{ voltage } {};
private:
    double voltage;
};

#endif
