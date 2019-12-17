#include "Simulation.h"

using namespace std;

Simulation::Simulation(int tN, int tn, double dt){
    N = tN; //N przedziałów
    n = tn; //n cząstek
    tau = dt;
    x = new double [N + 1];
    Fr = new double [N + 1];
    Fi = new double [N + 1];
    Hr = new double [N + 1];
    Hi = new double [N + 1];
    for (int i = 0; i <= N; i++)
    {
        x[i] = (double)i/N;
        Fr[i] = sqrt(2) * sin(n * M_PI * x[i]);
        Fi[i] = 0;
    }
    CalcultateHamiltonian();
    file_out.open("bin/stats.out", ofstream::out | ofstream::trunc);
    file_dat.open("bin/stats.dat", ofstream::out | ofstream::trunc);
}

void Simulation::CalcultateHamiltonian(){
    Hr[0] = Hi[0] = Hr[N] = Hi[N] = 0;
    for (int i = 1; i < N; i++){
        Hr[i] = -0.5*(Fr[i+1]+Fr[i-1]-2*Fr[i])*N*N + K*(x[i]-0.5)*Fr[i]*sin(omega*t);
        Hi[i] = -0.5*(Fi[i+1]+Fi[i-1]-2*Fi[i])*N*N + K*(x[i]-0.5)*Fi[i]*sin(omega*t);
    }
}

void Simulation::Simulate(){
    for(int i = 0 ; i <= N; i++){
        Fr[i] += Hi[i]*tau/2;
    }
    CalcultateHamiltonian();
    for(int i = 0 ; i <= N; i++){
        Fi[i] -= Hr[i]*tau;
    }
    CalcultateHamiltonian();
    for(int i = 0 ; i <= N; i++){
        Fr[i] += Hi[i]*tau/2;
    }
    t += tau;
}

void Simulation::WriteFile(){
    double tmp_N = 0, tmp_x = 0, tmp_E = 0;
    for(int i = 0; i <= N; i++){
        tmp_N += Fr[i] * Fr[i] + Fi[i] * Fi[i]; 
        tmp_x += x[i] * (Fr[i] * Fr[i] + Fi[i] * Fi[i]);
        tmp_E += Fr[i] * Hr[i] + Fi[i] * Hi[i]; 
    }
    tmp_N = tmp_N /N;
    tmp_x = tmp_x /N;
    tmp_E = tmp_E /N;
    if (file_out.is_open()) file_out << t <<"," << tmp_N << "," << tmp_x << "," << tmp_E << endl;
    else cerr << "File error" << endl;
}

void Simulation::WriteFileDAT(){
    if (file_dat.is_open()){
        for( int i = 0; i <= N; i++){
            file_dat << Fr[i]*Fr[i] + Fi[i]*Fi[i] << ", \t";
        }
        file_dat << endl;
    }
}

Simulation::~Simulation(){
    delete [] x;
    delete [] Fr;
    delete [] Fi;
    delete [] Hr;
    delete [] Hi;
    file_out.close();
    file_dat.close();
}