#include <iostream>
#include <random>

#include "input.h"
#include "analysis.h"

void random_experminent(){
  std::random_device rd{};
  std::default_random_engine generator(rd());
  std::uniform_int_distribution distribution{1,6};

  const int roll = distribution(generator);
  std::cout << "Dice roll " << roll << '\n'; 
}

void trading_game(){
  const double start_price = 100.0;
  std::cout << "Stock bought for: " << start_price << '\n';
  auto prices = stock_prices::get_prices(start_price, 10);
  for (auto price: prices) {
    std::cout << "Current price: " << price << '\n';
    std::cout <<  "Press (s) to sell\n";
    char choice{};
    std::cin >> choice;
    if (choice == 's') {
      const double profit = price - start_price;
      std::cout << "Profit " << profit << '\n';
      break;
    }
  }
  std::cout << "Game over\n";
}

int main(){
  random_experminent();
  stock_prices::test_input();

  auto seed = std::random_device{}();
  std::cout << "Seed " << seed << '\n';
  const auto prices = stock_prices::get_prices(100.0, 10, 0.05, seed);
  //  const auto different_prices = stock_prices::get_prices(100.0, 10, 0.05);
  std:: cout << "Got prices:\n";
  for(double price: prices){
    std::cout << price << '\n';
  }

  //const auto profit = stock_prices::profit_on_first_upstick(prices);
  //std::cout << "Profit " << profit << '\n';
  //trading_game();
}
