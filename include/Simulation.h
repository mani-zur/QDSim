#ifndef __Simulation__
#define __Simulation__

#include <fstream>
#include <iostream>
#include <math.h>

class Simulation
{
private:
    const double K = 0;
    const double omega = 0;
    const double tau = 1;
    double * x, * Fr, * Fi, * Hr, * Hi;
    int n ,N ;
    std::fstream file;

public:
    Simulation(int tN, int tn);
    void CalcultateHamiltonian();
    void Simulate(const double dt);
    void WriteFile();
    ~Simulation();
};

#endif