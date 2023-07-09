#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include "Candlestick.h"
#include "OrderBook.h"
#include <cmath>
#include <iomanip>

MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{
    int input;
    currentTime = orderBook.getEarliestTime();

    wallet.insertCurrency("BTC", 10);

    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}


void MerkelMain::printMenu()
{

    // 1 print Candlestick
    std::cout << "1: Compute CandleStick " << std::endl;
    // 2 print exchange stats
    // std::cout << "2: Print exchange stats" << std::endl;
    // 6 continue   
    std::cout << "6: Change Candlestick " << std::endl;
    // 7 Sample Candlestick
    std::cout << "7: Generate Candlestick " << std::endl;

    std::cout << "============== " << std::endl;

}

void MerkelMain::printMenu2()
{
    // 6 continue
    std::cout << "6: Continue " << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void MerkelMain::printMarketStats()
{

    allTime = orderBook.getAllTimes();


    for (int i = 0; i < allTime.size(); i++)
    {
        std::cout << "=========================== Time Stamp: " << allTime[i] << ":00:00 ===========================" << std::endl;

        for (std::string const& p : orderBook.getKnownProducts())
        {
            std::vector<OrderBookEntry> entries_ask = orderBook.getOrders(OrderBookType::ask, p, allTime[i]);
            std::vector<OrderBookEntry> entries_bid = orderBook.getOrders(OrderBookType::ask, p, allTime[i]);

            std::cout << "Product:      " << p << '\n';
            std::cout << "Asks seen:    " << entries_ask.size() << '\n';
            std::cout << "Bids seen:    " << entries_bid.size() << '\n';
            std::cout << "Max ask:      " << OrderBook::getHighPrice(entries_ask) << '\n';
            std::cout << "Min ask:      " << OrderBook::getLowPrice(entries_bid) << '\n';
            std::cout << '\n';

        }
    }



    

}

void MerkelMain::enterAsk()
{
    std::cout << "Make an ask - enter the amount: product,price, amount, eg  ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "MerkelMain::enterAsk Bad input! " << input << std::endl;
    }
    else {
        try {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2], 
                currentTime, 
                tokens[0], 
                OrderBookType::ask 
            );
            obe.username = "simuser";
            if (wallet.canFulfillOrder(obe))
            {
                std::cout << "Wallet looks good. " << std::endl;
                orderBook.insertOrder(obe);
            }
            else {
                std::cout << "Wallet has insufficient funds . " << std::endl;
            }
        }catch (const std::exception& e)
        {
            std::cout << " MerkelMain::enterAsk Bad input " << std::endl;
        }   
    }
}

void MerkelMain::enterBid()
{
    std::cout << "Make an bid - enter the amount: product,price, amount, eg  ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "MerkelMain::enterBid Bad input! " << input << std::endl;
    }
    else {
        try {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2], 
                currentTime, 
                tokens[0], 
                OrderBookType::bid 
            );
            obe.username = "simuser";

            if (wallet.canFulfillOrder(obe))
            {
                std::cout << "Wallet looks good. " << std::endl;
                orderBook.insertOrder(obe);
            }
            else {
                std::cout << "Wallet has insufficient funds . " << std::endl;
            }
        }catch (const std::exception& e)
        {
            std::cout << " MerkelMain::enterBid Bad input " << std::endl;
        }   
    }
}

void MerkelMain::printWallet()
{
    std::cout << wallet.toString() << std::endl;
}
        
void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Changing new Candlestick...... " << std::endl;
    // remove all contents of candlesticks vector
    candlesticks.clear();
    candlesticks.clear();

    
}

