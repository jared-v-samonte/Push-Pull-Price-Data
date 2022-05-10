

#ifndef _deserialize_h_included_
#define _deserialize_h_included_

// STL
#include <string>

// RapidJSON
#include "document.h"
#include "rapidjson.h"
#include "cryptodata.hpp"
#include <iostream>
#include <forward_list>

std::forward_list<CryptoData> deserialize_from_string(std::string const& json_data);
void deserialize_5mins(std::string price, std::string &deserialize_price);
void print_from_string(std::string const& json_data);

#endif //Data_Push_Pull_TESTING_DESERIALIZE_H

