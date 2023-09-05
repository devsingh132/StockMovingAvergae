#pragma once
#include "InputReader.h"
#include "AlgoConfig.h"
#include <thread>

namespace Simulator{
    class Simulator
    {
    private:
        Input::InputReader _input;
        int startIndex;
        int endIndex;
        std::vector<AlgoConfig::AlgoConfig> algoConfigs;
    public:
        Simulator(std::string& filename, std::string& inputFilenName);
        void simulate();
        void runSimulation(int simulationIndex);
    };
}

#include "Simulator.cpp"