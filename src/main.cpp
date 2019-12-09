#include "Simulation.h"

int main(){
    Simulation sim = Simulation(100, 1);
    for(int i = 0; i < 50 ; i++){
        sim.Simulate(1E-3);
        sim.WriteFile();
        }
    return 0;
}