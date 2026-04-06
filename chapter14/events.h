#include <iostream>
#include <string>
#include <variant>

namespace stock_prices
{
  struct Nothing 
  {
  };

  struct FixedFine 
  {
    double fine{};
  };

  struct Gift 
  {
    double gift{};
  };

  struct InterestPayment 
  {
    double percent{};
  };

  using Event = std::variant<Nothing,
			     FixedFine,
			     Gift,
			     InterestPayment,
			     std::string>;
}
