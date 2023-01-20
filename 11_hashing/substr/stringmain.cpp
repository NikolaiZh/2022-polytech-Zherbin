
#include "string.h"
#include <iostream>

int main() {
  String foo = "one";
  String bar = foo + " two";
  std::cout << bar << '\n' << bar.get_length();
  return 0;
}
