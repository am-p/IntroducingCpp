#include <iostream>
#include "stock.h"

int main(){
  stock_prices::Stock coffee{"Coffee", 4.8, 11.3};
  std::cout << coffee.name  
        << ": price " << coffee.last_price 
        << '\n';
}
