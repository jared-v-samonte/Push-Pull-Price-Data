#include <iostream>
#include <string>
#include <unistd.h>
#include "coins.h"

using namespace std;


void getPriceEveryMarket(const char *cryptoID)
{
    gecko::coinsFunctions coins;
    gecko::web::response response;
    const char* currency = "usd";
    const char* gecko_desc = "gecko_desc";
    string usd{currency};
    string sort{gecko_desc};

    int count = 0;
    unsigned int seconds = 5; 
    unsigned int wait = 1000000;

    while(true)
    {
        response = coins.getMarkets(usd, cryptoID);
        string price = string{response.text};   
        cout << endl << endl;
        cout << "Market Data after " << (seconds * count) << " seconds" << " is :" << endl << price;
        count++;
        usleep(seconds * wait);
    }
}

int main() {
    string cryptoID;
    const char * crypto;

    cout << "Enter Crypto ID: ";
    getline(cin, cryptoID);

    crypto = cryptoID.c_str();
    cin.clear();cin.sync();

    getPriceEveryMarket(crypto);
    return 0;
}