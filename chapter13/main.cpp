#include <iostream>
#include <memory> 

#include "asset.h"
#include "stock.h"
#include "trade.h"

int main()
{
using namespace stock_prices;
    auto coffee{ Stock{ "Coffee", 4.8, 0.0113 } }; 
    Asset& asset{coffee}; 
    std::cout << asset.get_name() << ": " << asset.next_price() << '\n'; 

    std::unique_ptr<Asset> asset_pointer{std::make_unique<Stock>("Coffee", 4.8, 0.0113)}; 
    std::cout << asset_pointer->get_name() << ": " << asset_pointer->next_price() << '\n';
    Exchange exchange{1, std::move(asset)};
}
