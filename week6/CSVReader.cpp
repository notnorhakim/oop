#include "CSVReader.h"
#include <iostream>
#include <fstream>

CSVReader::CSVReader()
{

}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFilename)
{
    std::vector<OrderBookEntry> entries;

    std::ifstream csvFile{csvFilename};
    std::string line;
    if(csvFile.is_open())
    {
        while(std::getline(csvFile, line))
        {
            try 
            {
            OrderBookEntry obe = stringstoOBE(tokenise(line, ','));
            entries.push_back(obe);
            } catch(const std::exception& e)
            {
                std::cout << "Bad Data " << std::endl;
            }
        }//end of while

    }
    std::cout << "CSVReader::readCSV read " << entries.size() << " entries." << std::endl;
    return entries;
}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;
    start = csvLine.find_first_not_of(separator, 0);
    do
    {
        end = csvLine.find_first_of(separator, start);

        //this line checks if the end is at the end of the string or if the end is at the start of the string
        if(start == csvLine.length() || start == end) break;
        
        if(end >= 0) token = csvLine.substr(start, end - start);

        else token = csvLine.substr(start, csvLine.length() - start);

        tokens.push_back(token);

        start = end + 1;

    }while(end != std::string::npos);

    return tokens;
}

OrderBookEntry CSVReader::stringstoOBE(std::vector<std::string> tokens)
{


    double price, amount;

    if (tokens.size() != 5)
        {
            std::cout << "Error: tokens.size() != 5" << std::endl;
            throw std::exception{};
        }
        try
        {
            price = std::stod(tokens[3]);
            amount = std::stod(tokens[4]);
        }
        catch(const std::exception& e)
        {
            std::cout << "Bad float" << std::endl;
            throw;
        }
    OrderBookEntry obe {price, amount,tokens[0], tokens[1], OrderBookEntry::stringToOrderBookType(tokens[2]) };
    return obe;
}