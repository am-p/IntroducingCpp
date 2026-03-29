#pragma once

#include <string>

namespace stock_prices{
  struct Stock{
    std::string name{};
    double last_price{};
    double volatility{};
  };
}
