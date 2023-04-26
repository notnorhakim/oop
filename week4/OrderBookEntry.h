#include <string>
#pragma once

//create an enum class
enum class OrderBookType {bid, ask};

//create a class
class OrderBookEntry
{
    public:

        //declare the variables
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderBookType;

        //constructor
        OrderBookEntry(double price, double amount, std::string timestamp, std::string product, OrderBookType orderBookType);

};