#include <iostream>
#include <string>

#include "conditional_ostream.h"


int main(int argc, char *argv[]) {
  // A simple example of long-lived ConditionalOStreams
  // This application has four output mode flags:
  //   -s  silent
  //   -q  quiet
  //   -v  verbose
  // If none are provided then it is "normal"
  // Because it's an example, I'm *not* implementing full argument handling

  ConditionalOStream quiet   { std::cout };
  ConditionalOStream normal  { std::cout };
  ConditionalOStream verbose {};

  if (argc == 2) {
    if (argv[1] == std::string("-s")) {
      quiet   = ConditionalOStream();
      normal  = ConditionalOStream();
      verbose = ConditionalOStream();
    }
    else if (argv[1] == std::string("-q")) {
      quiet   = ConditionalOStream(std::cout);
      normal  = ConditionalOStream();
      verbose = ConditionalOStream();
    }
    else if (argv[1] == std::string("-v")) {
      quiet   = ConditionalOStream(std::cout);
      normal  = ConditionalOStream(std::cout);
      verbose = ConditionalOStream(std::cout);
    }
  }

  quiet << "Welcome to example.out!\n";
  if (argc == 2) {
    normal << "  One argument was provided: '" << argv[1] << "'\n";
  }
  else {
    normal << "  No arguments were provided\n";
  }
  verbose << "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\n";

  return 0;
}
