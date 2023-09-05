#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

#define SIM_INDEX 0
#define ALGO_INDEX 1
namespace AlgoConfig {
    class AlgoConfig
    {
    private:
        std::string simulationName;
        std::string algoName;
        std::unordered_map<std::string, double> params;
    public:
        AlgoConfig(std::string input);
        std::string getSimName() { return simulationName;};
        std::string getAlgoName() { return algoName;};
        std::unordered_map<std::string, double>& getParmas() { return params;};
    };
}

#include "AlgoConfig.cpp"