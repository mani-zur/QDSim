#include "Simulation.h"
#include <iostream>
#include <math.h>

using namespace std;

Simulation::Simulation(int tN, int tn, double){
    N = tN; //N przedziałów
    n = tn; //n cząstek
    x = new double [N + 1];
    Fr = new double [N + 1];
    Fi = new double [N + 1];
    Hr = new double [N + 1];
    Hi = new double [N + 1];
    for (int i = 0; i <= N; i++)
    {
        x[i] = i * l/N;
        Fr[i] = sqrt(2) * sin(n * M_PI * x[i]);
        Fi[i] = 0;
    }
    cout << "Hello world" << endl;  
}

void Simulation::CalcultateHamiltonian(){
    Hr[0] = Hi[0] = Hr[N] = Hi[N] = 0;
    for (int i = 1; i < N; i++){
        Hr[i] = -0.5*(Fr[i+1]+Fr[i-1]-2*Fr[i])*N*N + K*(x[i]-0.5)*Fr[i]*sin(omega*tau);
        Hi[i] = -0.5*(Fi[i+1]+Fi[i-1]-2*Fi[i])*N*N + K*(x[i]-0.5)*Fi[i]*sin(omega*tau);
    }
}

Simulation::~Simulation(){
    delete [] x;
    delete [] Fr;
    delete [] Fi;
    delete [] Hr;
    delete [] Hi;
}