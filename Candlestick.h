#pragma once
#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"

class Candlestick
{
    public:
        Candlestick(double _high, double _low, double close, double _open, std::string _time);

        //draw candlestick
        static void drawCandlestick(std::vector<Candlestick> candlesticks, std::string currentData);

        //draw bargraph
        static void drawBargraph(std::vector<Candlestick> candlesticks, std::string currentData);
    
        double high;
        double low;
        double close;
        std::string time;
        double open;

};

