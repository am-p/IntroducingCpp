#pragma once

#include <string>
#include <exception>

namespace stock_prices{
  class Asset{
  public:
    virtual ~Asset() = default;
    virtual std::string get_name() const = 0;
    virtual double get_price() const = 0;
    virtual double next_price() = 0;
  };

  class no_more_prices : public std::exception{};
}
