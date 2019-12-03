#ifndef __Simulation__
#define __Simulation__

class Simulation
{
private:
    const double K = 0;
    const double omega = 0;
    const double tau = 0;
    double * x, * Fr, * Fi, * Hr, * Hi;
    int l, n ,N ;

public:
    Simulation(int tN, int tn, double tl);
    void CalcultateHamiltonian();
    ~Simulation();
};

#endif