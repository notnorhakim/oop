#include "Candlestick.h"
#include "OrderBook.h"
#include <iostream>
#include <cmath>
#include <iomanip>



Candlestick::Candlestick(double _high, double _low, double _close, double _open, std::string _time)
    : high(_high), low(_low), close(_close), open(_open), time(_time)
{
 
}

void Candlestick::drawBargraph(std::vector<Candlestick> candlesticks,std::string currentData)
{
    if (currentData == "no data loaded")
    {
        std::cout << std::endl;
        std::cout << "***** No data loaded. Enter 1 to load a data first. *****" << std::endl;
        return;
    }

    std::vector<double> bars;
    double highest = 0;
    double lowest = 10000000000;
    double range = 0;
    int divideCount = 0;
    bool isDecimal = false;
    int stringLength = 0;
    std::string spacing;

    for (Candlestick candlestick : candlesticks)
    {
        //close is the average price per unit in this time frame (same as Open, but for the current time frame)
 
        double bar = candlestick.close;
        int round = std::round(bar);
        int lengthRound = std::to_string(round).length();

        if (lengthRound == 1)
        {
            bar *= 1000000000;
            isDecimal = true;
        }
        else
        {
            bar *= 100;
        }

        std::cout << std::fixed << std::setprecision(0);
        int roundedNumber = static_cast<int>(std::round(bar));
        std::string highstr = std::to_string(roundedNumber);
        int numberLength = highstr.length();

        while (numberLength > 4) 
        {
            bar /= 10;
            numberLength--; 
            divideCount++;
        }
        if (bar > highest)
        {
            highest = bar;
        }
        if (bar < lowest)
        {
            lowest = bar;
        }

        bars.push_back(bar);

    }
    range = highest - lowest;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////draw bargraph///////////////////////////////////////////////////////////////////////////////////////////////
    // std::cout << "Range: " << range << std::endl;
    // std::cout << "Highest: " << highest << std::endl;
    // std::cout << "Lowest: " << lowest << std::endl;
    std::cout << std::endl;
    std::cout << "~~~~~~~~~~ Average Price per hour for [ " <<  currentData << " ] ~~~~~~~~~~" << std::endl;
    std::cout << std::endl;


    for (int i = highest; i >= lowest - range; i-- )
    {

        std::cout << std::fixed << std::setprecision(5);
        double steps = i;


        
        for (int j = 0; j < divideCount/candlesticks.size(); j++)
        {
            steps *= 10;
        }
        if (isDecimal)
        {
            steps /= 1000000000;
        }
        else
        {
            steps /= 100;
        }
        
        if (divideCount == 8) // to make the thousands number have no decimals
        {
            std::cout << std::fixed << std::setprecision(0);
            stringLength = (std::to_string(steps).length()) - 6; // to get the length of the number to insert the correct number of spaces so its aligned

        }
        else
        {
            std::cout << std::fixed << std::setprecision(8);
            stringLength = std::to_string(steps).length() + 3; // to get the length of the number to insert the correct number of spaces so its aligned
        }
        std::cout << steps << " | ";
        for (double bar : bars)
        {
            bar = std::round(bar);
            if (i <= bar)
            {
                std::cout << "    xxxx    ";
            }
            else
            {
                std::cout <<  "            ";
            }
        }
        std::cout << std::endl;
    }
    
    std::cout << "_______________________________________________________________________________" << std::endl;
    for (int i = 0; i < stringLength; i++)
    {
        spacing = spacing + " ";
    }
    std::cout << spacing << "|    11:00        12:00       13:00      14:00" << std::endl;
}

