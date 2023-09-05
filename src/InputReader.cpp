#include "InputReader.h"

namespace Input {
    InputReader::InputReader(std::string& fileName) {
        std::ifstream ifs;
        ifs.open(fileName.c_str(), std::ifstream::in);
        if(!ifs.good()) {
            std::cout << "csv file not found: " + fileName << std::endl;
			exit(0);
        }
        std::string headerLine;
        getline(ifs, headerLine);
        std::stringstream lineStream(headerLine);
        std::string stock;
        while (getline(lineStream, stock, ','))
        {
            _header.push_back(stock);
        }
        _header[0] = TIMESTAMP;

        std::string line;
        int index = 0;
        while (getline(ifs, line))
        {
            _data.push_back(csv_utils::CsvRow(line, _header));
            time_t timeStamp = utils::getTimeStamp((_data.back())[_header[0]]);
            _timeIndex.push_back(timeStamp);
        }
    }

    std::vector<std::string>& InputReader::getHeader() {
        return _header;
    }

    csv_utils::CsvRow& InputReader::operator[](int i) {
        return _data[i];
    }

    int InputReader::getStartTimeIndex(time_t timeStamp) {

        return (std::lower_bound(_timeIndex.begin(), _timeIndex.end(), timeStamp) - _timeIndex.begin());
    };

    int InputReader::getEndTimeIndex(time_t timeStamp) {

        return (std::upper_bound(_timeIndex.begin(), _timeIndex.end(), timeStamp) - _timeIndex.begin());
    };
}