#include <exception>

#include "historical_prices.h"

double stock_prices::HistoricalPrices::next_price()
{
    ++index; 
    return get_price(); 
}

double stock_prices::HistoricalPrices::get_price() const
{
    if (index == prices.size()) 
    {
      throw no_more_prices{};
    }
    return prices[index]; 
}
