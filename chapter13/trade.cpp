#include  <stdexcept>

#include "trade.h"

double stock_prices::Exchange::next_price() 
{
    if (!asset) 
    {
        throw std::invalid_argument{"No asset available"}; 
    }
    prices.push_back(asset->get_price()); 
    return  asset->next_price(); 
}
