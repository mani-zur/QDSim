#ifndef __Simulation__
#define __Simulation__

#include <fstream>
#include <iostream>
#include <math.h>

class Simulation
{
private:
    const double K = 1;
    const double omega = 1;
    const double tau = 1;
    double * x, * Fr, * Fi, * Hr, * Hi;
    double t = 0;
    int n ,N ;
    std::fstream file_out;
    std::fstream file_dat;
    void CalcultateHamiltonian();

public:
    Simulation(int tN, int tn);
    void Simulate(const double dt);
    void WriteFile();
    void WriteFileDAT();
    ~Simulation();
};

#endif