#include <iostream>
#include <fstream>

#include "conditional_ostream.h"
#include "profile.h"

int main() {
  auto stream = std::ofstream("ofstream.cpp.txt", std::ios::trunc);
  time_streaming(stream);
  return 0;
}
