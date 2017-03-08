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
    cout << endl;
    cycles = atoi(argv[1]);
    cout << "Cycles: " << cycles << ", ";

    writes = atoi(argv[2]);
    cout << "Writes: " << writes << ", ";
	    
    iterations = atof(argv[3]);
    cout << "Iterations: " << iterations << ", ";

    volt = atoi(argv[4]);
    cout << "Volt: " << volt << endl << endl;;
    
    Connection n, p, Q124, Q23;
    vector<Component*> net; 
    net.push_back(new Battery("Bat", volt, n, p));
    net.push_back(new Resistor("R1", 6.0, p, Q124));
    net.push_back(new Resistor("R2", 4.0, Q124, Q23));
    net.push_back(new Resistor("R3", 8.0, Q23, n));
    net.push_back(new Resistor("R4", 12.0, Q124, n));
    cout << "Krets 1: " << endl;
    simulate(net, cycles, writes, iterations);
    cout << "---------------------------------" << endl;
    cout << "|    Communism will prevail!    |" << endl;
    cout << "---------------------------------" << endl;
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
