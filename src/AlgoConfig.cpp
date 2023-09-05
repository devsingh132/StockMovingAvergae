#include "AlgoConfig.h"

namespace AlgoConfig {
    AlgoConfig::AlgoConfig(std::string input) {
        std::stringstream ss(input);
        std::vector<std::string> inputArr;
        std::string cell;
        while (getline(ss, cell, ','))
        {
            inputArr.push_back(cell);
        }
        
        simulationName = inputArr[SIM_INDEX];
        algoName = inputArr[ALGO_INDEX];
        int index = 2;
        while (index<inputArr.size())
        {
            params[inputArr[index]] = std::stod(inputArr[index + 1]);
            index+=2;
        }
    }
}