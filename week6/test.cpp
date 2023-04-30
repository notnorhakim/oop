#include <string>
#include <iostream>
#include <vector>
#include <fstream>

//this defines a function that takes a string and a char and returns a vector of strings
//it is not a defining a variable called tokenise
//the function is called tokenise
//the reason its like this is because to return a vector, which is a complex type, it needs to be std::vector<std::string> tokenise() and not int tokenise()
std::vector<std::string> tokenise(std::string csvLine, char separator)
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

int main()
{
    // std::string csvLine = "1000,0.02,2020/03/17 17:01:24.884492,BTC/USDT,bid";

    // std::vector<std::string> tokens = tokenise(csvLine, ',');
    // for(std::string& token : tokens)
    // {
    //     std::cout << token << std::endl;
    // }

    std::ifstream csvFile{"20200317.csv"};
    std::string line;
    std::vector<std::string> tokens;

    if (csvFile.is_open())
    {

        std::cout << "File opened successfully" << std::endl;

        while(std::getline(csvFile, line))
        {
            std::cout << line << std::endl;
            tokens = tokenise(line, ',');
            if (tokens.size() != 5)
            {
                std::cout << "Error: tokens.size() != 5" << std::endl;
                continue;
            }
            try
            {
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);
                std::cout << "Price: " << price << std::endl;
                std::cout << "Amount: " << amount << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cout << "Bad float" << std::endl;
                continue;
            }
            

            

        }
        
        csvFile.close();
    }
    else
    {
        std::cout << "File not opened successfully" << std::endl;
    }





    return 0;
}