#include <iostream>
#include <vector>

#include "stock.h"

int main(){

  using namespace stock_prices;
  std::vector stocks{
    Stock{"Coffee", 4.8, 0.0113},
    Stock{"Tea", 171.68, 0.023},
    Stock{"Sugar", 17.91, 0.05}
  };
  
  for(auto& stock: stocks){
    std::cout << stock.get_name() << ":  " << stock.next_price() << '\n';
  }
}
