#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "input.h"

void write_to_file(const std::vector<double>& prices, const std::string& filename){

  const std::filesystem::path path = std::filesystem::current_path();
  const auto fully_pathed_filename = path / filename;
  
  std::ofstream file{filename, std::ios::out | std::ios::app};
  if (file){
    for (auto price: prices) {
      file << price << '\n';
    }
    std::cout << "Wrote to " << fully_pathed_filename << '\n';
  }
  else {
    auto error_message = "Failed to write to " + fully_pathed_filename.string();
    throw std::runtime_error(error_message);
  }
}

void read_from_file(const std::string & filename){
  std::ifstream file{filename};
  if (file){
    auto prices = stock_prices::get_prices(file, [](){});
    for (auto price: prices) {
      std::cout << price << '\n';
    }
  }
  else {
    throw std::runtime_error("Failed to read from file");
  }
}

int main(){
  try{
    double first_price{100.0};
    const std::string filename{"prices.txt"};
    
    if(std::filesystem::exists(filename)){
      auto prices = stock_prices::read_from_file(filename);
	if(!prices.empty()){
	  first_price = prices.back();
	  std::cout << "Read " << prices.size() << " prices\n";
	}
      }
    
    write_to_file(stock_prices::get_prices(first_price, 10, 0.05), filename);
    return 0;
  }
  catch(const std::exception& e) {
    std::cout << e.what() << '\n';
    return -1;
  }
}
