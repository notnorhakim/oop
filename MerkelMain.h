#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"
#include "Candlestick.h"

class Candlestick;

class MerkelMain
{
    public:
        MerkelMain();
        /** Call this to start the sim */
        void init();
    private: 
        // void printCandlestick(std::string product, std::string time);
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        int getUserOption();
        void processUserOption(int userOption);

        std::vector<Candlestick> generateCandlesticks();

        std::string currentTime;

        std::vector<std::string> allTime;

        std::vector<Candlestick> candlesticks;


        OrderBook orderBook{"20200601.csv"};

        Wallet wallet;

        

};
