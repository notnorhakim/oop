#pragma once
#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"

class Candlestick
{
    public:
        Candlestick(double _high, double _low, double _mean, double _prevMean, std::string _time);

        //draw candlestick
        static void drawCandlestick(std::vector<Candlestick> candlesticks);

    
        double high;
        double low;
        double mean;
        std::string time;
        double prevMean;

};

