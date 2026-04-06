#include <iostream>

#include "events.h"

int main(){
  Event event{FixedFine{10.0}};
  if(std::holds_alternative<FixedFine>(event)){
    std::cout << "A fine\n";
  }
}
