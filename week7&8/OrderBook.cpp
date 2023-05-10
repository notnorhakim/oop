#include "OrderBook.h"
#include "CSVReader.h"
#include <map>
#include <algorithm>


/** construct, reading a csv data file*/
OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
}
/** return vector of all known products in the dataset */
std::vector<std::string> OrderBook::getKnownProducts()
{
    std::vector<std::string> products;
    std::map<std::string, bool> prodMap;

    for (OrderBookEntry& e : orders)
    {
        prodMap[e.product] = true;
    }

    for (auto const& e : prodMap)
    {
        products.push_back(e.first);
    }

    return products;
}
/** return vector of Orders according to sent filters */
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product, std::string timestamp)
{
    std::vector<OrderBookEntry> orders_sub;
        for (OrderBookEntry& e : orders)
    {
        if (e.orderType == type && e.product == product && e.timestamp == timestamp)
        {
            orders_sub.push_back(e);
        }
    }
    return orders_sub;
}

double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders)
{
    double max = orders[0].price;
    for (OrderBookEntry& e : orders)
    {
        if (e.price > max)max = e.price;
    }
    return max;
}

    double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders)
{
    double min = orders[0].price;
    for (OrderBookEntry& e : orders)
    {
        if (e.price < min)min = e.price;
    }
    return min;
}

std::string OrderBook::getEarliestTime()
{
    return orders[0].timestamp;
}

std::string OrderBook::getNextTime(std::string timestamp)
{
    std::string next_timestamp = "";
    for (OrderBookEntry& e : orders)
    {
        if (e.timestamp > timestamp)
        {
            next_timestamp = e.timestamp;
            break;
        }
    }
    if (next_timestamp =="")
        {
            next_timestamp = orders[0].timestamp;
        }
        return next_timestamp;
}

void OrderBook::insertOrder(OrderBookEntry& order)
{
    orders.push_back(order);
    std::sort(orders.begin(), orders.end(), OrderBookEntry::comparebyTimeStamp);
}

std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timestamp)
{
    //asks = orderbook.asks
    std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask, product, timestamp);
    //bids = orderbook.bids
    std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid, product, timestamp);
    //sales = []
    std::vector<OrderBookEntry> sales;
    //sort asks lowest first
    std::sort(asks.begin(), asks.end(), OrderBookEntry::comparebyPriceAsc);
    //sort bids highest first
    std::sort(bids.begin(), bids.end(), OrderBookEntry::comparebyPriceDesc);
    //for ask in asks
    for (OrderBookEntry& ask : asks)
    {
        for (OrderBookEntry& bid : bids)
        {
            if (bid.price >= ask.price)
            {
                OrderBookEntry sale{ask.price, 0, product, timestamp, OrderBookType::sale};

                if (bid.amount == ask.amount)
                {
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    //make sure the bid and ask are not used again
                    bid.amount = 0;
                    break;
                }
                if (bid.amount > ask.amount)
                {
                    sale.amount = ask.amount;   //set the sale amount to the ask amount
                    sales.push_back(sale);  //add the sale to the sales vector
                    bid.amount -= ask.amount;   //reduce the amount of the bid
                    break;  //break out of the bids loop
                }
                if (bid.amount < ask.amount)
                {
                    sale.amount = bid.amount;   //set the sale amount to the bid amount
                    sales.push_back(sale);  //add the sale to the sales vector
                    ask.amount -= bid.amount;   //reduce the amount of the ask
                    bid.amount = 0; //make sure the bid is not used again
                    continue;   //continue to next bid
                }
            }   
        }
    
    }
    return sales;
}