#include "OrderBookEntry.h"
#pragma once
#include <vector>
#include <string>

class CSVReader
{
    public:
        CSVReader();

        static std::vector<OrderBookEntry> readCSV(std::string csvFile);

    private:
        static std::vector<std::string> tokenise(std::string csvLine, char separator);
        static OrderBookEntry stringstoOBE(std::vector<std::string> strings);
};