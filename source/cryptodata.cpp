

#include "cryptodata.hpp"
#include <forward_list>
#include <iostream>


CryptoData::CryptoData(){}
CryptoData::CryptoData(double price, double market_cap)
{
    setPrice(price);
    setMarketCap(market_cap);
}

// Member Functions()

// Setter Functions
void CryptoData::setPrice(double price)
{
    point.price = price;
}
void CryptoData::setMarketCap(double market_cap)
{
    point.market_cap = market_cap;
}
void CryptoData::setName(std::string name)
{
    point.name = name;
}


// Getter Functions
CryptoData::data CryptoData::getDataPoint()
{
    return point;
}
double CryptoData::getPrice()
{
    return point.price;
}
double CryptoData::getMarketCap()
{
    return point.market_cap;
}
std::string CryptoData::getName()
{
    return point.name;
}

// Print Function
void CryptoData::print()
{
    std::cout <<  getName() << " has the price of " << getPrice() << " and the market cap of " << getMarketCap() << std::endl;
}
