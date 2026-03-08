#include <algorithm>
#include <cassert>
#include <fstream>
#include <limits>
#include <sstream>
#include <random>

#include "input.h"

namespace stock_prices{
  std::expected<double, std::string> get_number(std::istream& input_stream)
  {
    double number{};
    input_stream >> number;

    if(input_stream)
      {
	return number;
      }
  
    input_stream.clear();
    input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
    return std::unexpected("That's not a number");
  }

  std::vector<double> get_prices(std::istream& input_stream, std::function<void ()> prompt){
    prompt();
    std::vector<double> numbers{};
    auto number = stock_prices::get_number(input_stream);
  
    while(number.has_value()){
      numbers.push_back(number.value());
      prompt();
      number = stock_prices::get_number(input_stream);
    }

    return numbers;
  }

  std::vector<double> get_prices(double price, size_t count) {
    std::vector<double> prices(count);
    const double step = price/100.0;

    std::random_device rd{};
    std::default_random_engine gen(rd());
    std::uniform_int_distribution distrib{-1,1};

    auto next_price = [step, &price, &gen, &distrib]() {
      price += step*distrib(gen);
      return price;
    };
    
    std::ranges::generate(prices.begin(), prices.end(), next_price);
    return prices;
  }

  std::vector<double> get_prices(double price, size_t count, double volatility) {
    std::vector<double> prices(count);
    
    std::random_device rd{};
    std::default_random_engine gen{rd()};
    std::normal_distribution distrib;

    auto next_price = [volatility, &price, &gen, &distrib](){
      double percent = volatility * distrib(gen);
      price += price * percent;
      return price;
    };

    std::ranges::generate(prices.begin(), prices.end(), next_price);
    return prices;
  }

  std::vector<double> get_prices(double price, size_t count, double volatility, unsigned int seed) {
    std::vector<double> prices(count);
    
    std::random_device rd{};
    std::default_random_engine gen{seed};
    std::normal_distribution distrib;

    auto next_price = [volatility, &price, &gen, &distrib](){
      double percent = volatility * distrib(gen);
      price += price * percent;
      return price;
    };

    std::ranges::generate(prices.begin(), prices.end(), next_price);
    return prices;
  }

  std::vector<double> read_from_file(const std::string& filename){
    std::ifstream file{filename};
    if(file) {
      return get_prices(file, [](){});
    }
    else {
      throw std::runtime_error("Failed to write to file");
    }
  }

  void test_input(){

    std::stringstream no_input{""};
    auto no_op = [](){};
    assert(get_prices(no_input, no_op).empty());

    std::stringstream some_input{"1"};
    assert(get_prices(some_input, no_op).size() == 1);
  }
}

