#include <iostream>

#include "conditional_ostream.h"


int main(int argc, char *argv[]) {
  // Used as a temporary for one streaming expression
  //   This works because the operator<< accepts a const-reference
  //   as the left-hand argument, and the compiler will provide
  //   lifetime extension for the ConditionalOStream temporary.
  ConditionalOStream(&std::cout       ) << "Stream to std::cout pointer\n";
  ConditionalOStream( std::cout       ) << "Stream to std::cout reference\n";
  ConditionalOStream(&std::cout, true ) << "Stream to std::cout pointer, true\n";
  ConditionalOStream( std::cout, true ) << "Stream to std::cout reference, true\n";
  ConditionalOStream(&std::cout, false) << "Stream to std::cout pointer, false\n";
  ConditionalOStream( std::cout, false) << "Stream to std::cout reference, false\n";
  return 0;
}
