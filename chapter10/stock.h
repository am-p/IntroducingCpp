#pragma once

#include <random>
#include <string>

namespace stock_prices{
  class Stock{
    std::string name{};
    double last_price{};
    double volatility{};
    std::default_random_engine gen{std::random_device{}()};
    std::normal_distribution<double> distrib{};

  public:
    Stock(const std::string& stock_name, double start_price, double start_volatility);
    
    std::string get_name() const{// Ese const significa que no voy a modificar el objeto(y sus componentes, claro)
    return name;
  }
    double next_price();
  };
}
