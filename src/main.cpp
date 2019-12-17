#include "Simulation.h"

int main(){
    Simulation sim = Simulation(100, 1, 1E-4);
    sim.WriteFile();
    for(int i = 0; i < 500000 ; i++){
        sim.Simulate();
        if (i % 100 == 99) {
            sim.WriteFile();
            //sim.WriteFileDAT();
        }
    }
    return 0;
}