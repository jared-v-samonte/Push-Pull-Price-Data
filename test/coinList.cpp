#include <iostream>
#include <string>
#include "coins.h"




std::string getCoinsList()
{
    gecko::coinsFunctions coins;
    gecko::web::response response;
    response = coins.listCoins(false);
    std::string list =  std::string{response.text};
    return list;
}

int main() {


    std::cout <<  std::endl  << "List of Coins: "  <<  std::endl << getCoinsList() <<  std::endl << std::endl;
    return 0;
}

