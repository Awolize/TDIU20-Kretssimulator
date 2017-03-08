#include "Component.h"
#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

double Component::get_voltage() const
{
    return 0.0;
}

void simulate(vector<Component*> net,int cycles, int writes, double time)
{
    


    for ( int i{0}; i < net.size(); i++)
    {
	cout << setw(12) << setfill(' ') << net.at(i)->name;
    } 
    cout << endl;  

    for ( int i{0}; i < net.size(); i++)
    {
	cout << setw(12) << "Volt Curr" ;
    } 
    cout << endl;
    for (int j{0}; j < cycles; j++)
    {
        for( int i{0}; i < net.size();i++)
	{
	    net.at(i)->simulate(time);
	}
    }
    for (int j{0}; j < writes; j++)
    { 
	cout << "  ";
	for( int i{0}; i < net.size();i++)
	{
	    cout << setw(4) << fixed << setprecision(2) << net.at(i)->get_voltage() << " ";
	    cout << setw(4) << fixed << setprecision(2) << net.at(i)->get_current() << "  ";

	    if (i+1 != net.size())
	    {
		if (net.at(i+1)->get_voltage() < 10)
		{
		    cout << " ";
		}
	    }
	}
	cout << endl;
    }
}

std::string Component::get_name() const
{
    return std::string();
}

double Resistor::get_current() const
{
    return ((a.charge - b.charge) / resistance);  
}

double Capacitor::get_current() const
{
    return current;
}

double Battery::get_current() const
{
    return current;
}

double Resistor::get_voltage() const
{
    return (a.charge - b.charge); 
}

double Capacitor::get_voltage() const
{
    return voltage;
}

double Battery::get_voltage() const
{
    return voltage;
}

void Battery::simulate(double time) 
{
    a.charge = 0;
    b.charge = voltage;
}

void Resistor::simulate(double time) 
{
    b.charge = (time * ((a.charge-b.charge)/resistance));
    a.charge = (a.charge - b.charge);
}

void Capacitor::simulate(double time) 
{
    
}
