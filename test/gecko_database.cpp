
#include <iostream>
#include <string>
#include "gecko.h"
#include "coins.h"
#include "cgapi.hpp"
#include "account.hpp"//
#include "mysql.h"
#include <memory.h>
#include <connection.hpp>
#include <bind.hpp>
#include <types.hpp>
#include <result_set.hpp>
#include <databasefunctions.hpp>

using namespace mariadb;


void showTables(connection_ref connection)
{
    result_set_ref result;
    std::string databases;
    
    connection->execute("USE Demo");
    result = connection->query("SHOW TABLES");

    std::cout << std::endl << "List of Tables: ";
    while (result->next()) 
    {
        databases = result ->get_string(0);
        std::cout << std::endl << databases ;
    }
    std::cout << std::endl;
}

void createTables(connection_ref connection, std::string name)
{
    std::string temp("CREATE TABLE IF NOT EXISTS " + name + " (demo varchar(1))");
    connection->execute(temp);
}



int main() 
{


    connection_ref connection;
    connection_ref* connection_address = &connection;
    establish_db_connection(0, connection_address);
    std::string name;

    connection->execute("CREATE DATABASE IF NOT EXISTS Demo");
    connection->execute("USE Demo");
    
    do
    {
        std::cout << std::endl << "Enter CLOSE to exit or new table name: ";
        std::getline(std::cin, name);
        createTables(connection, name);
        showTables(connection);
    }  while(name != "CLOSE");

    connection->execute("DROP DATABASE Demo");
    std::string cryptoID, start, end, price;
    
    std::cout << std::endl << "Enter Crypto ID: ";
    std::getline(std::cin, cryptoID);
    std::cin.clear();
    std::cin.sync();

    std::cout << std::endl << "Enter starting Unix Timestamp: ";
    std::getline(std::cin, start);
    std::cin.clear();
    std::cin.sync();

    end = std::to_string(unixtimestamp_after24h(stoi(start)));
    price = getHistoryRange(cryptoID, start, end);

    std::cout << std::endl << "Price of " << cryptoID << " from " << start << " to " << end << " in usd: " << std::endl;
    std::cout << price << std::endl;
    std::cout << "Ending Unix Timestamp: " << end << std::endl << std::endl;
    return 0;
}
