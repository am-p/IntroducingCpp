#pragma once

#include <expected>
#include <iostream>

namespace stock_prices{
  std::expected<double, std::string> get_number(std::istream& input_stream);
}
