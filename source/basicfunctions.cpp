#include "basicfunctions.hpp"
#include "simple.h"
#include <unistd.h>


void getPricePerSeconds(std::string cryptoID)
{
    gecko::simpleFunctions simple;
    gecko::web::response response;
    const char* currency = "usd";
    std::string usd{currency};

    int count = 0;
    unsigned int seconds = 5; 
    unsigned int wait = 1000000;

    while(true)
    {
        response = simple.getPrice(cryptoID, usd, true);
        std::string price = std::string{response.text};   
        std::cout << std::endl << std::endl;
        std::cout << "Price of " << cryptoID << " after " << (seconds * count) << " seconds" << " is " << price;
        count++;
        usleep(seconds * wait);
    }
}
