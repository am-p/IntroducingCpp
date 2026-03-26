#include <iostream>

int main(){
  
  int value = 101; 
  int* pointer_to_value = &value; 
  int& reference_to_value = value;

  std::cout << "value " << value
	    << ", pointer " << *pointer_to_value
	    << ", reference " << reference_to_value << '\n';
}
