#include <iostream>

#include "conditional_ostream.h"


struct Foo {};

std::ostream &operator<<(std::ostream &os, Foo const &) {
  std::cout << "Putting Foo into the ostream!\n";
  return os << "This is a Foo in the ostream!\n";
}


int main() {
  ConditionalOStream on  { std::cout, true };
  ConditionalOStream off { std::cout, false };

  Foo f {};

  on  << f << std::hex << std::endl;  // Streams
  off << f << std::hex << std::endl;  // Doesn't

  (on || off) << f << std::hex << std::endl;  // Streams
  (on && off) << f << std::hex << std::endl;  // Doesn't

  on  << &f << std::hex << std::endl;  // Streams
  off << &f << std::hex << std::endl;  // Doesn't

  return 0;
}
