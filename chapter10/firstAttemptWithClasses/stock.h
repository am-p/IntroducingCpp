#pragma once

#include <string>

namespace stock_prices
{
    class Stock
    {
        std::string name{};
        double last_price{};
        double volatility{};

    public:
        Stock(const std::string & stock_name,
            double start_price,
            double start_volatility) 
        : 
            name(stock_name), 
            last_price(start_price), 
            volatility(start_volatility) 
        {
        }

        std::string get_name() const 
        {
            return name;
        }
    };
}
