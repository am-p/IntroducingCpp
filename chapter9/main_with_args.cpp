#include <iostream>
#include <string>
#include <string_view>

// void show_characters_before(const std::string& value, char character) {
//   auto position = value.find(character);
//   if(position != std::string::npos){
//     std::string partial = value.substr(0, position);
//     std::cout << "Before " << character << ": " << partial<< '\n';
//   }
//   else {
//     std::cout << character << " not found\n";
//   }
// }

// acá lo distinto es que estamos usando una view
void show_characters_before(const std::string_view value, char character) {
  auto position = value.find(character);
  if(position != std::string::npos){
    std::string_view partial = value.substr(0, position);
    std::cout << "Before " << character << ": " << partial<< '\n';
  }
  else {
    std::cout << character << " not found\n";
  }
}

int main(int argc, char *argv[]){
  for(int i = 0; i < argc;  ++i){
    std::cout << "Argument " << argv[i] << '\n';
    show_characters_before(argv[i], '/');
    show_characters_before(argv[i], '\\');//<--- need another backslash as '\n' to indicate that n is a special character
  }
}
