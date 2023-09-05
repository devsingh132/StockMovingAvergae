#include "CsvRow.h"


namespace csv_utils
{

  CsvRow::CsvRow (std::string line, std::vector<std::string> & header_row)
  {
    std::stringstream lineStream (line);
    std::string cell;

    _data.clear ();
    int index = 0;
    while (!lineStream.eof() && !line.empty())
      {
        getline (lineStream, cell, ',');
        std::string header = header_row[index];
        _data.insert(std::pair<std::string, std::string> (header, cell));
        index++;
      }
  }

  std::string& CsvRow::operator[](std::string& s){
      if (_data.find(s) == _data.end())
      {
          std::cout<<s<<" Not in input data"<<std::endl;
      }
      return _data.at(s);
      
  };
}
