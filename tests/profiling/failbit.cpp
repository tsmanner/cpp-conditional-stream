#include <iostream>
#include <fstream>

#include "conditional_ostream.h"
#include "profile.h"

int main() {
  auto stream = std::ofstream();
  stream.setstate(std::ios::failbit);
  time_streaming(stream);
  return 0;
}
