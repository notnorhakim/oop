#include "Candlestick.h"
#include "OrderBook.h"
#include <iostream>



Candlestick::Candlestick(double _high, double _low, double _open, double _close, std::string _time):
high(_high), 
low(_low), 
open(_open), 
close(_close),
time(_time)
{


}

void Candlestick::drawCandlestick(std::vector<Candlestick> candlesticks)
{

    for (Candlestick candlestick : candlesticks) 
    {
        double high = candlestick.high;
        double low = candlestick.low;
        double open = candlestick.open;
        double close = candlestick.close;
        double diff_h_c = high - close;
        double diff_c_o = close - open;
        double diff_o_l = open - low;
   
    for (int i = 0; i < diff_h_c; i++) {
        std::cout << "  |  " << std::endl;
    }

    for (int i = 0; i < diff_c_o; i++) {
        std::cout << "-----" << std::endl;
    }

    for (int i = 0; i < diff_o_l; i++) {
        std::cout << "  |  " << std::endl;
    }
    }
    
}