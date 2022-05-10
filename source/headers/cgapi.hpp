
#pragma once


#ifndef _cgapi_hpp_included_
#define _cgapi_hpp_included_



#include <iostream>
#include <string>
#include "gecko.h"
#include "coins.h"
#include "cgapi.hpp"

//#include <date.h>



std::string getHistoryRange(std::string cryptoID, std::string start, std::string end);
int get_current_unix_timestamp();
int unixtimestamp_after24h(int start);

#endif
