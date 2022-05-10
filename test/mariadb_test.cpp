#include <account.hpp>//set up the account
#include "mysql.h"
#include <memory.h>
#include <connection.hpp>
#include <bind.hpp>
#include <types.hpp>
#include <databasefunctions.hpp>
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


void commandForMySQL(connection_ref con, std::string command)
{
    con->execute(command);
}


int main()
{
    std::string database = "Demo";
    std::string table = "Test_Table";
    std::string column = "Test_Column";
    std::string column_type = "Test_Column INT UNSIGNED  DEFAULT '0000' NOT NULL";
    connection_ref connection;
    connection = getConnection();
    createDatabase(connection, database);
    useDatabase(connection, database);
    createTable(connection, table, column_type);
    addColumn(connection, table,  column_type);
    insertValue(connection, table, column,  "99");
    dropTable(connection, table);
    dropDatabase(connection, database);
}