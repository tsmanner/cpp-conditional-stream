#include <iostream>
#include <fstream>

#include "conditional_ostream.h"
#include "profile.h"

int main() {
  auto stream = std::ofstream("/dev/null", std::ios::out);
  time_streaming(stream);
  return 0;
}
