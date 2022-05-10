

#include <iostream>
#include <string>
#include "gecko.h"
#include "coins.h"
#include "cgapi.hpp"
//#include <date.h>

using namespace gecko;



int get_current_unix_timestamp()
{
    unsigned long int secconds = time(NULL);
    return secconds;
}

int unixtimestamp_after24h(int start)
{
    int end;
    end = start+ 86400; 
    return end;
}

std::string getHistoryRange(std::string cryptoID, std::string start, std::string end)
{
    coinsFunctions coins;
    web::response response;
    std::string range;
    const char* currency = "usd";
    std::string usd{currency};

    response = coins.getCoinMarketHistoryWithinRange(cryptoID, usd, end, start);
    range = response.text;
    return range;
}