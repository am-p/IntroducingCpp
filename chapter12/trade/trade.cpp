#include <cassert>
#include <stdexcept>

#include "trade.h"

double stock_prices::Exchange::next_price() 
{
  if (!asset) 
    {
      throw std::invalid_argument{"No asset available"}; 
    }
  prices.push_back(asset->get_price()); 
  return asset->next_price(); 
}

void stock_prices::test_trades()
{
  using namespace stock_prices;
  Exchange exchange{ 100 }; 
  try 
    {
      exchange.next_price(); 
      assert(false); 
    }
  catch (const std::exception & ) {}

  static_assert(!std::is_copy_constructible<Exchange>()); 
  static_assert(!std::is_copy_assignable<Exchange>()); 
}
