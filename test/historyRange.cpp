#include <iostream>
#include <string>
#include "coins.h"


using namespace std;


string getHistoryRange(string cryptoID, string start, string end)
{
    gecko::coinsFunctions coins;
    gecko::web::response response;
    const char* currency = "usd";
    string usd{currency};

    response = coins.getCoinMarketHistoryWithinRange(cryptoID, usd, end, start);
    string range = string{response.text};
    return range;
}

int main() {
    string cryptoID, start, end;
    cout << endl << "Enter Crypto ID: ";
    getline(cin, cryptoID);
    cout << endl << "Enter date Unix Time Start: ";
    getline(cin, start);
    cout << endl << "Enter date Unix Time End: ";
    getline(cin, end);
    cin.clear();cin.sync();
    cout << endl << "Price of " << cryptoID << " from " << start << " to " << end << " in usd: ";
    cout << getHistoryRange(cryptoID, start, end) << endl << endl;
    return 0;
}
