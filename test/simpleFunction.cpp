#include <iostream>
#include <string>
#include "simple.h"



std::string getPriceStringAsync(std::string cryptoID)
{
    gecko::simpleFunctions simple;
    gecko::web::response response;
    const char* currency = "usd";
    std::string usd{currency};

    response = simple.getPrice(cryptoID, usd, true);
    std::string price = std::string{response.text};
    return price;
}

int main() {
    std::string cryptoID;
    std::cout << "Enter Crypto ID: ";
    std::getline(std::cin, cryptoID);
    std::cin.clear();
    std::cin.sync();
    std::cout << "Price of " << cryptoID << " in usd: " << getPriceStringAsync(cryptoID) <<  std::endl << std::endl;
    return 0;
}
