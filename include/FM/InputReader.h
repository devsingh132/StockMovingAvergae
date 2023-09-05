#pragma once
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "CsvRow.h"

#define TIMESTAMP "TIMESTAMP"

namespace Input {
    class InputReader
    {
    private:
        std::vector<csv_utils::CsvRow> _data;
        std::vector<time_t> _timeIndex;
        std::vector<std::string> _header;
    public:
        InputReader(std::string& fileName);
        std::vector<std::string>& getHeader();
        int getStartTimeIndex(time_t timeStamp);
        int getEndTimeIndex(time_t timeStamp);
        csv_utils::CsvRow& operator[](int i);
    };
}

#include "InputReader.cpp"