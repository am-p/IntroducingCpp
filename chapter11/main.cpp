#include <iostream>
#include <vector>

#include "stock.h"

int main()
{
  using namespace stock_prices;
  std::vector<Stock> stocks;
  stocks.push_back(Stock{"Coffee", 4.8, 0.0113}); //Stock{"Coffee", 4.8, 0.0113} <---this is a temporary without a name: Stock is the type!

  for(auto & stock : stocks)
    {
      std::cout << stock.get_name() << ": " << stock.next_price() << '\n';
    }
}
