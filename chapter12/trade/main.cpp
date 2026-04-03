#include <iostream>

#include "trade.h"
#include "stock.h"

void show_prices(const stock_prices::Exchange& exchange) 
{
    for(auto price: exchange.get_prices())
    {
       std::cout << price << '\n';
    }
}

int main()
{
   using namespace stock_prices;
   test_trades();
   Exchange exchange{100}; 
   show_prices(exchange); 
}
