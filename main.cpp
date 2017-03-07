#include <iostream>
#include <vector>
#include "Component.h"
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
    // cout << argv[] << endl;
    int cycles, writes, volt;
    double iterations;
    if (argc != 5)
    {
	throw std::invalid_argument("Invalid amount of input arguments.");
    }
    for (int i{1}; i < argc; i++)
    {
	if (i == 1)
	{
	    cycles = atoi(argv[i]);
	    cout << "arg 1: " << cycles << endl;
	}
	else if (i == 3)
	{
//	    sscanf(argv[i],"%lf",&iterations); 
	    iterations = atof(argv[i]);
	    cout << "arg 2: " << iterations << endl;
	}
	else if (i == 4)
	{
	    volt = atoi(argv[i]);
	    cout << "arg 3: " << volt << endl;
	}
	else if (i == 2)
	{
	    writes = atoi(argv[i]);
	    cout << "arg 4: " << writes << endl;
	}
	else 
	{
	    cout << argv[i] << " Is not defined." << endl;
	    break;
	}
    }
    
    Connection p, n, Q124, Q23;
    vector<Component*> net; 
    net.push_back(new Battery("Bat", volt, p, n));
    net.push_back(new Resistor("R1", 6.0, p, Q124));
    net.push_back(new Resistor("R2", 8.0, Q124, Q23));
    net.push_back(new Resistor("R3", 8.0, Q23, n));
    net.push_back(new Resistor("R4", 8.0, Q124, n));
    //net.push_back(new Capacitor("C1",1 , q2 , n));
    simulate(net, cycles, volt, writes);


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
