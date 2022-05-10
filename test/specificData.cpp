#include <iostream>
#include <string>
#include <unistd.h>
#include "coins.h"
#include <deserialize.h>

using namespace std;

void getPriceEveryMarket(const char *cryptoID)
{
    gecko::coinsFunctions coins;
    gecko::web::response response;
    const char* currency = "usd";
    string usd{currency};
    response = coins.getMarkets(usd, cryptoID);
    string market = string{response.text};   
    print_from_string(market);
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