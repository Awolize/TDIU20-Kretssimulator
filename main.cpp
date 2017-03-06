#include <iostream>
#include <vector>
#include "Component.h"

using namespace std;

int main(int argc, char* argv[])
{
    // cout << argv[] << endl;
    int cycles, writes, volt;
    double iterations;
    if (argc != 5)
	throw std::invalid_argument("Invalid amount of input arguments.");
    for (int i{1}; i < argc; i++)
    {
	if (i == 1)
	{
	    cycles = *((int*)(&argv[i]));
	    cout << "arg 1: " << cycles << endl;
	}
	else if (i == 2)
	{
	    iterations = (stod)argv[i];
	    cout << "arg 2: " << iterations << endl;
	}
	else if (i == 3)
	{
	    volt = *((int*)(&argv[i]));
	    cout << "arg 3: " << volt << endl;
	}
	else if (i == 4)
	{
	    writes = *((int*)(&argv[i]));
	    cout << "arg 4: " << writes << endl;
	}
	else 
	{
	    cout << argv[i] << " Is not defined." << endl;
	    break;
	}
    }
    
    Connection p, n, q, q1, q2;
    vector<Component*> net;
    net.push_back(new Battery("Bat", volt, p, n));
    net.push_back(new Resistor("R1", 6.0, p, q));
    net.push_back(new Resistor("R2", 8.0, q, q1));
    net.push_back(new Resistor("R2", 8.0, q1, q2));
    net.push_back(new Capacitor("C1", 0.0047, q2 , n));
//  simulate(net, cycles, volt, writes);


    cout << "\n\nPress \"Enter\" to continue...";
    std::cin.get();
    return 0;
}


/*
  Ett exempel: två parallellkopplade resistorer kan byggas upp och simuleras

  Connection p, n;
  vector<Component*> net;
  net.push_back(new Battery("Bat", 24.0, p, n));
  net.push_back(new Resistor("R1", 6.0, p, n));
  net.push_back(new Resistor("R2", 8.0, p, n));
  simulate(net, 10000, 10, 0.1);

*/
