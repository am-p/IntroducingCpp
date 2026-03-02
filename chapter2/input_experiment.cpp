#include <iostream>
#include <limits>

int main()
{
  const double largest = std::numeric_limits<double>::max();
  std::cout << "Please enter a number up to " << largest << ".\n>";
  double number{};
  std::cin >> number;
  std::cout << number << '\n';

  if (!std::cin.eof() && std::cin.peek()!='\n')
    {
      std::cout << "Unusued input\n";
    }
}
