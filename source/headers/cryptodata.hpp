//
// Created by Jared V. Samonte on 2021-12-26
//
// Stub code to test the framework. Feel free to ignore or change.
//


#ifndef _cryptodata_h_included_
#define _cryptodata_h_included_

#include <forward_list>
#include <iostream>

class CryptoData
{
    // Access specifier
    public:
    struct data
    {
        double price;
        double market_cap;
        std::string name;
    };

    void setPrice(double price);
    void setMarketCap(double market_cap);
    void setName(std::string name);

    data getDataPoint();
    double getPrice();
    double getMarketCap();
    std::string getName();

    CryptoData();
    CryptoData(double price, double market_cap);
    void print();


    private:
    data point;
};


#endif //Data_Push_Pull_TESTING_CRYPTO_DATA_H
