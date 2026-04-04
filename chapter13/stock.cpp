#include <type_traits>

#include "stock.h"

void stock_prices::test_stock() 
{
  using namespace stock_prices;
  static_assert(std::is_abstract<Asset>()); 
  static_assert(std::is_polymorphic<Asset>()); 
  static_assert(std::is_polymorphic<Stock>()); 
}

stock_prices::Stock::Stock(const std::string& stock_name, double start_price, double start_volatility):
  name(stock_name),
  last_price(start_price),
  volatility(start_volatility)  
{}

double stock_prices::Stock::next_price(){
  double percent = volatility * distrib(gen);
  last_price += last_price * percent;
  return last_price;
}
