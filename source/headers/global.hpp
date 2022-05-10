#ifndef _global_hpp_
#define _global_hpp_

#include <string>
#include <vector>
//#include "boost/date_time.hpp"

//Time variables
extern int g_current_year, g_current_month, g_current_day, g_current_hour, g_current_min, g_current_sec, g_current_dst_flag;

//Sqlite data vectors
extern std::vector<std::string> vector_data_columns, vector_data;

//Sqlite callback
extern int callback(void *NotUsed, int rows, char **data, char **data_col_name);

#endif
