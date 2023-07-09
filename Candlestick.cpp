#include "Candlestick.h"
#include "OrderBook.h"
#include <iostream>
#include <cmath>
#include <iomanip>



Candlestick::Candlestick(double _high, double _low, double _close, double _open, std::string _time)
    : high(_high), low(_low), close(_close), open(_open), time(_time)
{
 
}


void Candlestick::drawCandlestick(std::vector<Candlestick> candlesticks)
{
    double highest = 0;
    double lowest = 10000000000;
    double yaxis;
    double high;
    double low;
    double close;
    double open;
    int count = 1;

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
        }
        else
        {
            high = candlestick.high;
            low = candlestick.low;
            close = candlestick.close;
            open = candlestick.open;
        }


        std::cout << std::fixed << std::setprecision(9);
        // std::cout << beforeRound << std::endl;
        // std::cout << lengthBeforeRound << std::endl;
        // std::cout << "Round: " << round << std::endl;
        // std::cout << "lengthRound: " << lengthRound << std::endl;


        // std::cout << "Before" << std::endl;
        // std::cout << "High: " <<  std::fixed << std::setprecision(0) << high << std::endl;
        // std::cout << "Close: " << std::fixed << std::setprecision(0) << close << std::endl;
        // std::cout << "Open: " << std::fixed << std::setprecision(0) << open << std::endl;
        // std::cout << "Low: " << std::fixed << std::setprecision(0) << low << std::endl;
        // std::cout << std::endl;

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
        }


        high = static_cast<int>(std::floor(high));
        close = static_cast<int>(std::floor(close));
        open = static_cast<int>(std::floor(open));
        low = static_cast<int>(std::floor(low));

        candle.push_back(high);
        candle.push_back(close);
        candle.push_back(open);
        candle.push_back(low);

        std::cout << "============================================================= Candlestick #" << count << " =============================================================" << std::endl;
        std::cout << "High: " << std::fixed << std::setprecision(0) << high << std::endl;
        std::cout << "Close: " << std::fixed << std::setprecision(0) << close << std::endl;
        std::cout << "Open: " << std::fixed << std::setprecision(0) << open << std::endl;
        std::cout << "Low: " << std::fixed << std::setprecision(0) << low << std::endl;
        



        count++;
        candles.push_back(candle);
    }
    
    highest = highest * 100000000;
    lowest = lowest * 100000000;

    
    int roundedNumber1 = static_cast<int>(std::round(highest));
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

    std::cout << "---------------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Highest: " << highest << std::endl;
    std::cout << "Lowest: " << lowest << std::endl;
    std::cout << "Yaxis: " << yaxis << std::endl;
    std::cout << std::endl;

    



















    // for (int i = highest; i >= lowest; i--)
    // {
    //     for (int j = 0; j < candles.size(); j++)
    //     {
    //         if (candles[j][0] == i)
    //         {
    //             std::cout << "     |     ";
    //         }
    //         else if (candles[j][1] < i && i <= candles[j][0]){
    //             std::cout << "     |     ";
    //         }
    //         else if (i == candles[j][1])
    //         {
    //             std::cout << "     =     ";
    //         } 
    //         else if (candles[j][2] < i && i <= candles[j][1])
    //         {
    //             std::cout << "     =     ";
    //         }
    //         else if (i == candles[j][2])
    //         {
    //             std::cout << "     |     ";
    //         }
    //         else if (candles[j][3] < i && i <= candles[j][2])
    //         {
    //             std::cout << "     |     ";

    //         }




    //         else
    //         {
    //             std::cout << "           ";
    //         }


            
    //     }
    //     std::cout << std::endl;
        
    // }

}