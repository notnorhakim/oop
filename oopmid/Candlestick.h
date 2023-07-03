#pragma once
#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"

class Candlestick
{
    public:
        Candlestick(double _high, double _low, double _open, double _close, std::string _time);



        double high;
        double low;
        double open;
        double close;
        std::string time;

        //draw candlestick
        void drawCandlestick(std::vector<Candlestick> candlesticks);

    private:
        std::vector<Candlestick> candlesticks;
};

