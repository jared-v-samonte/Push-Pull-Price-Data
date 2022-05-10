#include <account.hpp>//set up the account
#include "mysql.h"
#include <memory.h>
#include <connection.hpp>
#include <bind.hpp>
#include <types.hpp>
#include <result_set.hpp>
using namespace mariadb;

connection_ref getConnection()
{
    connection_ref con;
    const std::string host_name = "localhost";
    const std::string user_name = "root";
    const std::string password = "root_password";
    const std::string schema = ""; 
    u32 port = 3306;
    const std::string unix_socket = "";


    // create connection
    account_ref acc = account::create(host_name, user_name, password, schema, port, unix_socket);
    con = connection::create(acc); 
    return con;
}


int main()
{
    connection_ref connection;
    connection = getConnection();

    std::cout << std::endl << "Cannot Show or Query"  << std::endl;

    while(true)
    {
        std::string command;
        std::cout << std::endl;
        std::cout << "Execute in MySQL: ";
        std::getline(std::cin, command); 
        connection->execute(command);
        std::cin.clear();
        std::cin.sync();
    }

}