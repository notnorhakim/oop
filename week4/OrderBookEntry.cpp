#include "OrderBookEntry.h"

//constructor
OrderBookEntry::OrderBookEntry(double price, double amount, std::string timestamp, std::string product, OrderBookType orderBookType)

//initialise the variables
: price(price), amount(amount), timestamp(timestamp), product(product), orderBookType(orderBookType)
{

}