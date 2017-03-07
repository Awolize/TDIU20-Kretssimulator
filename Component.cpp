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
    for (int j{0}; j < writes; j++){
	for( int i{0}; i < net.size();i++)
	{
	    net.at(i)->simulate(time);
	}
	cout << endl;
    }
}

std::string Component::get_name() const
{
    return std::string();
}

double Resistor::get_current(Connection & a, Connection & b, double time) const
{
    double current{0},diffrence{0};
    current = a.charge/resistance; 
    diffrence = a.charge-b.charge;
    b.charge = time * diffrence/resistance;
    return current;  
}

double Capacitor::get_current(Connection & a, Connection & b, double time) const
{
    return (a.charge-b.charge)*farad;
}

double Battery::get_current(Connection & a, Connection & b, double time) const
{
    a.charge = voltage;
    b.charge = 0;
    return 0.0;
}

void Battery::simulate(double time) const
{
    cout << setw(6) << setprecision(2) <<voltage << setw(6) << get_current(a,b,time);
}

void Resistor::simulate(double time) const
{
    cout << setw(6) << setprecision(2) <<  b.charge << setw(6) << get_current(a,b,time);
}

void Capacitor::simulate(double time) const
{
    cout << setw(6) << setprecision(2) << b.charge << setw(6) << get_current(a,b,time);
}
