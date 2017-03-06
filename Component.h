#ifndef LIST_H
#define LIST_H

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
    string name;
    Component(Connection & c1,
	      Connection & c2,
	      string const & n)
	: a{c1}, b{c2}, name{n} {};
};

class Resistor : public Component
{
public:
    Resistor(double resistance,
	     Connection &c1,
	     Connection &c2,
	     string name) :
	Component{c1, c2, name},
	resistance{resistance} {};
    double get_current() const override;
private:
    int resistance;
}

class Capacitor : public Component
{
public:
    Capacitor (double farad,
	       Connection &c1,
	       Connection &c2,
	       string name) :
	Component{c1, c2, name},
	farad{farad} {};
private:
    double farad;
}

class Battery : public Component
{
public:
    Battery(double voltage,
	    Connection &c1,
	    Connection &c2,
	    string name) :
	Component{c1, c2, name},
	voltage{voltage};
private:
    double voltage;
}

#endif
