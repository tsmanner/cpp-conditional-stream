#include <iostream>
#include <sstream>

#include "conditional_ostream.h"
#include "profile.h"

int main() {
  std::ostringstream stream;
  time_streaming(stream);
  return 0;
}
