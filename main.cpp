#include <iostream>
#include <vector>
#include "Component.h"

using namespace std;

int main(int argc, char* argv[])
{
    // cout << argv[] << endl;
    int cycles, writes, volt;
    double iterations;
    for (int i{0}; i < argc; i++)
    {
	if (i == 1)
	{
	    cycles = *((int*)(&argv[i]));
	}
	else if (i == 2)
	{
	    iterations = *((double*)(&argv[i]));
	}
	else if (i == 3)
	{
	    volt = *((int*)(&argv[i]));
	}
	else if (i == 4)
	{
	    writes = *((int*)(&argv[i]));
	}
	else 
	{
	    cout << argv[i] << " Is not defined." << endl;
	    break;
	}
    }
    

  Connection p, n;
  vector<Component*> net;
  //net.push_back(new Battery("Bat", 24.0, p, n));
  //net.push_back(new Resistor("R1", 6.0, p, n));
  //net.push_back(new Resistor("R2", 8.0, p, n));
  //net.push_back(new Capacitor("C1", 0.0047, p , n));
  //simulate(net, cycles, volt, writes);
  
    
    
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




Bat. -> .R1. -> .bat
   . -> .R2. -> . 
*/
