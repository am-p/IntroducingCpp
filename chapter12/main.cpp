#include <memory>

#include "stock.h"

int main(){
  using namespace stock_prices;
  auto asset{
    std::make_unique<Stock>("Coffee", 4.8, 0.0113)
  };
}
