#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream> 
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
    Component(std::string const & new_name, Connection & n, Connection & p) 
	:  name{ new_name }, a{ n }, b{ p } {};
    std::string get_name() const;
    virtual ~Component() = default;
};

class Resistor : public Component
{
public:
    Resistor(std::string name, int resistance, Connection & n, Connection & p) 
	: Component{ name, n, p }, resistance{ resistance } {};
    double get_current() const override;
private:
    int resistance;
};

class Capacitor : public Component
{
public:
    Capacitor( std::string name, double farad, Connection & n, Connection & p) 
	: Component{ name, n, p } {};
    double get_farad() { return farad; };
    double get_current() const override;
private:
    double farad;
};

class Battery : public Component
{
public:
    Battery(std::string name, double voltage, Connection & n, Connection & p) 
	: Component{ name, n, p }, voltage{ voltage } {};
    double get_current() const override;
private:
    double voltage;
};

#endif
