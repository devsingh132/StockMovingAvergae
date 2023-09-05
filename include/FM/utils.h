#include <ctime>
#include <iostream>
#include <string>
using namespace std;

namespace utils {

    time_t getTimeStamp(std::string& timeStampStr){
        while (timeStampStr.size() > 0 && timeStampStr.back() == ' ')
        {
            timeStampStr.pop_back();
        }
        bool valid = true;
        struct tm tm = {0};
        strptime(timeStampStr.c_str(), "%F\t%H:%M:%S", &tm);
        time_t t = mktime(&tm);
        if(t<0) {
            std::cout<<"Invalid Data format: "<<timeStampStr<<" Use YYYY-mm-dd HH:MM:SS format"<<std::endl;
        }
        return t;
    }

}