#include <iostream>
#include <string>
#include "gecko.h"




int main() {
    gecko::api pingTest;
    bool result = pingTest.ping();
    std::cout <<  std::endl;
    std::cout << "Ping Result: " <<  std::endl;
    std::cout << result << std::endl << std::endl;
    return 0;
}

