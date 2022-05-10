

#include <iostream>
#include <string>
#include "gecko.h"
#include "coins.h"
#include "cgapi.hpp"
#include "deserialize.hpp"

using namespace std;




int main() {
    //void*(price_timestamps)[1][300];
    //void **price_timestamps;
    //price_timestamps = new void *[1];
    //price_timestamps[0] = new void * [288];
    //price_timestamps[1] = new void * [288];


    string cryptoID, start, end, price, deserialize_price;
    
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
    deserialize_5mins(price, deserialize_price);

    cout << endl << "Price of " << cryptoID << " from " << start << " to " << end << " in usd: " << endl;
    cout.precision(13);
    cout << deserialize_price << endl;
    return 0;
}
