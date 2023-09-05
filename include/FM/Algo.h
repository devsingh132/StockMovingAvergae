#pragma once
#include "InputReader.h"
#include "AlgoConfig.h"

namespace Algo {
    class Algo
    {
    private:
        std::vector<std::string> instruments;
        AlgoConfig::AlgoConfig _config;
        Input::InputReader* closePrice;
        std::vector<double> position, stateVariables;
        std::ofstream ofs;
    public:
        Algo(AlgoConfig::AlgoConfig&& config, Input::InputReader* inputData);
        void run(int ti);
        void printOutput(int ti);
    };   
}

#include "Algo.cpp"