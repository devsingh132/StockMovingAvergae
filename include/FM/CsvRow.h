#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

#include "utils.h"

namespace csv_utils
{
	class CsvRow
	{
		public:
			/**
			 * Constructor.
			 * Header values are added as lower string.
			 */
			CsvRow(std::string line, std::vector<std::string>& header_row);

			/**
			 * @return
			 * Row data.
			 */
			std::unordered_map<std::string, std::string>& getRowData()
			{
				return _data;
			}

			std::string& operator[](std::string& s);
		private:
			std::unordered_map<std::string, std::string> _data;
	};
}

#include "CsvRow.cpp"
