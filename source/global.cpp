#include "global.hpp"

//Time variables

int g_current_year, g_current_month, g_current_day, g_current_hour, g_current_min, g_current_sec, g_current_dst_flag;

//Sqlite data vectors
std::vector<std::string> vector_data_columns, vector_data;

//Sqlite callback
int callback(void *NotUsed, int rows, char **data, char **data_col_name) {
    std::string str_data_col,str_data;
    for(int a=0;a<rows;a++){
        str_data_col=data_col_name[a];
        str_data=data[a];
        vector_data_columns.push_back(str_data_col);
        vector_data.push_back(str_data);
        str_data_col.clear();
        str_data.clear();
    }
    return 0;
}
