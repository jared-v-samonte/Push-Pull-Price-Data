
#include <account.hpp>//set up the account
#include "mysql.h"
#include <memory.h>
#include <connection.hpp>
#include <bind.hpp>
#include <types.hpp>
#include <result_set.hpp>
#include <databasefunctions.hpp>

using namespace mariadb;




bool is_established(connection_ref *connection)
{
    bool established  = true;
    if(connection == NULL)
    {
        established = false;
    }
    return established;
}

bool establish_db_connection(int database, connection_ref *connection) 
{
    const std::string host_name = "localhost";
    const std::string user_name = "root";
    const std::string password = "root_password";
    const std::string schema = ""; 
    u32 port = 3306;
    const std::string unix_socket = "";

    account_ref acc = account::create(host_name, user_name, password, schema, port, unix_socket);
    *connection = connection::create(acc); 
    
    return is_established(connection);   
}

bool create_initial_databases(connection_ref *connection_1, connection_ref *connection_2)
{
    bool database_1;
    bool database_2;
    std::string name_1;
    std::string name_2;


    name_1 = "insert name";
    database_1 = establish_db_connection(1, connection_1);
    createDatabase(*connection_1, name_1);


    name_2  = "insert name";
    database_2 = establish_db_connection(2, connection_2);
    createDatabase(*connection_2, name_2);


    return (database_1 && database_2);
}

bool check_initial_databases(connection_ref *connection_1, connection_ref *connection_2)
{
    bool database_1;
    bool database_2;
    database_1 = is_established(connection_1);
    database_2 = is_established(connection_2);
    return (database_1 && database_2);
}


void createDatabase(connection_ref connection, std::string name)
{
    std::string temp("CREATE DATABASE IF NOT EXISTS " + name);
    connection->execute(temp);
}

void createTable(connection_ref connection, std::string name, std::string column)
{
    std::string temp("CREATE TABLE if not exists " + name + "(" + column  + ")");
    connection->execute(temp);
}

void dropTable(connection_ref connection, std::string name)
{
    std::string temp("DROP TABLE " + name);
    connection->execute(temp);
}

void dropDatabase(connection_ref connection, std::string name)
{
    std::string temp("DROP DATABASE " + name);
    connection->execute(temp);
}


void useDatabase(connection_ref connection, std::string name)
{
    std::string temp("USE " + name);
    connection->execute(temp);
}


void addColumn(connection_ref connection, std::string name, std::string column_type)
{
    std::string temp("ALTER TABLE " + name + " ADD COLUMN IF NOT EXISTS " + column_type);
    connection->execute(temp);
}

void insertValue(connection_ref connection, std::string table, std::string column, std::string values)
{
    std::string empty = "";
    std::string temp("INSERT INTO " + table + " (" + column + ") VALUES (" + values + ")" + empty);
    connection->execute(temp);
}


