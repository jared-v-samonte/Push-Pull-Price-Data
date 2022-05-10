
// STL
#include <string>

// RapidJSON
#include <sstream>
#include "document.h"
#include "rapidjson.h"
#include "cryptodata.hpp"
#include <iostream>
#include <forward_list>
#include "deserialize.hpp"

using namespace rapidjson;


// Input data format/parsing.

/*
std::forward_list<CryptoData> deserialize(Document& doc) 
{
    std::forward_list<CryptoData> data_list;
    std::forward_list<CryptoData>::iterator line_iterator = data_list.before_begin();
    for (rapidjson::SizeType i = 0; i < doc.Size(); i++)
    {
        //intializes new segment
        CryptoData new_data;

        std::string crypto_name =  doc[i]["name"].GetString();
        double crypto_price = doc[i]["current_price"].GetDouble();
        double crypto_market_cap = doc[i]["market_cap"].GetDouble();
        //adds points to segments
        new_data.setName(crypto_name);
        new_data.setPrice(crypto_price);
        new_data.setMarketCap(crypto_market_cap);
        //inserts completed doc[i] segment to forward list
        line_iterator = data_list.insert_after(line_iterator, new_data);
    }
    return data_list;
}



void print_from_string(std::string const &json_data)
{
    Document doc;
    doc.Parse<0>(json_data.c_str());
    std::forward_list<CryptoData> list = deserialize(doc);
    for (std::forward_list<CryptoData>::iterator iterator_i = list.begin(); iterator_i != list.end(); ++iterator_i)
    {
        CryptoData list_data =  *iterator_i;
        list_data.print();
    }
}

std::forward_list<CryptoData> deserialize_from_string(std::string const &json_data)
{
    Document doc;
    doc.Parse(json_data.c_str());
    return deserialize(doc);
}



void deserialize_price_timestamp(Document& doc, float* unix_timestamps[288]) 
{
    auto const& lines_json = doc["prices"];
    auto lines_array = lines_json.GetArray();
    int count = 0;
    float time_temp;

    for (auto& price_time : lines_array) 
    {
        if((price_time.IsArray()) && (count < 288))
        {
            auto unix_time = price_time.GetArray()[1].GetFloat();
            time_temp = unix_time;

            unix_timestamps[count] = &time_temp;

            count++;
        }
    }
}
*/

void deserialize_price(Document& doc, double (&price_5_mins)[288]) 
{
    auto const& lines_json = doc["prices"];
    auto lines_array = lines_json.GetArray();
    int count = 0;
    double price_temp;

    for (auto& price_time : lines_array) 
    {
        if((price_time.IsArray()) && (NULL != price_time.GetArray()[0].GetDouble()))
        {
            auto price  = price_time.GetArray()[0].GetDouble();
            price_temp = price;
            price_5_mins[count] = price_temp;
            count++;
        }
    }
}


void deserialize_timestamp(Document& doc,  float (&unix_timestamps)[288]) 
{
    auto const& lines_json = doc["prices"];
    auto lines_array = lines_json.GetArray();
    int count = 0;
    float time_temp;

    for (auto& price_time : lines_array) 
    {
        if((price_time.IsArray()) && (count < 288))
        {
            auto unix_time = price_time.GetArray()[1].GetFloat();
            time_temp = unix_time;
            unix_timestamps[count] = time_temp;
            count++;
        }
    }
}

std::string double_to_string(double pointer)
{
    std::string output;
    std::ostringstream stream;

    stream.precision(288);

    stream << pointer;
    output =  stream.str();

    stream.clear(); 
    return output;
}


std::string float_to_string(float pointer)
{
    std::string output;
    std::ostringstream stream;

    stream.precision(18);
    stream << pointer;
    output =  stream.str();

    stream.clear(); 
    return output;
}

std::string integer_to_string(int pointer)
{
    std::string output;
    std::ostringstream stream;

    stream << pointer;
    output =  stream.str();

    stream.clear(); 
    return output;
}


void string_5mins(std::string &prices, double (&price_5_mins)[288], float (&unix_timestamps)[288])
{
    std::string price, timestamp, price_intro, time_intro, count_intro, count, spaces;
    double price_temp;
    float timestamp_temp;
    price_intro = " and the price is ";
    time_intro = "The unix timestamp: ";
    count_intro = " count: ";
    spaces = "\n\n";

    for(int i = 0; i < 288 ; i++) 
    {

        price_temp = price_5_mins[i];
        timestamp_temp = unix_timestamps[i];

        price = double_to_string(price_temp);
        timestamp = float_to_string(timestamp_temp);

        count = integer_to_string(1+ i);

        prices.append(time_intro);
        prices.append(price);
        prices.append(price_intro);
        prices.append(timestamp);
        prices.append(count_intro);
        prices.append(count);
        prices.append(spaces);
    }
}

void deserialize_5mins(std::string json_data , std::string &prices)
{
    
    double price_5_mins[288];
    float unix_timestamps[288];
    Document doc;
    doc.Parse(json_data.c_str());
    deserialize_price(doc, price_5_mins);
    deserialize_timestamp(doc, unix_timestamps);
    string_5mins(prices, price_5_mins, unix_timestamps);
}