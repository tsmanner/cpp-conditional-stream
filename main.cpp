#include <iostream>

#include "conditional_ostream.h"


struct Foo {};

std::ostream &operator<<(std::ostream &os, Foo const &) {
  std::cout << "Putting Foo into the ostream!\n";
  return os << "This is a Foo in the ostream!\n";
}


struct Bar {};

std::ostream &operator<<(std::ostream &os, Bar &) {
  std::cout << "Putting Bar into the ostream!\n";
  return os << "This is a Bar in the ostream!\n";
}


ConditionalOStream s() {
  return ConditionalOStream { std::cout };
}


int main() {
  ConditionalOStream on  { std::cout };
  ConditionalOStream off {};


  Foo f {};
  Bar b {};

  ConditionalOStream( std::cout)        << f << b << std::hex << std::endl;  // Streams
  ConditionalOStream(&std::cout)        << f << b << std::hex << std::endl;  // Streams
  ConditionalOStream( std::cout, true)  << f << b << std::hex << std::endl;  // Streams
  ConditionalOStream(&std::cout, true)  << f << b << std::hex << std::endl;  // Streams
  ConditionalOStream( std::cout, false) << f << b << std::hex << std::endl;  // Doesn't
  ConditionalOStream(&std::cout, false) << f << b << std::hex << std::endl;  // Doesn't
  s()                                   << f << b << std::hex << std::endl;  // Streams
  on                                    << f << b << std::hex << std::endl;  // Streams
  off                                   << f << b << std::hex << std::endl;  // Doesn't

  on  << &f << '\n';  // Streams
  off << &f << '\n';  // Doesn't

  return 0;
}
