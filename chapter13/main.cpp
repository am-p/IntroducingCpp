#include <iostream>
#include <memory>
#include <type_traits>

#include "asset.h"
#include "stock.h"
#include "trade.h"

namespace stock_prices
{
  void test_stock()
  {
    static_assert(std::is_abstract<Asset>());
    static_assert(std::is_polymorphic<Asset>());
    static_assert(std::is_polymorphic<Stock>());
  }

  void test_trades()
  {
    static_assert(std::is_move_constructible_v<Exchange>);
    static_assert(!std::is_copy_constructible_v<Exchange>);
  }
}

int main()
{
  using namespace stock_prices;
  test_stock(); 
  test_trades(); 

  auto coffee{ Stock{ "Coffee", 4.8, 0.0113 } }; 
  Asset& asset{coffee}; 
  std::cout << asset.get_name() << ": " << asset.next_price() << '\n'; 

  std::unique_ptr<Asset> asset_pointer{
    std::make_unique<Stock>("Coffee", 4.8, 0.0113)
  }; 
  std::cout << asset_pointer->get_name() << ": " 
	    << asset_pointer->next_price() << '\n'; 
}
