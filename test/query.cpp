#include "account.hpp"//
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
    connection = getConnection();
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
}