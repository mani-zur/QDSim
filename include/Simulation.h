#ifndef __Simulation__
#define __Simulation__

#include <fstream>
#include <iostream>
#include <math.h>

class Simulation
{
private:
    const double K = 0;//1;
    const double omega = 0;//(3*M_PI*M_PI)/2;
    double tau;
    double * x, * Fr, * Fi, * Hr, * Hi;
    double t = 0;
    int n ,N ;
    std::fstream file_out;
    std::fstream file_dat;
    void CalcultateHamiltonian();

public:
    Simulation(int tN, int tn, double dt);
    void Simulate();
    void WriteFile();
    void WriteFileDAT();
    ~Simulation();
};

#endif