#include <iostream>
#include <string>
#include "simple.h"
#include <unistd.h>


using namespace std;


void getPriceEveryMin(std::string cryptoID)
{
    gecko::simpleFunctions simple;
    gecko::web::response response;
    const char* currency = "usd";
    string usd{currency};

    int count = 0;
    unsigned int seconds = 5; 
    unsigned int wait = 1000000;

    while(true)
    {
        response = simple.getPrice(cryptoID, usd, true);
        string price = string{response.text};   
        cout << endl << endl;
        cout << "Price of " << cryptoID << " after " << (seconds * count) << " seconds" << " is " << price;
        count++;
        usleep(seconds * wait);
    }
}

int main() {
    string cryptoID;
    cout << endl << endl;
    cout << "Enter Crypto ID: ";
    getline(cin, cryptoID);
    cin.clear();cin.sync();
    getPriceEveryMin(cryptoID);
    return 0;
}