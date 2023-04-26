#include "MerkelMain.h"
#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"

MerkelMain::MerkelMain()
{
    //constructor
}

void MerkelMain::init()
{

    loadOrderBook();
    int input;
    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::loadOrderBook()
{

    //add data to the object
    orders.push_back(OrderBookEntry{5319.450288, 0.00020075, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid});
    //add data to the object
    orders.push_back(OrderBookEntry{6319.450288, 0.02020075, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::ask});


    //print data from the object
    //the & means that we are passing the object by reference and not by value (which is the default) 
    //it is called an ampersand
    //this means that we are not making a copy of the object, but we are passing the actual object itself 
    //this is more efficient as we are not making a copy of the object
    //we are passing the object itself
    for (OrderBookEntry& order : orders)
    {
        std::cout << "Price: " << order.price << std::endl;
        std::cout << "Amount: " << order.amount << std::endl;
        std::cout << "Timestamp: " << order.timestamp << std::endl;
        std::cout << "Product: " << order.product << std::endl;
        std::cout << "OrderBookType: " << static_cast<int>(order.orderBookType) << std::endl;
    }

    //another way to print the data from the object
    //++i is more efficient than i++ as it does not make a copy of the object 
    for (unsigned int  i=0; i < orders.size(); ++i)
    {
        std::cout << "Price: " << orders[i].price << std::endl;
    }
}

void MerkelMain::printMenu()
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Make an offer " << std::endl;
    // 4 make a bid 
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;
    // 6 continue   
    std::cout << "6: Continue " << std::endl;

    std::cout << "============== " << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void  MerkelMain::printMarketStats()
{
    std::cout << "Order book contains : " << orders.size() << " entries" << std::endl;
}

void MerkelMain::enterOffer()
{
    std::cout << "Mark and offer - enter the amount " << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty. " << std::endl;
}
        
void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Going to next time frame. " << std::endl;
}
 
int MerkelMain::getUserOption()
{
    int userOption;

    std::cout << "Type in 1-6" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void MerkelMain::processUserOption(int userOption)
{
    if (userOption == 0) // bad input
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if (userOption == 1)
    {
        printHelp();
    }
    if (userOption == 2)
    {
        printMarketStats();
    }
    if (userOption == 3)
    {
        enterOffer();
    }
    if (userOption == 4)
    {
        enterBid();
    }
    if (userOption == 5)
    {
        printWallet();
    }
    if (userOption == 6)
    {
        gotoNextTimeframe();
    }       
}