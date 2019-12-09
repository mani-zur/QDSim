#include "Simulation.h"

using namespace std;

Simulation::Simulation(int tN, int tn){
    N = tN; //N przedziałów
    n = tn; //n cząstek
    x = new double [N + 1];
    Fr = new double [N + 1];
    Fi = new double [N + 1];
    Hr = new double [N + 1];
    Hi = new double [N + 1];
    for (int i = 0; i <= N; i++)
    {
        x[i] = (double)i/N;
        Fr[i] = sqrt(2) * sin(n * M_PI * x[i]);
        cout << x[i]  << " : "<< Fr[i] << endl;
        Fi[i] = 0;
    }
    CalcultateHamiltonian();
    file.open("bin/stats.out", ofstream::out | ofstream::trunc);
}

void Simulation::CalcultateHamiltonian(){
    Hr[0] = Hi[0] = Hr[N] = Hi[N] = 0;
    for (int i = 1; i < N; i++){
        Hr[i] = -0.5*(Fr[i+1]+Fr[i-1]-2*Fr[i])*N*N + K*(x[i]-0.5)*Fr[i]*sin(omega*tau);
        Hi[i] = -0.5*(Fi[i+1]+Fi[i-1]-2*Fi[i])*N*N + K*(x[i]-0.5)*Fi[i]*sin(omega*tau);
    }
}

void Simulation::Simulate(const double dt){
    for(int i = 0 ; i <= N; i++){
        Fr[i] += Hi[i]*dt/2;
    }
    CalcultateHamiltonian();
    for(int i = 0 ; i <= N; i++){
        Fi[i] -= Hr[i]*dt;
    }
    CalcultateHamiltonian();
    for(int i = 0 ; i <= N; i++){
        Fr[i] += Hi[i]*dt/2;
    }
}

void Simulation::WriteFile(){
    double tmp_N = 0, tmp_x = 0, tmp_E = 0;
    cout << tmp_N << endl;
    for(int i = 0; i <= N; i++){
        tmp_N += Fr[i] * Fr[i] + Fi[i] * Fi[i]; 
        tmp_x += x[i] * (Fr[i] * Fr[i] + Fi[i] * Fi[i]);
        tmp_E += Fr[i] * Hr[i] + Fi[i] * Hi[i]; 
    }
    tmp_N = tmp_N /N;
    tmp_x = tmp_x /N;
    tmp_E = tmp_E /N;
    if (file.is_open()) file << tmp_N << "," << tmp_x << "," << tmp_E << endl;
    else cerr << "File error" << endl;
}

Simulation::~Simulation(){
    delete [] x;
    delete [] Fr;
    delete [] Fi;
    delete [] Hr;
    delete [] Hi;
    file.close();
}