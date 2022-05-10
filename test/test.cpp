
#include <iostream>
#include <iostream>
#include <string>
#include "gecko.h"
#include "coins.h"
#include "cgapi.hpp"

using namespace std;



int main() {
    string cryptoID, start, end, price;
    
    cout << endl << "Enter Crypto ID: ";
    getline(cin, cryptoID);
    cin.clear();
    cin.sync();

    cout << endl << "Enter starting Unix Timestamp: ";
    getline(cin, start);
    cin.clear();
    cin.sync();

    end = to_string(unixtimestamp_after24h(stoi(start)));
    price = getHistoryRange(cryptoID, start, end);

    cout << endl << "Price of " << cryptoID << " from " << start << " to " << end << " in usd: " << endl;
    cout << price << endl;
    cout << "Ending Unix Timestamp: " << end << endl << endl;
    return 0;
}
