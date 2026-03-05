#include <iostream>
#include <random>

#include "input.h"

void random_experminent(){
  std::random_device rd{};
  std::default_random_engine generator(rd());
  std::uniform_int_distribution distribution{1,6};

  const int roll = distribution(generator);
  std::cout << "Dice roll " << roll << '\n'; 
}

int main(){
  random_experminent();
  stock_prices::test_input();
  const auto prices = stock_prices::get_prices(100.0, 10);
  std:: cout << "Got prices:\n";
  for(double price: prices){
    std::cout << price << '\n';
  }
}
