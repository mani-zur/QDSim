#include "Simulation.h"

int main(){
    Simulation sim = Simulation(100, 1);
    sim.WriteFile();
    for(int i = 0; i < 50000 ; i++){
        sim.Simulate(1E-5);
        sim.WriteFileDAT();
        if (i % 100 == 99) sim.WriteFile();
    }
    return 0;
}