#include <iostream>

#include "cstream.h"


struct Foo {};

std::ostream &operator<<(std::ostream &os, Foo const &) {
  std::cout << "Putting Foo into the ostream!\n";
  return os << "This is a Foo in the ostream!\n";
}


int main() {
  ConditionalStream onStream { std::cout, true };
  ConditionalStream offStream { std::cout, false };

  Foo f {};

  onStream << f << std::hex << std::endl;
  offStream << f << std::hex << std::endl;

  onStream << &f << std::hex << std::endl;
  offStream << &f << std::hex << std::endl;

  return 0;
}
