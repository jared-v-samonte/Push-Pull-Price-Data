#ifndef _databasefunctions_hpp_included_
#define _databasefunctions_hpp_included_

#include <account.hpp>//set up the account
#include "mysql.h"
#include <memory.h>
#include <connection.hpp>
#include <bind.hpp>
#include <types.hpp>
#include <result_set.hpp>

using namespace mariadb;

bool establish_db_connection(int databasem,  connection_ref* connection);

void createDatabase(connection_ref connection, std::string name);

void createTable(connection_ref connection, std::string name, std::string column_type);

void useDatabase(connection_ref connection, std::string name);

void dropTable(connection_ref connection, std::string name);

void dropDatabase(connection_ref connection, std::string name);

void addColumn(connection_ref connection, std::string name, std::string column_type);

void insertValue(connection_ref connection, std::string table, std::string column, std::string values);

bool create_initial_databases(connection_ref *connection_1, connection_ref *connection_2);

bool check_initial_databases();



#endif