std::vector<Candlestick> MerkelMain::generateCandlesticks()
{
    std::cout << "Which product would you like to see? e.g ETH/BTC" << std::endl;
    std::string inputProduct;
    std::getline(std::cin, inputProduct);
    std::cout << "What order type? e.g ask" << std::endl;
    std::string inputOrderType;
    OrderBookType inputType;
    std::getline(std::cin, inputOrderType);
    if (inputOrderType != "ask" && inputOrderType != "bid")
    {
        std::cout << "Invalid order type. Choose ask or bid" << std::endl;
    }
    else if (inputOrderType == "ask")
    {
        inputType = OrderBookType::ask;
    }
    else if (inputOrderType == "bid")
    {
        inputType = OrderBookType::bid;
    }

    allTime = orderBook.getAllTimes();

    double totalValue = 0;
    double totalAmount = 0;
    double high = 0;
    double low;
    double open =0;
    

    for (int i = 0; i < allTime.size(); i++)
    {
        std::vector<OrderBookEntry> ordersCandlestick = orderBook.getOrders(inputType, inputProduct, allTime[i]);
        std::cout << "=========================== CandleStick #" << i + 1 <<  " [ " << allTime[i] << ":00:00 ] ===========================" << std::endl;

        

        for (int i = 0; i < ordersCandlestick.size(); i++)
        {
            
            // std::string date = ordersCandlestick[i].timestamp;
            double price = ordersCandlestick[i].price;
            double amount = ordersCandlestick[i].amount;
            double value = price * amount;
            low = ordersCandlestick[0].price;


            if (price > high)
            {
                high = price;
            }
            if (price < low)
            {
                low = price;
            }
            totalValue += value;
            totalAmount += amount;
                        
        }

        double close = totalValue / totalAmount;

        
        std::cout << "                                    Total of " << ordersCandlestick.size() << " orders                                  " << std::endl;
        std::cout << "Order Type:    " << inputOrderType << std::endl;
        std::cout << "Product:       " << inputProduct << std::endl;
        std::cout << std::fixed << std::setprecision(9);
        std::cout << "OPEN:          " << open << std::endl;
        std::cout << "CLOSE:         " << close << std::endl;
        std::cout << "HIGH:          " << high << std::endl;
        std::cout << "LOW:           " << low << std::endl;
        std::cout << std::endl;

        Candlestick candle = Candlestick(high, low, close, open, allTime[i]);

        candlesticks.push_back(Candlestick(high, low, close, open, allTime[i]));
        open = close;

        

    }

    // std::cout << "========================================== [ SUMMARY ] ==========================================" << std::endl;
    // std::cout << "Date                         Open          Close          High          Low" << std::endl;
    // std::cout << candlesticks[0].time << ":00:00          " << candlesticks[0].open << "          " << candlesticks[0].close << "          " << candlesticks[0].high << "          " << candlesticks[0].low << std::endl;
    // std::cout << candlesticks[1].time << ":00:00          " << candlesticks[1].open << "          " << candlesticks[1].close << "          " << candlesticks[1].high << "          " << candlesticks[1].low << std::endl;
    // std::cout << candlesticks[2].time << ":00:00          " << candlesticks[2].open << "          " << candlesticks[2].close << "          " << candlesticks[2].high << "          " << candlesticks[2].low << std::endl;
    // std::cout << candlesticks[3].time << ":00:00          " << candlesticks[3].open << "          " << candlesticks[3].close << "          " << candlesticks[3].high << "          " << candlesticks[3].low << std::endl;
    // std::cout << std::endl;

    return candlesticks;


}
 
int MerkelMain::getUserOption()
{
    int userOption = 0;
    std::string line;
    std::cout << "Type in 1-6" << std::endl;
    std::getline(std::cin, line);
    try{
        userOption = std::stoi(line);
    }catch(const std::exception& e)
    {
        // 
    }
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
        // printHelp();
        generateCandlesticks();
        // Candlestick::drawCandlestick(candlesticks);

    }
    if (userOption == 2) 
    {
        printMarketStats();
    }
    if (userOption == 3) 
    {
        enterAsk();
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
    if (userOption == 7) 
    {
        // text-based plot of candlestick data
        // std::cout << "_____________________________________________________" << std::endl;
        // std::cout << "  |  " << "          " << "  |  " << std::endl;
        // std::cout << "  |  " << "          " << "  |  " << std::endl;
        // std::cout << "  |  " << "          " << "  |  " << std::endl;
        // std::cout << "  |  " << "          " << "  |  " << std::endl;
        // std::cout << "=====" << "          " << "  |  " << std::endl;
        // std::cout << "=====" << "          " << "  |  " << std::endl;
        // std::cout << "=====" << "          " << "  |  " << std::endl;
        // std::cout << "=====" << "          " << "  |  " << std::endl;
        // std::cout << "  |  " << "          " << "=====" << std::endl;
        // std::cout << "  |  " << "          " << "=====" << std::endl;
        // std::cout << "  |  " << "          " << "=====" << std::endl;
        // std::cout << "  |  " << "          " << "  |  " << std::endl;
        // std::cout << "_____________________________________________________" << std::endl;

        
        //draw candlestick
        Candlestick::drawCandlestick(candlesticks);      

    }         
}

