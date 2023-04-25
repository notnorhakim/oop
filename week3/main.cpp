#include <iostream>
#include <string>
#include <vector>

//create an enum class
enum class OrderBookType {bid, ask};

//create a class
class OrderBookEntry
{
    public:

        //constructor
        OrderBookEntry(double price, double amount, std::string timestamp, std::string product, OrderBookType orderBookType)

        //initialise the variables
        : price(price), amount(amount), timestamp(timestamp), product(product), orderBookType(orderBookType)
        {
      
        }
        //store the data
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderBookType;

};

void printMenu()
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

void printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void  printMarketStats()
{
    std::cout << "Market looks good. " << std::endl;
}

void enterOffer()
{
    std::cout << "Mark and offer - enter the amount " << std::endl;
}

void enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void printWallet()
{
    std::cout << "Your wallet is empty. " << std::endl;
}
        
void gotoNextTimeframe()
{
    std::cout << "Going to next time frame. " << std::endl;
}
 
int getUserOption()
{
    int userOption;

    std::cout << "Type in 1-6" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void processUserOption(int userOption)
{
    if (userOption == 0) // bad input
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if (userOption == 1) // bad input
    {
        printHelp();
    }
    if (userOption == 2) // bad input
    {
        printMarketStats();
    }
    if (userOption == 3) // bad input
    {
        enterOffer();
    }
    if (userOption == 4) // bad input
    {
        enterBid();
    }
    if (userOption == 5) // bad input
    {
        printWallet();
    }
    if (userOption == 6) // bad input
    {
        gotoNextTimeframe();
    }       
}



int main()
{    

    //create an object
    std::vector<OrderBookEntry> orders;

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














    // double price = 5319.450228;
    // double amount = 0.00020075;
    // std::string timestamp{"2020/03/17 17:01:24.884492"};
    // std::string product{"BTC/USDT"};
    // //std::string orderType{"sell"};
    
    // OrderBookType orderBookType = OrderBookType::bid;

    // std::vector<double> prices;
    // std::vector<double> amounts;
    // std::vector<std::string> timestamps;
    // std::vector<std::string> products;
    // std::vector<OrderBookType> orderBookTypes;

    // //add data to vectors
    // prices.push_back(5000.01);
    // amounts.push_back(0.000232);
    // timestamps.push_back("2020/03/17 17:01:24.884492");
    // products.push_back("BTC/USDT");
    // orderBookTypes.push_back(OrderBookType::bid);

    // //add data to vectors
    // prices.push_back(300.01);
    // amounts.push_back(0.230232);
    // timestamps.push_back("2020/03/17 17:01:24.884492");
    // products.push_back("BTC/USDT");
    // orderBookTypes.push_back(OrderBookType::ask);

    // //print data from vectors
    // std::cout << "Price: " << prices[0] << std::endl;
    // std::cout << "Amount: " << amounts[0] << std::endl;
    // std::cout << "Timestamp: " << timestamps[0] << std::endl;
    // std::cout << "Product: " << products[0] << std::endl;





    // while (true)
    // {
    //     printMenu();
    //     int userOption = getUserOption();
    //     processUserOption(userOption);
    // }
    return 0;
}

