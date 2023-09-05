#include "Algo.h"
#include "iomanip"

namespace Algo {
    Algo::Algo(AlgoConfig::AlgoConfig&& config, Input::InputReader* inputData): _config(config), closePrice(inputData) {
        std::string fileName = config.getSimName() + ".csv";
        ofs.open(fileName, std::ios_base::out);
        //Initialized stocks with all the columns
        if(instruments.size() == 0) {
            for (int i = 1; i < inputData->getHeader().size(); i++)
            {
                instruments.push_back(inputData->getHeader()[i]);
            }
        }
        //Print the header
        ofs<<",";
        for (int i = 0; i < instruments.size()-1; i++)
        {
            ofs<<instruments[i]<<",";
        }
        ofs<<instruments.back()<<"\n";
    };

    void Algo::run(int ti) {
        if (position.size() < instruments.size())
        {
            position.resize(instruments.size());
        }
        for (int index = 0; index < instruments.size(); index++) {
            std::string ii = instruments[index];
            if (ti<2 || (*closePrice)[ti-1][ii] == ""
                || (*closePrice)[ti-2][ii] == "") {
                
                position[index] = -1;
                
            } else {
                double d1 = std::stod((*closePrice)[ti-1][ii]);
                double d2 = std::stod((*closePrice)[ti-2][ii]);
                position[index] = -1*(d1 - d2)/d2*10000;
            }
        }
    }

    void Algo::printOutput(int ti) {
        //Print the time first;
        ofs<<(*closePrice)[ti][closePrice->getHeader()[0]]<<",";
        for (int index = 0; index < instruments.size(); index++) {
            std::string ii = instruments[index];
            if (!(ti<2 || (*closePrice)[ti-1][ii] == ""
                || (*closePrice)[ti-2][ii] == "")) {

                ofs<<std::setprecision(16)<<position[index];
            }
            if (index !=instruments.size() - 1)
            {
                ofs<<",";
            }
        }
        ofs<<"\n";
    }
}