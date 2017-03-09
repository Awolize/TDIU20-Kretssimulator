#include <iostream>
#include <vector>
#include "Component.h"
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
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
    net.clear();

    Connection n1,p1,l,r;
    net.push_back(new Battery("Bat", volt, n1, p1));
    net.push_back(new Resistor("R1", 150.0, p1, l));
    net.push_back(new Resistor("R2", 50.0, p1, r));
    net.push_back(new Resistor("R3", 100.0, r, l));
    net.push_back(new Resistor("R4", 300.0, l, n1));
    net.push_back(new Resistor("R5", 250.0, r, n1));
    cout << "Krets 2: " << endl;
    simulate(net, cycles, writes, iterations);
    net.clear();

    Connection n2,p2,l1,r1;
    net.push_back(new Battery("Bat", volt, n2, p2));
    net.push_back(new Resistor("R1", 150.0, p2, l1));
    net.push_back(new Resistor("R2", 50.0, p2, r1));
    net.push_back(new Capacitor("C3", 1.0, r1, l1));
    net.push_back(new Resistor("R4", 300.0, l1, n2));
    net.push_back(new Resistor("C5", .5, r1, n2));
    cout << "Krets 3: " << endl;
    simulate(net, cycles, writes, iterations);
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
