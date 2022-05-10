#include <iostream>
#include <string>
#include "coins.h"

using namespace std;


std::string getHistoryString(std::string cryptoID, std::string date)
{
    gecko::coinsFunctions coins;
    gecko::web::response response;

    response = coins.getCoinHistory(cryptoID, date, true);
    string price = string{response.text};
    return price;
}

int main() {
    string cryptoID, date;
    cout << endl << "Enter Crypto ID: ";
    getline(cin, cryptoID);
    cout << endl << "Enter date in in dd-mm-yyyy: ";
    getline(cin, date);
    cin.clear();cin.sync();
    cout << endl << "Price of " << cryptoID << " on " << date << " in usd: " << getHistoryString(cryptoID, date) <<  endl << endl;
    return 0;
}

