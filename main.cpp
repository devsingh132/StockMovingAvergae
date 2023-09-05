#include <bits/stdc++.h>
#include "InputReader.h"
#include "Simulator.h"

int main(int argc, char** argv) {
    std::string fileName(argv[1]);
    std::string configFile(argv[2]);
    Simulator::Simulator sim(configFile, fileName);
    sim.simulate();
    return 0;
}