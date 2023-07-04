#pragma once
#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"

class Candlestick
{
    public:
        Candlestick(double high, double low, double mean, std::string time) {
        // Initialize member variables with the provided values
        this->high = high;
        this->low = low;
        this->mean = mean;
        this->time = time;
    }

        //draw candlestick
        void drawCandlestick(std::vector<Candlestick> candlesticks);

    private:
        double high;
        double low;
        double mean;
        std::string time;

};

