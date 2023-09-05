#include "Simulator.h"
#include "Algo.h"

namespace Simulator {
    Simulator::Simulator(std::string& filename, std::string& inputFileName) : _input(inputFileName) {
        std::ifstream ifs;
        ifs.open(filename.c_str(), std::ios_base::in);
        if(!ifs.good()) {
            std::cout << "Config file not found: " + filename << std::endl;
			exit(0);
        }
        std::string line;
        getline(ifs, line);
        std::stringstream ss(line);
        std::string configTime;

        getline(ss, configTime, ',');
        time_t startTime = utils::getTimeStamp(configTime);
        startIndex = _input.getStartTimeIndex(startTime);
        configTime = "";

        getline(ss, configTime, ',');
        time_t endTime = utils::getTimeStamp(configTime);
        endIndex = _input.getEndTimeIndex(endTime);

        while (getline(ifs, line))
        {
            algoConfigs.emplace_back(line);
        }
    };

    void Simulator::runSimulation(int simulationIndex) {
        Algo::Algo algo(std::move(algoConfigs[simulationIndex]), &_input);

        for (int ti = startIndex; ti < endIndex; ti++) {
            algo.run(ti);
            algo.printOutput(ti);
        }
        
    };

    void Simulator::simulate() {
        std::vector<std::thread> threads(algoConfigs.size());
        for (int i = 0; i < algoConfigs.size(); i++) {
            threads[i] = thread(&Simulator::runSimulation,this, i);
        }
        for (int i = 0; i < threads.size(); i++) {
            threads[i].join();
        }
        
    }
}