void Candlestick::drawCandlestick(std::vector<Candlestick> candlesticks,std::string currentData)
{
    double highest = 0;
    double lowest = 10000000000;
    double highestOri;
    double lowestOri;
    double yaxis;
    double high;
    double low;
    double close;
    double open;
    int count = 1;

    int divideCount = 0;
    bool isDecimal = false;
    int stringLength = 0;
    std::string spacing;
    
    if (currentData == "no data loaded")
    {
        std::cout << std::endl;
        std::cout << "***** No data loaded. Enter 1 to load a data first. *****" << std::endl;
        return;
    }
   

    std::vector<std::vector<double>> candles;

    for (Candlestick candlestick : candlesticks)
    {
        std::vector<double> candle;
        

        if (candlestick.high > highest)
        {
            highest = candlestick.high;
        }
        if (candlestick.low < lowest)
        {
            lowest = candlestick.low;
        }

        double beforeRound = candlestick.high;
        int lengthBeforeRound = std::to_string(beforeRound).length();

        int round = std::round(candlestick.high);
        int lengthRound = std::to_string(round).length();

        if (lengthRound == 1)
        {
            high = candlestick.high * 100000000;
            low = candlestick.low * 100000000;
            close = candlestick.close * 100000000;
            open = candlestick.open * 100000000;
            isDecimal = true;

        }
        else
        {
            high = candlestick.high * 100;
            low = candlestick.low * 100;
            close = candlestick.close * 100;
            open = candlestick.open * 100;
        }


        std::cout << std::fixed << std::setprecision(9);
        int roundedNumber = static_cast<int>(std::round(high));
        std::string highstr = std::to_string(roundedNumber);
        int numberLength = highstr.length();

        while (numberLength > 4) 
        {
            high /= 10;
            low /= 10;
            close /= 10;
            open /= 10;
            numberLength--; 
            divideCount++;

        }


        high = static_cast<int>(std::floor(high));
        close = static_cast<int>(std::floor(close));
        open = static_cast<int>(std::floor(open));
        low = static_cast<int>(std::floor(low));

        candle.push_back(high);
        candle.push_back(close);
        candle.push_back(open);
        candle.push_back(low);

        count++;
        candles.push_back(candle);
    }
    highestOri = highest;
    lowestOri = lowest;
    highest = highest * 100000000;
    lowest = lowest * 100000000;
    
    long long roundedNumber1 = static_cast<long long>(std::floor(highest));
    std::string higheststr = std::to_string(roundedNumber1);
    int numberLength = higheststr.length();

    while (numberLength > 4) 
    {
        highest /= 10;
        lowest /= 10;
        numberLength--;
    }

    highest = static_cast<int>(std::floor(highest));
    lowest = static_cast<int>(std::floor(lowest));


    yaxis = highest - lowest;


    
    std::cout << "======================================= [" << currentData << "] Candlestick Chart =======================================" << std::endl;
    std::cout << std::fixed << std::setprecision(9);
    // std::cout << "Highest: " << highestOri << std::endl;
    // std::cout << "Lowest: " << lowestOri << std::endl;
    std::cout << std::endl;
    
    //drawing a candlestick chart
    for (int i = highest; i >= lowest; i--)
    {
        std::cout << std::fixed << std::setprecision(5);
        double steps = i;

        for (int j = 0; j < divideCount/candlesticks.size(); j++)
        {
            steps *= 10;
        }
        if (isDecimal)
        {
            steps /= 100000000;
        }
        else
        {
            steps /= 100;
        }
        
        std::cout << std::fixed << std::setprecision(8);
        stringLength = std::to_string(steps).length() + 3; // to get the length of the number to insert the correct number of spaces so its aligned
        std::cout << steps << " | ";
        
        for (int j = 0; j < candles.size(); j++)
        {
            // //round all candles
            // candles[j][0] = std::round(candles[j][0]);
            // candles[j][1] = std::round(candles[j][1]);
            // candles[j][2] = std::round(candles[j][2]);
            // candles[j][3] = std::round(candles[j][3]);

            if (i <= candles[j][2] && i >= candles[j][1])
            {
                std::cout << "   =====   ";
            }
            else if (i == candles[j][1])
            {
                std::cout << "   =====   ";
            }
            else if (i >= candles[j][1] && i <= candles[j][0])
            {
                std::cout << "     |     ";
            }
            else if( i >= candles[j][2] && i <= candles[j][1])
            {
                std::cout << "   =====   ";
            }
            else if (i >= candles[j][3] && i <= candles[j][2])
            {
                std::cout << "     |     ";
            }
            else
            {
                std::cout << "           ";
            }
            
        }
        std::cout << std::endl;
    }
    std::cout << "_______________________________________________________" << std::endl;
    for (int i = 0; i < stringLength; i++)
    {
        spacing = spacing + " ";
    }
    std::cout << spacing << "|    11:00      12:00      13:00      14:00" << std::endl;


}