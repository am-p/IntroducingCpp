#include <cassert>
#include <istream>
#include <iostream>
#include <sstream>
#include <limits>


[[nodiscard] ]bool get_number(std::istream& input_stream, double& number)
{
  input_stream >> number;
  if (input_stream)
    {
      return true;
    }
  else
    {
      input_stream.clear();
      input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return false;
    }
}

void some_experiments()
{
  double number{}; //change to int and see what the compiler has to say
  bool OK = get_number(std::cin, number);
  std::cout << OK << '\n';
}

void test_code()
{
  double value{};
  std::stringstream some_input{"1"};
  const bool ok = get_number(some_input, value);
  assert(ok);
  assert(value == 1);

  double unused{};
  std::stringstream bad_input{"q"};
  const bool not_ok = get_number(bad_input, unused);
  assert(!not_ok);
}

int main()
{
  test_code();
  
  double number{};
  std::cout << "Please enter a number. \n>";
  const bool ok = get_number(std::cin, number);
  if(ok)
    {
      std::cout << "Got " << number << ", thanks!\n";
    }
  else
    {
      std::cout << "Something went wrong\n"; 
      std::cout << "Please enter a number,\n";
      const bool ok_now = get_number(std::cin, number);
      if (ok_now)
	{
	  std::cout << "Got " << number << ", thanks!\n";
	}
      else {
	std::cout << "Something went wrong\n";
      }
    }
}
    
