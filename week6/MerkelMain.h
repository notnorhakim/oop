//a header is to declare the class and its members and functions, but not define them.
//The definition of a class is done in a .cpp file.
//The header file is included in the .cpp file to provide the declarations for the .cpp file.
//The header guards prevent the contents of the header from being defined multiple times where it is included.
//The #pragma once is a non-standard but widely supported preprocessor directive designed to cause the current source file to be included only once in a single compilation.
//The #pragma once directive is used to avoid the problem of double inclusion when dealing with the include files.

#pragma once

#include <vector>
#include "OrderBookEntry.h"

class MerkelMain
{
    public:
        MerkelMain();
        /** Call this to start the sim */
        void init();
    private: 
        void loadOrderBook();
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterOffer();
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        int getUserOption();
        void processUserOption(int userOption);


        std::vector<OrderBookEntry> orders;

};